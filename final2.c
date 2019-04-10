 #include<stdio.h>
int main()
{
     int k,j,q,i,n,time_slice,temp;
     int Total_wait;        float average_waiting_time;
     int burst_time[10],wait_time[10],te[10],rt[10],arrival_time[10];j=0;
     printf("enter number of process :\t");
     scanf("%d",&n);
    printf("\n enter brust time and arriavl time\n");
    for(i=0;i<n;i++)
      {
          printf("P%d  \nbrust time ",i+1);
          scanf("%d",&burst_time[i]);
          printf("ariavl time   :  ");
          scanf("%d",&arrival_time[i]);
          te[i]=0;     wait_time[i]=0;
      }
    for(i=0;i<n;i++)
      {
        for(j=i+1;j<n;j++)
         {
             if(arrival_time[i]>arrival_time[j])
               {
                    temp=arrival_time[i];                                          //here i am sorting the processes according to their arrival time
                   	 	arrival_time[i]=arrival_time[j];
                    		arrival_time[j]=temp;
                    			temp=burst_time[i];
                    				burst_time[i]=burst_time[j];
					                    burst_time[j]=temp;
              }
         }
     }
    printf("\n enter time slice\t");
    scanf("%d",&time_slice); q=0;   
    printf("\nprocess      :")  ;
    for(i=0;i<n;i++)
     {
       printf("  %d",i+1);
      }
    printf("\nBrust time   :");
    for(i=0;i<n;i++)
       {
         printf("  %d",burst_time[i]); rt[i]=burst_time[i];
        }
    printf("\nArrival time :");
    for(i=0;i<n;i++)
      {
          printf("  %d",arrival_time[i]);
      }
    printf("\n Gannt chart \n");
    j=0;

    while(j<=n)
       {
          j++;
          for(i=0;i<n;i++)
            {
              if(rt[i]==0)  continue;
                   if(rt[i]>time_slice)
                     {
                        printf("\n %d\t P%d",q,i+1);
                        q=q+time_slice;
                        rt[i]=rt[i]-time_slice;
                        te[i]=te[i]+1;
                     }
                  else
                    {
                       printf("\n %d\t P%d",q,i+1);
                       wait_time[i]=q-te[i]*time_slice;
                       q=q+rt[i]; 
                       rt[i]=rt[i]-rt[i];
                    }
            }
       }                                   //end of while     
    average_waiting_time=0;
    printf("\n Process   Waitnig time");
    for(i=0;i<n;i++)
       {
                wait_time[i]=wait_time[i]-arrival_time[i];
                    printf("\n P%d      :   %d",i+1,wait_time[i]); 
					   	average_waiting_time=average_waiting_time+wait_time[i];
        }
    Total_wait=average_waiting_time;
    printf("\ntotal waiting time %d",Total_wait);
    printf("\n Avg wainting time %f ",average_waiting_time/n);
    
 }
