#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
// the structure for round robin scheduling algorithm with gantt chart.

 struct struct_rra
{
int process_id, burst_time, burst_time_bal,arrival_time;
float total_average_time, waiting_time;
};
int main()  
  {
  struct struct_rra process[10];
  int i,j,k,n,tq;
  int sum_burst_time=0,sum_total_average_time=0,sum_waiting_time=0,sum_total_arrival_time=0,tq_used=0;
  int gantt[2][50];//gant chart 2d array
  printf("Enter number of process required : ");
  scanf("%d",&n);
  for(i=0;i<n;i++) 
  {
  	printf("\n\nArrival Time:\t");
    scanf("%d", &process[i].arrival_time);
    printf("\n\nBurst-time of process %d: ",i+1);
    process[i].process_id = i+1; //giving process id
    scanf("%d",&process[i].burst_time);
    process[i].burst_time_bal = process[i].burst_time;
  }
  printf("\n\nEnter time quantums of the process : ");
  scanf("%d",&tq);
  for( i=0;i<n;i++)
  sum_burst_time += process[i].burst_time;
  printf("\nSum of burst time = %d\n",sum_burst_time);
  k=0;
  do
  {
    for( i=0;i<n;i++) {
      if( process[i].burst_time_bal > 0 && process[i].burst_time_bal<= tq )
      {
        tq_used += process[i].burst_time_bal;
        process[i].total_average_time = tq_used;
        process[i].waiting_time = process[i].total_average_time - process[i].burst_time;
        process[i].burst_time_bal = 0;
        gantt[0][k] = process[i].process_id;
        gantt[1][k] = tq_used;
        k++;
      }
      else if( process[i].burst_time_bal >0 )
      {
        tq_used += tq;
        process[i].burst_time_bal -= tq;
        gantt[0][k] = process[i].process_id;
        gantt[1][k] = tq_used;
        k++;
      }
      else if( process[i].burst_time_bal < 0 )
      {
        printf("\nError: burst time Negative \n");
        
      }
  }} while( tq_used != sum_burst_time);


printf("\n Round Robin scheduling program in c with gantt chart\n\n");
printf("process_id: ");
for( i=0; i<n;i++)
printf("\t%d",gantt[0][i]);
printf("\n\nTime: ");
for( i=0; i<n;i++)
printf("\t%d",gantt[1][i]);
for( i=0;i<n;i++)
sum_waiting_time += process[i].waiting_time;
for( i=0;i<n;i++)
sum_total_average_time += process[i].total_average_time;
printf("\n\nProcess_id: ");
for( i=0;i<n;i++)
printf("\t%d",i+1);
printf("\n\nArrival Time: ");
for( i=0;i<n;i++)
printf("\t%d",process[i].arrival_time);
printf("\n\nBurst_time: ");
for( i=0;i<n;i++)
printf("\t%d",process[i].burst_time);

printf("\n\nTotal waiting time = %d\n",sum_waiting_time);
printf("Average waiting time = %.2f\n",(float)sum_waiting_time/n);
printf("\n\nTotal turn around time = %d\n",sum_total_average_time);
printf("Average turn around time = %.2f\n\n",(float)sum_total_average_time/n);
return 0;
}
