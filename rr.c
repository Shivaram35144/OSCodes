#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void RoundRobin(struct process *p, int n, int quantum)
{
    int current_time = 0;
    int remaining_time[n];
    for (int i = 0; i < n; i++)
        remaining_time[i] = p[i].burst_time;

    while (1)
    {
        int done = 1;
        for (int i = 0; i < n; i++)
        {
            if (remaining_time[i] > 0)
            {
                done = 0;
                if (remaining_time[i] > quantum)
                {
                    current_time += quantum;
                    remaining_time[i] -= quantum;
                }
                else
                {
                    current_time = current_time + remaining_time[i];
                    p[i].completion_time = current_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }

    for (int i = 0; i < n; i++)
    {
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
}

void display(struct process *p, int n)
{
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
}

int main()
{
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the details of process %d\n", i + 1);
        printf("Enter process ID: ");
        scanf("%d", &p[i].pid);
        printf("Enter arrival time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Enter burst time: ");
        scanf("%d", &p[i].burst_time);
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    RoundRobin(p, n, quantum);
    display(p, n);
	return 0;}