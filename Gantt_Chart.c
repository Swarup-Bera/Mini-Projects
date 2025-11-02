#include <stdio.h>
#include "Gantt_Chart.h"


int countDigit(int num){
    int count = 0;
    if(num == 0) return 1;
    while(num > 0){
        num = num/10;
        count = count+1;
    }
    return count;
}

void printSpace(int num){
    for(int i = 0; i < num; i++) printf(" ");
}

void sortBurst(chart ch){
    int n = ch.process_num;

    for(int i = 0; i< n; i++){
        for(int j = 1; j < n; j++){
            if(ch.rows[j].burstTime < ch.rows[j-1].burstTime){
                chart_row temp = ch.rows[j];
                ch.rows[j] = ch.rows[j-1];
                ch.rows[j-1] = temp;
            }
        }
    }
}

void sortPriority(chart ch){
    int n = ch.process_num;

    for(int i = 0; i< n; i++){
        for(int j = 1; j < n; j++){
            if(ch.rows[j].priority < ch.rows[j-1].priority){
                chart_row temp = ch.rows[j];
                ch.rows[j] = ch.rows[j-1];
                ch.rows[j-1] = temp;
            }
        }
    }
}

void printChart(chart c){
    int processLen = 7;
    int arrivalLen = 12;
    int waitingLen = 12;
    int burstlen = 10;
    int turnLen = 15;

    int num = c.process_num;
    printf("\n Process | Arrival Time | Burst Time | Waiting Time | TurnAround Time \n");
    printf("_____________________________________________________________________\n");
    for(int i = 0; i < num; i++){

        int dataLen = countDigit(c.rows[i].process);
        int before = (processLen + 2 - dataLen)/2;
        printSpace(before);
        int after =processLen + 2 - (before + dataLen) ;
        printf("%d", c.rows[i].process);
        printSpace(after);
        printf("|");

        dataLen = countDigit(c.rows[i].arrivalTime);
        before = (arrivalLen + 2 - dataLen)/2;
        printSpace(before);
        after = arrivalLen + 2 - (before + dataLen) ;
        printf("%d", c.rows[i].arrivalTime);
        printSpace(after);
        printf("|");

        dataLen = countDigit(c.rows[i].burstTime);
        before = (burstlen + 2 - dataLen)/2;
        printSpace(before);
        after = burstlen + 2 - (before + dataLen) ;
        printf("%d", c.rows[i].burstTime);
        printSpace(after);
        printf("|");

        dataLen = countDigit(c.rows[i].waitingTime);
        before = (waitingLen + 2 - dataLen)/2;
        printSpace(before);
        after = waitingLen + 2 - (before + dataLen) ;
        printf("%d", c.rows[i].waitingTime);
        printSpace(after);
        printf("|");

        dataLen = countDigit(c.rows[i].turnAroundTime);
        before = (turnLen + 2 - dataLen)/2;
        printSpace(before);
        after = turnLen + 2 - (before + dataLen) ;
        printf("%d", c.rows[i].turnAroundTime);
        printSpace(after);
        

        printf("\n");
    }

    printf("_____________________________________________________________________\n");
}

void printPriorityChart(chart c){
     int processLen = 7;
    int arrivalLen = 12;
    int waitingLen = 12;
    int burstlen = 10;
    int turnLen = 15;
    int priorLen = 8;

    int num = c.process_num;
    printf("\n Process | Arrival Time | Burst Time | Priority | Waiting Time | TurnAround Time \n");
    printf("___________________________________________________________________________________\n");
    for(int i = 0; i < num; i++){

        int dataLen = countDigit(c.rows[i].process);
        int before = (processLen + 2 - dataLen)/2;
        printSpace(before);
        int after =processLen + 2 - (before + dataLen) ;
        printf("%d", c.rows[i].process);
        printSpace(after);
        printf("|");

        dataLen = countDigit(c.rows[i].arrivalTime);
        before = (arrivalLen + 2 - dataLen)/2;
        printSpace(before);
        after = arrivalLen + 2 - (before + dataLen) ;
        printf("%d", c.rows[i].arrivalTime);
        printSpace(after);
        printf("|");

        dataLen = countDigit(c.rows[i].burstTime);
        before = (burstlen + 2 - dataLen)/2;
        printSpace(before);
        after = burstlen + 2 - (before + dataLen) ;
        printf("%d", c.rows[i].burstTime);
        printSpace(after);
        printf("|");

        dataLen = countDigit(c.rows[i].priority);
        before = (priorLen + 2 - dataLen)/2;
        printSpace(before);
        after = priorLen + 2 - (before + dataLen) ;
        printf("%d", c.rows[i].priority);
        printSpace(after);
        printf("|");

        dataLen = countDigit(c.rows[i].waitingTime);
        before = (waitingLen + 2 - dataLen)/2;
        printSpace(before);
        after = waitingLen + 2 - (before + dataLen) ;
        printf("%d", c.rows[i].waitingTime);
        printSpace(after);
        printf("|");

        dataLen = countDigit(c.rows[i].turnAroundTime);
        before = (turnLen + 2 - dataLen)/2;
        printSpace(before);
        after = turnLen + 2 - (before + dataLen) ;
        printf("%d", c.rows[i].turnAroundTime);
        printSpace(after);
        

        printf("\n");
    }
}