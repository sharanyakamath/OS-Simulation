#include<stdio.h>

int safety(int n,int m,int need[][m],int work[m],int allocation[][m])
{	
    int count=0;
	int finish[n],i,j;
	for(i=0;i<n;i++)
	{
		finish[i]=0;
	}
	int done,k,naya[n],var=0;

	while(count!=n)
	{
		done=0;
		for(i=0;i<n;i++)
		{
			if(finish[i]==0)
			{
				for(j=0;j<m;j++)
				{
					if(need[i][j]>work[j])
				    {
				    	break;
				    }
			    }
			    if(j==m)
			    {
			    	done=1;
				    for(k=0;k<m;k++)
				    {
				    	work[k]=work[k]+allocation[i][k];
				    }
				    finish[i]=1;
				    count++;
				    naya[var++]=i;
			    }
		    }
		}
		if(done==0)
		{
			printf("Unsafe\n");
			break;
		}
	}

	if(count==n)
	{
		printf("Safe sequence\n");
		for(i=0;i<var;i++)
		{
			printf("%d ",naya[i]);
		}
		printf("\n");
	}
	return done;
}

int main()
{
	int n,m;
	printf("Enter no. of processes\n");
	scanf("%d",&n);
	printf("Enter no. of resource types\n");
	scanf("%d",&m);
	int available[m],work[m];
	int max[n][m],allocation[n][m],need[n][m],i,j;
	printf("Enter available resources\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&available[i]);
	}
	for(i=0;i<m;i++)
	{
		work[i]=available[i];
	}
	printf("Enter Allocated resources for process\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&allocation[i][j]);
		}
	}

	printf("Enter max resources for process\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}

	safety(n,m,need,work,allocation);

	int request[m],prn;
	printf("Enter the process no. to which we want to decide whether to grant request or not\n");
	scanf("%d",&prn);
	printf("Enter request for each resource\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&request[i]);
	}
	int bro=0;
	for(i=0;i<m;i++)
	{
		if(request[i]<=need[prn][i])
		{
			if(request[i]<=available[i])
			{
				bro=1;
			}
			else
			{
				bro=-1;
				break;
			}
		}
		else if(bro==-1)
		{
			break;
		}
		else if(request[i]>need[prn][i])
		{
			bro=-1;
			break;
		}
	}
	if(bro==1)
	{
		for(i=0;i<m;i++)
		{
			available[i]-=request[i];
			allocation[prn][i]+=request[i];
			need[prn][i]-=request[i];
		}
		for(i=0;i<m;i++)
		{
			work[i]=available[i];
		}
		// check for safety algorithm	
		if(safety(n,m,need,work,allocation)==0)
			printf("request can't be granted\n");
		else
			printf("request is granted\n");
	}
	else
	{
		printf("request can't be granted\n");
	}
	return 0;
}