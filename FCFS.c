#include <stdio.h>
#include "Gantt_Chart.h"

int main(){
    int n;
    printf("Enter number of processes : ");
    scanf("%d", &n);


    int burst[n];
    printf("Enter %d space seperated burst times for each process : ", n);

    for(int i = 0; i < n; i++){
        scanf("%d", (burst+i));
    }

    chart ch;
    ch.process_num = n;

    // printf("Initialized Number of processes to chart .....\n");
    
    chart_row records[n];

    // printf("All placeholders for records created .....\n");

    records[0].process = 1;
    records[0].arrivalTime = 0;
    records[0].burstTime = burst[0];
    records[0].waitingTime = 0;
    records[0].turnAroundTime = records[0].burstTime + records[0].waitingTime;

    for(int i = 1; i < n; i++){
        records[i].process = i+1;
        records[i].arrivalTime = 0;
        records[i].burstTime = burst[i];
        records[i].waitingTime = records[i-1].turnAroundTime;
        records[i].turnAroundTime = records[i].burstTime + records[i].waitingTime;
    }

    // printf("Assigned all values to chart .....\n");

    ch.rows = records;

    // printf("Initialized all records to chart rows .....\n");

    // printf("Printing begins .....\n");

    printChart(ch);

    return 0;
}