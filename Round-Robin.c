/*
*/

/*
Full Form-

bt = Burst Time
wt = Waiting Time
tat = Turnaround Time
qt = Time Quantum
wtavg = Average Waiting Time
tatavg = Average Turnaround Time

*/

#include<stdio.h>

int main()
{
    int n, i, qt, count = 0, temp, sq = 0, bt[10], wt[10], tat[10], rem_bt[10];
    float wtavg = 0, tatavg = 0;

    printf("Enter The Number of Process: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter Burst Time For Process P%d -- ", i);
        scanf("%d", &bt[i]);

        rem_bt[i] = bt[i];
    }

    printf("Enter Quantum Time: ");
    scanf("%d", &qt);

    while(1)
    {
        for(i = 1, count = 0; i <= n; i++)
        {
            temp = qt;

            if(rem_bt[i] == 0)
            {
                count++;
                continue;
            }

            if(rem_bt[i] > qt)
                rem_bt[i] = rem_bt[i] - qt;

            else
            {
                if(rem_bt[i] >= 0)
                {
                    temp = rem_bt[i];
                    rem_bt[i] = 0;
                }
            }

            sq = sq + temp;
            tat[i] = sq;
        }

        if(n == count)
            break;
    }

    printf("\n\t Process\t Burst Time\t Waiting Time\t Turnaround Time\n");

    for(i = 1; i <= n; i++)
    {
        wt[i] = tat[i] - bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];

        printf("\t %d \t\t %d \t\t %d \t\t %d\n", i, bt[i], wt[i], tat[i]);
    }

    wtavg = wtavg / n;
    tatavg = tatavg / n;

    printf("\nThe Average Turnaround Time is -- %f\n", tatavg);
    printf("The Average Waiting Time is -- %f\n", wtavg);

    return 0;
}


/*

Sample Input/Output:

Enter The Number of Process: 3
Enter Burst Time For Process P1 -- 24
Enter Burst Time For Process P2 -- 3
Enter Burst Time For Process P3 -- 3
Enter Quantum Time: 4

         Process         Burst Time      Waiting Time    Turnaround Time
         1               24              6               30
         2               3               4               7
         3               3               7               10

The Average Turnaround Time is -- 15.666667
The Average Waiting Time is -- 5.666667

*/