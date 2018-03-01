#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

struct process
{
	int pid, pri,at,bt, wt,tat;
};

struct process p[N];
double av_wait = 0.0, av_turn = 0.0;
int n, burst[N];

void compute()
{
	int tim=-1, tot=n, mini=1e9, pos=-1;

	while(tot)
	{
		tim++;
		mini = 1e9;
		pos = -1;

		for(int i=0; i<n; i++)
			if(mini > p[i].pri && burst[i] && tim>=p[i].at)
			{
				pos = i;
				mini = p[i].pri;
			}

		if(pos == -1)
			continue;

		burst[pos]--;
		for(int i=0; i<n; i++)
			if(i!=pos && burst[i] && tim>=p[i].at)
				p[i].wt++;

		if(burst[pos] == 0)
		{
			tot--;
			p[pos].tat = tim - p[pos].at +1;

			av_turn += p[pos].tat;
			av_wait += p[pos].wt;
		}
	}
}

int main()
{
	printf("Number of processes : ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		printf("Arrival time, burst time and pri of process%d: ",i+1);
		scanf("%d%d%d", &p[i].at,&p[i].bt,  &p[i].pri);
		p[i].pid = i+1;
		burst[i] = p[i].bt;
	}

	compute();

	printf("\n");
	printf("Process\t\tPriority\tArrival Time\tBurst Time\tWaiting time\tTurn around time\n");
	for(int i=0; i<n; i++)
	{
		printf("%d\t\t%d\t\t%d\t\t", p[i].pid, p[i].pri, p[i].at);
		printf("%d\t\t%d\t\t%d\n", p[i].bt, p[i].wt, p[i].tat);
	}

	av_turn /= 1.0*n;
	av_wait /= 1.0*n;

	printf("\nAverage waiting time     : %f", av_wait);
	printf("\nAverage turn around time : %f", av_turn);
	printf("\n\n");
}

