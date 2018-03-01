#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

struct process
{
	int id,at,bt,wt,tat,rem;
};

int queue[N];
int front = 0, rear = 0;
struct process proc[N];

void push(int id)
{
	queue[rear] = id;
	rear = (rear+1)%N;
}

int pop()
{
	if(front == rear)
		return -1;

	int return_position = queue[front];
	front = (front +1)%N;
	return return_position;
}

int main()
{
	float wait_time_total = 0.0, tat = 0.0;
	int n,time_quantum;
	printf("Number of processes: ");
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		printf("Arrival time and burst time of process%d: ",i+1);
		scanf("%d%d", &proc[i].at, &proc[i].bt);
		proc[i].id = i+1;
		proc[i].rem = proc[i].bt;
	}
	printf("Time quantum: ");
	scanf("%d",&time_quantum);

	int time=0; 
	int processes_left=n;   
	int position=-1; 		
	int local_time=0; 

	for(int j=0; j<n; j++)
		if(proc[j].at == time)
			push(j);

	while(processes_left)
	{
		if(local_time == 0) 
		{
			if(position != -1)
				push(position);

			position = pop();
		}

		for(int i=0; i<n; i++)
		{
			if(proc[i].at > time)
				continue;
			if(i==position)
				continue;
			if(proc[i].rem == 0)
				continue;

			proc[i].wt++;
			proc[i].tat++;
		}

		if(position != -1)
		{
			proc[position].rem--;
			proc[position].tat++;
			
			if(proc[position].rem == 0)
			{
				processes_left--;
				local_time = -1;
				position = -1;
			}
		}
		else
			local_time = -1; 

		time++;
		local_time = (local_time +1)%time_quantum;
		for(int j=0; j<n; j++)
			if(proc[j].at == time)	
				push(j);
	}

	printf("\n");

	printf("Process\t\tArrival Time\tBurst Time\tWaiting time\tTurn around time\n");
	for(int i=0; i<n; i++)
	{
		printf("%d\t\t%d\t\t", proc[i].id, proc[i].at);
		printf("%d\t\t%d\t\t%d\n", proc[i].bt, proc[i].wt, proc[i].tat);

		tat += proc[i].tat;
		wait_time_total += proc[i].wt;
	}

	tat = tat/(1.0*n);
	wait_time_total = wait_time_total/(1.0*n);

	printf("\nAverage waiting time     : %f",wait_time_total);
	printf("\nAverage turn around time : %f\n", tat);
	
}
