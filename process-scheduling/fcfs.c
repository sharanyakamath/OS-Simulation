#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

struct process
{
	int id,at,bt,wt,tat;
};

struct process p[N];
double avg_wt = 0.0, avg_tat = 0.0;
int n, burst[N];

void compute()
{
	int time=-1, tot=n, mini=1e9, pos=-1, curr=-1;

	while(tot)
	{
		time++;
		mini = 1e9;
		pos = -1;

		for(int i=0; i<n; i++)
			if(mini > p[i].at && burst[i] && time>=p[i].at)
			{
				pos = i;
				mini = burst[i];
			}

		if(curr != -1)
			pos = curr;

		if(pos == -1)
			continue;

		curr = pos;

		burst[pos]--;
		for(int i=0; i<n; i++)
			if(i!=pos && burst[i] && time>=p[i].at)
				p[i].wt++;

		if(burst[pos] == 0)
		{
			tot--;
			curr = -1;
			p[pos].tat = time - p[pos].at +1;

			avg_tat += p[pos].tat;
			avg_wt += p[pos].wt;
		}
	}
}

int main()
{
	printf("Number of processes : ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		printf("Arrival timee and Burst timee of the process%d: ",i+1);
		scanf("%d%d", &p[i].at,&p[i].bt);
		p[i].id = i+1;
		burst[i] = p[i].bt;
	}

	compute();

	printf("\n");
	printf("Process\t\tArrival timee\tBurst timee\tWaiting timee\tTurn around timee\n");
	for(int i=0; i<n; i++)
	{
		printf("%d\t\t%d\t\t", p[i].id, p[i].at);
		printf("%d\t\t%d\t\t%d\n", p[i].bt, p[i].wt, p[i].tat);
	}

	avg_tat /= 1.0*n;
	avg_wt /= 1.0*n;

	printf("\nAverage waiting timee     : %f", avg_wt);
	printf("\nAverage turn around timee : %f\n", avg_tat);
}

