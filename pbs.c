#include <stdio.h>
#include <stdlib.h>
#define MAX_PROCESSES 10
struct process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};
int compare_processes(const void *a, const void *b)
{
    struct process *p1 = (struct process *)a;
    struct process *p2 = (struct process *)b;
    return p1->priority - p2->priority;
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
        printf("Enter arrival time, burst time and priority for process %d: ", i + 1);
        scanf("%d%d%d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
    }
    qsort(processes, n, sizeof(struct process), compare_processes);
    for (i = 0; i < n; i++)
    {
        current_time = current_time + processes[i].burst_time;
        processes[i].completion_time = current_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
    printf("\nProcess ID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    return 0;
}
