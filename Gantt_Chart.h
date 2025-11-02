#ifndef GANTT_CHART_H
#define GANTT_CHART_H

typedef struct chart_row{

    int process;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
    int priority;

}chart_row;

typedef struct chart{
    int process_num;
    chart_row *rows;

}chart;

void printChart(chart c);

void printPriorityChart(chart ch);

void sortBurst(chart ch);

void sortPriority(chart ch);

#endif