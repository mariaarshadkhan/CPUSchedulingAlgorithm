#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
printf("Please enter the number of processes:"); //prompt user for no of process
int n;//declare
scanf("%d",&n);//user input
int Arrival[n],Burst[n],TurnAround[n],wait_time[n];//declare
char process_name[n];//declare
int i,wait_sum=0,burst_sum=0,turnAround_sum=0,avg_wait,avg_turnAround;//declare and initialized tat n wt as sum 0
float through_put=0;
int end[n]; //end time
	int count=0;
int execution[n];//it's the start time
for(i=0;i<n;i++) //will ask the process name,AT and BT as per user input for number of processes
{ //taking user input n time.
printf("Enter the name of process:");
scanf("%s",&process_name[i]);

printf("Enter the Arrival time:");
scanf("%d",&Arrival[i]);

printf("Enter Burst Time:");
scanf("%d",&Burst[i]);

}


	execution[0]=Arrival[0]; // first process executes whenever it arrives
      end[0]=execution[0]+Burst[0];// first process ends at arrival+burst




for(i=1;i<n;i++)//process by shortest burst time.
{

    int j;
    for(j=2;j<n;j++)
    {


        int temp;

if(Burst[j-1]>Burst[j]) //sorting in accordance to burst time
        {

           char temp_pn;
           temp_pn=process_name[j-1];
           process_name[j-1]=process_name[j];
           process_name[j]=temp_pn;

            int temp_at;
            temp_at=Arrival[j-1];
            Arrival[j-1]=Arrival[j];
            Arrival[j]=temp_at;

            temp=Burst[j-1];
            Burst[j-1]=Burst[j];
            Burst[j]=temp;



}
}
}


            for(i=1;i<n;i++) //computing start and end time of the rest
            {

                  execution[i]=end[i-1];
                  end[i]=execution[i]+Burst[i];

            }

            wait_time[0]=0;
            for(i=1;i<n;i++) // computing wait time of every process
            {

                wait_time[i]=execution[i]-Arrival[i];

            }
		for(i=0;i<n;i++) // computing turn around of every process
            {
                TurnAround[i]=wait_time[i]+Burst[i];

            }




            printf("GANT CHART:");

           for(i=0;i<n;i++)
           {

            printf("%d \t",execution[i]);//all processes start time is being printed

           }
           printf("%d \t",end[n-1]);//last process end time is being printed
	//table generation

            printf("\n Process Name \t Arrival Time \t Burst Time \t Wait Time \t TurnAround Time\n");
           for(i=0;i<n;i++)

           {   printf("%c \t\t %d \t\t %d \t\t %d \t\t %d\n",process_name[i],Arrival[i],Burst[i],wait_time[i],TurnAround[i]);
           }

		   for(i=0;i<n;i++)
		   {
			  wait_sum=wait_sum+wait_time[i];
			  turnAround_sum=turnAround_sum+TurnAround[i];
			  burst_sum=burst_sum+Burst[i];
		   }
		   avg_wait=wait_sum/n;
		   avg_turnAround=turnAround_sum/n;
		   through_put=n/burst_sum;
           printf("\nTotal Wait Time: %d \n",wait_sum);
		   printf("Average Wait Time :%d  \n",avg_wait);
		   printf("Total Turn Around time :  %d\n",turnAround_sum);
		   printf("Average Turn Around Time:   %d\n",avg_turnAround);
		   printf("Through Put:  %f\n",through_put);




           return 0;

}

