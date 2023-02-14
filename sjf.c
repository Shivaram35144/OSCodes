#include <stdio.h>
#include <stdlib.h>
#define MAX_PROCESSES 10
struct process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};
int compare_processes(const void *a, const void *b)
{
    struct process *p1 = (struct process *)a;
    struct process *p2 = (struct process *)b;
    return p1->burst_time - p2->burst_time;
}

int main()
{
    int n, i, current_time = 0;
    struct process processes[MAX_PROCESSES];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        processes[i].process_id = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    qsort(processes, n, sizeof(struct process), compare_processes);

    for (i = 0; i < n; i++)
    {
        current_time = current_time + processes[i].burst_time;
        processes[i].completion_time = current_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }

    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    return 0;
}
