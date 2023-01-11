#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;
    /* added by @akorkos */
    int remaining_time;
} process;


void swap(process *x, process *y) {
    process temp = *x;
    *x= *y;
    *y = temp;
}

void sortOnArrivalTime(process *A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j].arrival_time > A[j + 1].arrival_time)
                swap(&A[j], &A[j + 1]);
        }
    }
}

int totalBurstTime(process *A, int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += A[i].burst_time;
    return total;
}

int minBurstTime(process *A, int n, int time) {
    int low = 9999, lowIndex;
    for (int i = 0; i < n; i++) {
        if (A[i].arrival_time <= time && A[i].burst_time < low && A[i].burst_time > 0) {
            low = A[i].burst_time;
            lowIndex = i;
        }
    }
    return lowIndex;
}

void srtf(process *A, int n) {
    int total, *processRunning, i = 0, time = 0, processToRun, cp;

    for (int j = 0; j < n; j++)
        A[j].remaining_time = A[j].burst_time;

    sortOnArrivalTime(A, n);

    total = totalBurstTime(A, n);
    cp = total;

    processRunning = malloc(total * sizeof(int));

    while (total) {
        processToRun = minBurstTime(A, n, time);
        processRunning[i] = processToRun + 1;
        A[processToRun].remaining_time--;
        A[processToRun].burst_time--;
        i++;
        time++;
        total--;
    }

    for (i = 0; i < cp; i++)
        printf("%d\r\n", processRunning[i]);
}

int main() {

	/* read in data - DO NOT EDIT (START) */
	int n;
	int quantum;
	scanf("%d", &n);
	scanf("%d", &quantum);
	process *arr;
	arr = malloc(n * sizeof(process));
	for (int i = 0; i < n ; ++i) {
		scanf("%d", &arr[i].pid);
		scanf("%d", &arr[i].arrival_time);
		scanf("%d", &arr[i].burst_time);
	}
	/* read in data - DO NOT EDIT (END) */

    srtf(arr, n);

	return 0; /* DO NOT EDIT THIS LINE */
}
