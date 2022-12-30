#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;
} process;

int totalBurstTime(process *A, int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += A[i].burst_time;
    return total;
}

void rr(process *A, int quantum, int n) {
    int total, *processRunning, flag, hold = 0, k = 0;

    total = totalBurstTime(A, n);

    processRunning = malloc(total * sizeof(int));

    while(1) {
        flag = 1;
        for (int i = 0; i < n; i++) {
            if (A[i].arrival_time <= hold) {
                if (A[i].arrival_time <= quantum) {
                    if (A[i].burst_time > 0) {
                        flag = 0;
                        if (A[i].burst_time > quantum) {
                            hold += quantum;
                            A[i].burst_time -= quantum;
                            A[i].arrival_time += quantum;
                            for (;k < hold; k++)
                                processRunning[k] = A[i].pid;

                        } else {
                            hold += A[i].burst_time;
                            A[i].burst_time = 0;
                            for (;k < hold; k++)
                                processRunning[k] = A[i].pid;
                        }
                    }
                } else if (A[i].arrival_time > quantum) {
                    for (int j = 0; j < n; j++) {
                        if (A[j].arrival_time < A[i].arrival_time) {
                            if (A[j].burst_time > 0) {
                                flag = 0;
                                if (A[j].burst_time > quantum) {
                                    hold += quantum;
                                    A[j].burst_time -= quantum;
                                    A[j].arrival_time += quantum;
                                    for (;k < hold; k++)
                                        processRunning[k] = A[j].pid;
                                } else {
                                    hold += A[j].burst_time;
                                    A[j].burst_time = 0;
                                    for (;k < hold; k++)
                                        processRunning[k] = A[j].pid;
                                }
                            }
                        }
                    }

                    if (A[i].burst_time > 0) {
                        flag = 0;
                        if (A[i].burst_time > quantum) {
                            hold += quantum;
                            A[i].burst_time -= quantum;
                            A[i].arrival_time += quantum;
                            for (;k < hold; k++)
                                processRunning[k] = A[i].pid;
                        } else {
                            hold += A[i].burst_time;
                            A[i].burst_time = 0;
                            for (;k < hold; k++)
                                processRunning[k] = A[i].pid;
                        }
                    }
                } else if (A[i].arrival_time > hold) {
                    hold++;
                    i--;
                }
            }
        }
        if (flag)
            break;
    }

    for (int i = 0; i < total; i++)
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

    rr(arr, quantum, n);

	return 0; /* DO NOT EDIT THIS LINE */
}
