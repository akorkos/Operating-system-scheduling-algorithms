#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;
    /* added by @akorkos */
    int start_time;
    int waiting_time;
} process;

void fcfs(process *A, int n){
    int *processRunning, totalBurstTime = A[0].burst_time;
    A[0].waiting_time = 0;
    A[0].start_time = 0;

    for (int i = 1; i < n; i++) {
        A[i].start_time = A[i - 1].arrival_time + A[i - 1].burst_time + A[i - 1].waiting_time;
        A[i].waiting_time = A[i].start_time - A[i].arrival_time;
        totalBurstTime += A[i].burst_time;
    }

    processRunning = malloc(totalBurstTime * sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = A[i].start_time; j <  A[i].start_time + A[i].burst_time; j++)
            processRunning[j] = A[i].pid;
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

    fcfs(arr, n);

	return 0; /* DO NOT EDIT THIS LINE */
}
