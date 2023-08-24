
/*
Full Form-

bt = Burst Time
wt = Waiting Time
tat = Turnaround Time
pri= Priority
wtavg = Average Waiting Time
tatavg = Average Turnaround Time

*/

#include<stdio.h>
int main()
{
    int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    printf("Enter The Number of Processes -- ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        p[i] = i;

        printf("Enter The Burst Time & Priority of Process %d -- ", i);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    for(i = 1; i <= n; i++)
    {
        for(k = i + 1; k <= n; k++)
        {
            if(pri[i] > pri[k])
            {
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;

                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                temp = pri[i];
                pri[i] = pri[k];
                pri[k] =temp;
            }
        }
    }

    wt[1] = wtavg = 0;
    tat[1] = tatavg = bt[1];

    for(i = 2; i <= n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];

        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }

    printf("\n\t Process \t Priority \t Burst Time \t Waiting Time \t Turnaround Time\n");

    for(i = 1; i <= n; i++)
         printf("\n\t P%d \t\t %d \t\t %d \t\t %d \t\t %d", p[i], pri[i], bt[i], wt[i], tat[i]);

    printf("\n\nAverage Waiting Time -- %f\n", wtavg / n);
    printf("Average Turnaround Time -- %f\n", tatavg / n);

    return 0;
}

/*
Sample Input/Output:

Enter The Number of Processes -- 5
Enter The Burst Time & Priority of Process 1 -- 10 3
Enter The Burst Time & Priority of Process 2 -- 1 1
Enter The Burst Time & Priority of Process 3 -- 2 4
Enter The Burst Time & Priority of Process 4 -- 1 5
Enter The Burst Time & Priority of Process 5 -- 5 2

         Process         Priority        Burst Time      Waiting Time    Turnaround 
Time

         P2              1               1               0               1
         P5              2               5               1               6
         P1              3               10              6               16
         P3              4               2               16              18
         P4              5               1               18              19

Average Waiting Time -- 8.200000
Average Turnaround Time -- 12.000000


*/