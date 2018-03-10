#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n,m,c=0,i,j;
  printf("enter the number of processes\n");
  scanf("%d",&n);
  printf("enter the number of resources\n");
  scanf("%d",&m);
  int p[n];
  int max[n][m],alloc[n][m],need[n][m];
  int avail[m];
  int finish[n];
  for(i=0;i<n;i++)
    finish[i]=0;
  printf("enter the values\n");
  for(i=0;i<n;i++)
  {
    printf("process %d\n",i);
    printf("enter the max value\n");
     for(j=0;j<m;j++)
       scanf("%d",&max[i][j]);
     printf("enter the allocated value of resources\n");
     for(j=0;j<m;j++)
       scanf("%d",&alloc[i][j]);  
     for(j=0;j<m;j++)
       need[i][j] = max[i][j] - alloc[i][j];
  }
   
   for(i=0;i<n;i++) {
    for(j=0;j<m;j++)
     {
      printf("%d ",need[i][j]);
     } 
       printf("\n");
   }
       
   printf("enter the available instances of resources\n");
   for(j=0;j<m;j++)
    scanf("%d",&avail[j]);    
           
   int counter=0; 
   
   while(counter!=n)
   {
     for(i=0;i<n;i++)
       {       
         int check=1;
         if(finish[i]==0) 
         {
          
         for(j=0;j<m;j++)
           {
             if(need[i][j] <= avail[j])
                check=0;  
             else
             {
                check=1;
                break;   
             }   
           }  
            if(check==0)
             {
              p[c++]=i;
              finish[i]=1;
               for(int k=0;k<m;k++)  
               {  
               avail[k] = avail[k]+ alloc[i][k];
               }
            }
         }
       }
       counter++;
       
     }
     int count =0;
    for(i=0;i<n;i++)
    { 
     if(finish[i]==0)
     {
       int count=1;
       break;
     }
    }    
    if(count==0)
     printf("the system is safe\n");
    else
     printf("the system is not safe\n");
      
     printf("\nthe order\n");
     for(i=0;i<n;i++)
     printf("%d ",p[i]);
     
  }                             
               
             
             
             
             
             
