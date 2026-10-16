
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int startTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
    int isCompleted;
};

struct Process p[MAX];
int n = 0;

// Function declarations
void inputProcesses();
void displayProcesses();
void calculateFCFS();
void displayGanttChart();
void displayStatistics();
void searchProcess();
void sortByArrivalTime();
void resetProcesses();

void inputProcesses() {
    int i;

    printf("\n========================================\n");
    printf("          ENTER PROCESS DETAILS\n");
    printf("========================================\n");

    printf("Enter number of processes (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of processes!\n");
        n = 0;
        return;
    }

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("\nProcess P%d\n", p[i].pid);

        printf("Enter Arrival Time: ");
        if (scanf("%d", &p[i].arrivalTime) != 1 ||
            p[i].arrivalTime < 0) {
            printf("Invalid arrival time!\n");
            n = 0;
            return;
        }

        printf("Enter Burst Time: ");
        if (scanf("%d", &p[i].burstTime) != 1 ||
            p[i].burstTime <= 0) {
            printf("Invalid burst time!\n");
            n = 0;
            return;
        }

        p[i].isCompleted = 0;
    }

    printf("\nProcess details saved successfully!\n");
}

void displayProcesses() {
    int i;

    if (n == 0) {
        printf("\nPlease enter process details first.\n");
        return;
    }

    printf("\n========================================\n");
    printf("             PROCESS DETAILS\n");
    printf("========================================\n");
    printf("%-10s %-15s %-12s\n",
           "Process", "Arrival Time", "Burst Time");

    for (i = 0; i < n; i++) {
        printf("%-10d %-15d %-12d\n",
               p[i].pid,
               p[i].arrivalTime,
               p[i].burstTime);
    }
}

void sortByArrivalTime() {
    int i, j;
    struct Process temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].arrivalTime > p[j + 1].arrivalTime) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void calculateFCFS() {
    int i, currentTime = 0;

    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;
    float totalBurstTime = 0;

    if (n == 0) {
        printf("\nPlease enter process details first.\n");
        return;
    }

    sortByArrivalTime();

    printf("\n========================================\n");
    printf("       FCFS SCHEDULING SIMULATION\n");
    printf("========================================\n");

    for (i = 0; i < n; i++) {
        if (currentTime < p[i].arrivalTime) {
            currentTime = p[i].arrivalTime;
        }

        p[i].startTime = currentTime;

        p[i].completionTime =
            p[i].startTime + p[i].burstTime;

        p[i].turnaroundTime =
            p[i].completionTime - p[i].arrivalTime;

        p[i].waitingTime =
            p[i].turnaroundTime - p[i].burstTime;

        p[i].responseTime =
            p[i].startTime - p[i].arrivalTime;

        currentTime = p[i].completionTime;

        totalWaitingTime += p[i].waitingTime;
        totalTurnaroundTime += p[i].turnaroundTime;
        totalBurstTime += p[i].burstTime;

        p[i].isCompleted = 1;
    }

    printf("\nScheduling completed successfully!\n");

    printf("\n---------------------------------------------------------------\n");
    printf("%-6s %-5s %-5s %-5s %-5s %-5s %-5s\n",
           "PID", "AT", "BT", "ST", "CT", "TAT", "WT");
    printf("---------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("P%-5d %-5d %-5d %-5d %-5d %-5d %-5d\n",
               p[i].pid,
               p[i].arrivalTime,
               p[i].burstTime,
               p[i].startTime,
               p[i].completionTime,
               p[i].turnaroundTime,
               p[i].waitingTime);
    }

    printf("---------------------------------------------------------------\n");

    printf("\nAverage Waiting Time     : %.2f units",
           totalWaitingTime / n);

    printf("\nAverage Turnaround Time  : %.2f units",
           totalTurnaroundTime / n);

    printf("\nAverage Response Time    : %.2f units",
           totalWaitingTime / n);

    printf("\nCPU Utilization          : %.2f%%",
           (totalBurstTime / currentTime) * 100.0);

    printf("\nThroughput               : %.2f processes/unit\n",
           (float)n / currentTime);

    displayGanttChart();
}

void displayGanttChart() {
    int i;

    if (n == 0) {
        printf("\nNo process data available.\n");
        return;
    }

    printf("\n\n========================================\n");
    printf("               GANTT CHART\n");
    printf("========================================\n");

    printf("%d", p[0].startTime);

    for (i = 0; i < n; i++) {
        printf(" |--- P%d ---| %d",
               p[i].pid,
               p[i].completionTime);
    }

    printf("\n");
}

void displayStatistics() {
    int i;
    float totalWT = 0, totalTAT = 0;
    float totalBT = 0;
    int endTime = 0;

    if (n == 0 || !p[0].isCompleted) {
        printf("\nRun the scheduling simulation first.\n");
        return;
    }

    printf("\n========================================\n");
    printf("          PERFORMANCE STATISTICS\n");
    printf("========================================\n");

    for (i = 0; i < n; i++) {
        totalWT += p[i].waitingTime;
        totalTAT += p[i].turnaroundTime;
        totalBT += p[i].burstTime;

        if (p[i].completionTime > endTime) {
            endTime = p[i].completionTime;
        }
    }

    printf("Total Processes         : %d\n", n);
    printf("Total CPU Burst Time     : %.0f units\n", totalBT);
    printf("Total Execution Duration : %d units\n", endTime);
    printf("Average Waiting Time     : %.2f units\n", totalWT / n);
    printf("Average Turnaround Time  : %.2f units\n", totalTAT / n);
    printf("Average Response Time    : %.2f units\n", totalWT / n);

    if (endTime > 0) {
        printf("CPU Utilization          : %.2f%%\n",
               (totalBT / endTime) * 100.0);
        printf("Throughput               : %.2f processes/unit\n",
               (float)n / endTime);
    }
}

void searchProcess() {
    int key, i, found = 0;

    if (n == 0) {
        printf("\nPlease enter process details first.\n");
        return;
    }

    printf("\nEnter Process ID to search (e.g. 2 for P2): ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (p[i].pid == key) {
            printf("\nProcess Found!\n");
            printf("Process ID       : P%d\n", p[i].pid);
            printf("Arrival Time     : %d\n", p[i].arrivalTime);
            printf("Burst Time       : %d\n", p[i].burstTime);

            if (p[i].isCompleted) {
                printf("Start Time       : %d\n", p[i].startTime);
                printf("Completion Time  : %d\n", p[i].completionTime);
                printf("Turnaround Time  : %d\n", p[i].turnaroundTime);
                printf("Waiting Time     : %d\n", p[i].waitingTime);
            } else {
                printf("Run simulation to calculate scheduling times.\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Process P%d not found.\n", key);
    }
}

void resetProcesses() {
    n = 0;
    printf("\nAll process data has been reset.\n");
}

int main() {
    int choice;

    do {
        printf("\n\n");
        printf("============================================\n");
        printf("       CPU SCHEDULING MANAGEMENT SYSTEM\n");
        printf("       FIRST COME FIRST SERVED (FCFS)\n");
        printf("============================================\n");

        printf("1. Enter Process Details\n");
        printf("2. Display Process Details\n");
        printf("3. Run FCFS Scheduling\n");
        printf("4. Display Gantt Chart\n");
        printf("5. Display Performance Statistics\n");
        printf("6. Search Process\n");
        printf("7. Reset Process Data\n");
        printf("8. Exit\n");

        printf("--------------------------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please restart the program.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                inputProcesses();
                break;

            case 2:
                displayProcesses();
                break;

            case 3:
                calculateFCFS();
                break;

            case 4:
                displayGanttChart();
                break;

            case 5:
                displayStatistics();
                break;

            case 6:
                searchProcess();
                break;

            case 7:
                resetProcesses();
                break;

            case 8:
                printf("\nThank you for using the FCFS Simulator!\n");
                break;

            default:
                printf("\nInvalid choice! Please select 1-8.\n");
        }

    } while (choice != 8);

    return 0;
}
