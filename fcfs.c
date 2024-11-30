#include <stdio.h>

struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

// Function to calculate waiting time for each process
void calculateWaitingTime(struct Process processes[], int n) {
    processes[0].waitingTime = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i-1].waitingTime + processes[i-1].burstTime;
    }
}

// Function to calculate turnaround time for each process
void calculateTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}

// Function to calculate average time
void calculateAverageTime(struct Process processes[], int n) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;

        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime,
               processes[i].waitingTime, processes[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time = %.2f", (float)totalWaitingTime / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)totalTurnaroundTime / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burstTime);
    }

    calculateAverageTime(processes, n);

    return 0;
}
