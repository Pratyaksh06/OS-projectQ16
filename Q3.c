#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


typedef struct proccess
{
  int arrival_time;
  int burst_time;
  int completion_time;
  int turnaround_time;
  int waiting_time;
  int btt;
  int pro_id;




}Schedule;

bool compare(Schedule a,Schedule b)
{
	return a.arrival_time<b.arrival_time;


}
bool compare2(Schedule a,Schedule b)
{
	return a.burst_time<b.burst_time;



}

int main()
{
	Schedule pro[100];

	int n,i,j,pcom;
	float avg_waiting_time=0;
	float avg_turnaround_time=0;
	int total_time=0;


    printf("   !!!!   Enter the number of Process:   !!!!\n");
  scanf("%d",&n);

  printf("\t\tEnter the arrival time and burst time Process Id\n");
      printf(" Process Id.   arrival time    burst time     \n");

	for(i=0;i<n;)
	{

		int c=i;
		printf("process %d\t\t",i);
		int at;
		scanf("%d",&at);
		if(at==0)
{
	printf("   ->->->  Shouldn't be zero\n");

	i=c;
	printf("    ->->->   values of i%d\n",i);
		continue;
}
pro[i].arrival_time=at;
		scanf("%d",&pro[i].burst_time);
		pro[i].btt=pro[i].burst_time;

	//	printf("arriva time %d",pro[i].arrival_time);
		i++;


	}


//	sort(pro,pro+n,compare);
 qsort(pro, n, sizeof(int), compare);


	i=0;
	pcom=0;
	while(pcom<n)
	{
		for(j=0;j<n;j++)
		{
			if(pro[j].arrival_time>i)
			break;
		}

		//sort(pro,pro+j,compare2);
qsort(pro,n,sizeof(int),compare2);


		if(j>0)
		{

			for(j=0;j<n;j++)
			{
				if(pro[j].burst_time!=0)
				break;
			}
			if(pro[j].arrival_time>i)

			{
				i=pro[j].arrival_time;

			}
			pro[j].completion_time=i+1;
			pro[j].burst_time--;
		}
		i++;
		pcom=0;
		for(j=0;j<n;j++)
		{
			if(pro[j].burst_time==0)
			pcom++;
		}
	}

	printf("ProID\tAtime\tBtime\tCtime\tTatime\tWtime\n");

	for(i=0;i<n;i++)
	{
		pro[i].turnaround_time=pro[i].completion_time-pro[i].arrival_time;
		pro[i].waiting_time=pro[i].turnaround_time-pro[i].btt;


		avg_turnaround_time=avg_turnaround_time + pro[i].turnaround_time;
		avg_waiting_time=avg_waiting_time + pro[i].waiting_time;
    total_time=total_time + pro[i].btt;

		printf("%d\t",i);
    printf("%d\t",pro[i].arrival_time);
    printf("%d\t",pro[i].btt);
    printf("%d\t",pro[i].completion_time);
    printf("%d\t",pro[i].turnaround_time);
    printf("%d\t",pro[i].waiting_time);



		printf("\n\n");
	}
		avg_turnaround_time=	avg_turnaround_time/n;
		avg_waiting_time=avg_waiting_time/n;
	 printf("avage waiting time is :%f\n",avg_waiting_time);
	 printf("avage turn around time is :%f\n",avg_turnaround_time);
	 printf("avage total time taken by complet the process is :%d\n",total_time);



	return 0;
}
