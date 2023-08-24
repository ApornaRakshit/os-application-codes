/*
1.Write a c program to simulate the CPU scheduling algorithm First Come First Serve (FCFS)
*/
/*
Full Form-

bt = Burst Time
wt = Waiting Time
tat = Turnaround Time
wtavg = Average Waiting Time
tatavg = Average Turnaround Time

*/

#include<stdio.h>
int main()
{
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;

    printf("Enter The Number Of Processes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    wt[1] = wtavg = 0;
    tat[1] = tatavg = bt[1];

    for(i = 2; i <= n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }

    printf("\n\t Process \t Burst Time \t Waiting Time \t Turnaround Time\n");

    for(i = 1; i <= n; i++)
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]);

    printf("\n\nAverage Waiting Time -- %f\n", wtavg / n);
    printf("Average Turnaround Time -- %f\n", tatavg / n);

    return 0;
}


/*

Sample Input/Output:

Enter The Number Of Processes: 3

Enter Burst Time for Process 1 -- 24

Enter Burst Time for Process 2 -- 3

Enter Burst Time for Process 3 -- 3

         Process         Burst Time      Waiting Time    Turnaround Time

         P1              24              0               24
         P2              3               24              27
         P3              3               27              30

Average Waiting Time -- 17.000000
Average Turnaround Time -- 27.000000

*/