#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;
    /* added by @akorkos */
    int completion_time;
    int waiting_time;
    int turn_around_time;
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

void sortOnBurstTime(process *A, int n) {
    int tmp, low, pos;

    A[0].completion_time = A[0].arrival_time + A[0].burst_time;
    A[0].turn_around_time = A[0].completion_time - A[0].arrival_time;
    A[0].waiting_time = A[0].turn_around_time - A[0].burst_time;

    for (int i = 1; i < n; i++) {
        tmp = A[i - 1].completion_time;
        low = A[i].burst_time;

        for (int j = i; j < n; j++) {
            if (tmp >= A[j].arrival_time && low >= A[j].burst_time) {
                low = A[j].burst_time;
                pos = j;
            }
        }

        A[pos].completion_time = tmp + A[pos].burst_time;
        A[pos].turn_around_time = A[pos].completion_time - A[pos].arrival_time;
        A[pos].waiting_time = A[pos].turn_around_time - A[pos].burst_time;

        swap(&A[pos], &A[i]);
    }
}

void sjf(process *A, int n) {
    int totalBurstTime = 0, *processRunning, k = 0;

    for (int i = 0; i < n; i++)
        totalBurstTime += A[i].burst_time;

    processRunning = malloc(totalBurstTime * sizeof(int));

    sortOnArrivalTime(A, n);
    sortOnBurstTime(A, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <  A[i].burst_time; j++) {
            processRunning[k] = A[i].pid;
            k++;
        }
    }

    for (int i = 0; i < totalBurstTime; i++)
        printf("%d \n", processRunning[i]);
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

    sjf(arr, n);

	return 0; /* DO NOT EDIT THIS LINE */
}
