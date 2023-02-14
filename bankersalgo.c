// Banker's Algorithm
#include <stdio.h>
int main()
{
	

	int n, m, i, j, k;
	scanf("%d%d",&n,&m);
	int alloc[n][m];
	
	printf("Enter Resource Allocation Matrix:\n");
    	for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &alloc[i][j]);
        }}

	int max[n][m];
	
	printf("Enter Maximum Resource Matrix:\n");
    	for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &max[i][j]);
        }}

	int avail[m];
	printf("Enter Available Resource Array:\n");
    	for (int i = 0; i < m; i++){
        scanf("%d", &avail[i]);}

	int done[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		done[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++){
			need[i][j] = max[i][j] - alloc[i][j];
	}}
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (done[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					done[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	
	for(int i=0;i<n;i++)
	{
	if(done[i]==0)
	{
		flag=0;
		printf("Deadlock\n");
		break;
	}
	}
	
	if(flag==1)
	{
	printf("Sequence of execution: ");
	for (i = 0; i < n; i++){
		printf(" P%d ->", ans[i]+1);
	}
	
	}
	

	return (0);

	
}