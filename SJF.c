/*
SJF- Shortest Job First
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
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    printf("Enter The Number of Process: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        p[i] = i;

        printf("Enter Burst Time For Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    for(i = 1; i <= n; i++)
    {
        for(k = i + 1; k <= n; k++)
        {
            if(bt[i] > bt[k])
            {
                // Burst Time Swaping
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                
                // Process No. Swaping
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
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

    printf("\n\t Process \t Burst Time \t Waiting Time \t Turnaround Time\n");

    for(i = 1; i <= n; i++)
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);

    printf("\n\nAverage Waiting Time -- %f\n", wtavg / n);
    printf("Average Turnaround Time -- %f\n", tatavg / n);

    return 0;
}


/*
Sample Input/Output:

Enter The Number of Process: 4
Enter Burst Time For Process 1 -- 6
Enter Burst Time For Process 2 -- 8
Enter Burst Time For Process 3 -- 7
Enter Burst Time For Process 4 -- 3

         Process         Burst Time      Waiting Time    Turnaround Time

         P4              3               0               3
         P1              6               3               9
         P3              7               9               16
         P2              8               16              24

Average Waiting Time -- 7.000000
Average Turnaround Time -- 13.000000

*/