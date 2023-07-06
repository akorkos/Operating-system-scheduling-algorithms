# Operating system scheduling algorithms 101

In this repository, you will find several scheduling algorithms. The metirial, is a part of the course [Operating Systems [NCO-05-04]](https://elearning.auth.gr/course/view.php?id=8119) (2022/23) of the Department of Computer Science at Aristotle University of Thessaloniki.

## Description

Algorithms implemented:

- First Come First Serve / FCFS
- Shortest Job First / SJF (non-preemptive)
- Shortest Remaining Time First / SRTF (preemptive)
- Round-Robin / RR (for any time quantum value)

The input files should be simple text files (alternatively, data can be directly inputted from the keyboard) and should follow the following structure:

- The first line contains an integer indicating the number of processes described below.
- The second line contains an integer indicating the time quantum possibly used by the algorithms. The time quantum is always defined for all the algorithms, but obviously, it will not be used by algorithms in which it doesn't play any role.
- The remaining lines (as many as the integer on the first line of the file) contain three integers representing the ID of the process, its arrival time, and its CPU burst time.

At the end of their execution, the algorithms print in the standard output, on each line, the ID of the process being executed at each time (starting from time 0).
