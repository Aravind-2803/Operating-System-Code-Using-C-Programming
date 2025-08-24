#include <stdio.h>

struct Process
{
	int id;
	int arrivalTime;
	int burstTime;
	int priority;
	int waitingTime;
	int turnAroundTime;
	int responseTime;
	int completionTime;
};
void sortByPriority(struct Process proc[], int n)
{
	for (int i = 0; i < n - 1; i++)
 	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (proc[j].priority > proc[j + 1].priority || (proc[j].priority == proc[j + 1].priority &&proc[j].arrivalTime > proc[j + 1].arrivalTime))
			{
				struct Process temp = proc[j];
				proc[j] = proc[j + 1];
				proc[j + 1] = temp;
			}
		}
	}
}

void calculateTimes(struct Process proc[], int n)
{
	int currentTime = 0;
	for (int i = 0; i < n; i++)
	{
		if (currentTime < proc[i].arrivalTime)
		{
			currentTime = proc[i].arrivalTime;
		}
		proc[i].waitingTime = currentTime - proc[i].arrivalTime;
		proc[i].responseTime = proc[i].waitingTime;
		currentTime += proc[i].burstTime;
		proc[i].completionTime = currentTime;
		proc[i].turnAroundTime = proc[i].completionTime -
		proc[i].arrivalTime;
	}
}


void printProcesses(struct Process proc[], int n)
{
	printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaitingTime\tTurnaround Time\tResponse Time\n");
	for (int i = 0; i < n; i++)
	{
	printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", proc[i].id,proc[i].arrivalTime, proc[i].burstTime, proc[i].priority,proc[i].waitingTime, proc[i].turnAroundTime, proc[i].responseTime);
	}
}

void calculateAverages(struct Process proc[], int n)
{
	float totalWaitingTime = 0, totalTurnAroundTime = 0,totalResponseTime = 0;
	for (int i = 0; i < n; i++)
	{
		totalWaitingTime += proc[i].waitingTime;
		totalTurnAroundTime += proc[i].turnAroundTime;
		totalResponseTime += proc[i].responseTime;
	}
	printf("\nAverage Waiting Time: %.2f", totalWaitingTime / n);
	printf("\nAverage Turnaround Time: %.2f", totalTurnAroundTime / n);
	printf("\nAverage Response Time: %.2f\n", totalResponseTime / n);
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
		printf("Enter arrival time, burst time, and priority forprocess %d: ", i + 1);
		scanf("%d %d %d", &proc[i].arrivalTime, &proc[i].burstTime,&proc[i].priority);
	}
	sortByPriority(proc, n);
	calculateTimes(proc, n);
	printProcesses(proc, n);
	calculateAverages(proc, n);
	return 0;
}
