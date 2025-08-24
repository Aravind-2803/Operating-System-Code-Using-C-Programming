#include <stdio.h>
#include <limits.h>
struct Process
{
 	int id;
	int arrivalTime;
	int burstTime;
	int remainingTime;
	int priority;
	int waitingTime;
	int turnAroundTime;
	int startTime;
	int completionTime;
	int isCompleted;
};

void calculateWaitingAndTurnaroundTimes(struct Process proc[], int n)
{
	for (int i = 0; i < n; i++)
	{
		proc[i].turnAroundTime = proc[i].completionTime -proc[i].arrivalTime;
		proc[i].waitingTime = proc[i].turnAroundTime -proc[i].burstTime;
	}
}

void printProcesses(struct Process proc[], int n)
{
	printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaitingTime\tTurnaround Time\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].id,
		proc[i].arrivalTime, proc[i].burstTime, proc[i].priority,proc[i].waitingTime, proc[i].turnAroundTime);
	}
}

void calculateAverages(struct Process proc[], int n)
{
	float totalWaitingTime = 0, totalTurnAroundTime = 0;
	for (int i = 0; i < n; i++)
	{
		totalWaitingTime += proc[i].waitingTime;
		totalTurnAroundTime += proc[i].turnAroundTime;
	}
	printf("\nAverage Waiting Time: %.2f", totalWaitingTime / n);
	printf("\nAverage Turnaround Time: %.2f\n", totalTurnAroundTime /n);
}

int main()
{
	int n;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	struct Process proc[n];
	for (int i = 0; i < n; i++)
	{
	proc[i].id = i + 1;
	printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
	scanf("%d %d %d", &proc[i].arrivalTime, &proc[i].burstTime,&proc[i].priority);
	proc[i].remainingTime = proc[i].burstTime;
	proc[i].isCompleted = 0;
	}
	int currentTime = 0, completed = 0, prev = -1;
	int minPriority = INT_MAX;
	int idx = -1;
	while (completed != n)
	{
		for (int i = 0; i < n; i++)
		{
			if (proc[i].arrivalTime <= currentTime &&proc[i].isCompleted == 0)
			{
				if (proc[i].priority < minPriority || (proc[i].priority== minPriority && proc[i].remainingTime < proc[idx].remainingTime))
				{
					minPriority = proc[i].priority;
					idx = i;
				}
			}
		}
		if (idx != -1)
		{
			if (prev != idx)
			{
				proc[idx].startTime = currentTime;
			}
			proc[idx].remainingTime--;
			currentTime++;
			if (proc[idx].remainingTime == 0)
			{
				proc[idx].isCompleted = 1;
				proc[idx].completionTime = currentTime;
				completed++;
				minPriority = INT_MAX;
			}
		}		
		else
 		{
			currentTime++;
 		}
		prev = idx;
		idx = -1;
	}
	calculateWaitingAndTurnaroundTimes(proc, n);
	printProcesses(proc, n);
	calculateAverages(proc, n);
	return 0;
}
