#include <stdio.h>
#include "Gantt_Chart.h"

int main(){
    int n;
    printf("Enter number of process : ");
    scanf("%d", &n);

    int burst[n];
    printf("Enter %d space seperated burst time : ", n);
    for(int i = 0; i < n; i++) scanf("%d", (burst+i));
    chart_row records[n];

    chart ch;
    ch.process_num = n;
    ch.rows = records;

    for(int i = 0; i < n; i++){
        ch.rows[i].process = i+1;
        ch.rows[i].arrivalTime = 0;
        ch.rows[i].burstTime = burst[i];
    }

    sortBurst(ch);

    ch.rows[0].waitingTime = 0;
    ch.rows[0].turnAroundTime = ch.rows[0].burstTime;
    for(int i = 1; i < n; i++){
        ch.rows[i].waitingTime = ch.rows[i-1].turnAroundTime;
        ch.rows[i].turnAroundTime = ch.rows[i].burstTime + ch.rows[i].waitingTime;
    }

    printChart(ch);

    return 0;
}