#include<stdio.h>
//FCFS codes
int main(){
	int n;
	printf("Enter how many entries :  ");
	scanf("%d",&n);
	int at[n],pid[n],bt[n],ct[n],tt[n],wt[n];
	int time=0;
	printf("\nEnter PID AT BT %d times\n\n",n);
	for(int i=0;i<n;i++){
		scanf("%d",&pid[i]);
		scanf("%d",&at[i]);
		scanf("%d",&bt[i]);
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(at[j]>at[j+1]){
				int temp=at[j];
				at[j]=at[j+1];
				at[j+1]=temp;
				
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				
				temp=pid[j];
				pid[j]=pid[j+1];
				pid[j+1]=temp;
			}
		}
	}
	for(int i=0;i<n;i++){
		int sum=bt[i];
		ct[0]=bt[0];
		for(int j=0;j<i;j++){
			sum+=bt[j];
		}
		ct[i]=sum;
	}
	for(int i=0;i<n;i++){
		tt[i]=ct[i]-at[i];
	}
	for(int i=0;i<n;i++){
		wt[i]=tt[i]-bt[i];
	}
	printf("\n PID      AT      BT       CT       TT       WT\n");
	for(int i=0;i<n;i++){
	printf("  %d       %d       %d       %d      %d       %d\n",pid[i],at[i],bt[i],ct[i],tt[i],wt[i]);
	}
	
	return 0;
	

}