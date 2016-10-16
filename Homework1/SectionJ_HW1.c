/****

Carlie Procell
Homework 1
Section J

****/
#include<stdio.h>
#include<math.h>
int main()
{
	int selection, commissionRate, exit;
	float weeklySales, commission, netIncome;

	printf("Employee type\n");
	printf("(1) Part time\n");
	printf("(2) Full time\n");
	printf("Please make a selection: \n");
	scanf("%d", &selection);
	while(selection<1 ||  selection>2)
	{
		printf("Invalid choice, make a selection again: \n");
		scanf("%d", &selection);
	}
	while(selection==1)
	{
		printf("Enter the weekly sales: \n");
		scanf("%f", &weeklySales);	
		if(weeklySales>0, weeklySales<=10000)
		{
			commissionRate=7;
		}			
		else if(weeklySales>10000, weeklySales<=20000)
		{
			commissionRate=10;
		}		
		else if(weeklySales>20000, weeklySales<=30000)
		{
			commissionRate=15;			
		}
		else if(weeklySales>30000, weeklySales<=50000)
		{
			commissionRate=17;
		}
		else if(weeklySales>50000)
		{
			commissionRate=20;
		}
           	printf("Commission rate is %d%%\n", commissionRate);
            	commission = (weeklySales*commissionRate)/100;
         	printf("Total commission on sales is: $%.2f\n", commission);
           	netIncome = 200 + commission;
            	printf("Net income is: $%.2f\n", netIncome);
		printf("Do you want to continue type -1 to exit: \n");
		scanf("%d", &exit);
		if(exit==-1)
		{
			printf("Exiting the sales commission calculator.\n");
			break;
		}
		else
		{	
			return main();
		}
	}
	while(selection==2)
	{
		printf("Enter the weekly sales: \n");
		scanf("%f", &weeklySales);
		if(weeklySales>0, weeklySales<=10000)
		{
			commissionRate=5;
		}
		else if(weeklySales>10000, weeklySales<=20000)
		{
			commissionRate=9;
		}
		else if(weeklySales>20000, weeklySales<=30000)
		{
			commissionRate=12;
		}
		else if(weeklySales>30000, weeklySales<=50000)
		{
			commissionRate=15;
		}
		else if(weeklySales>50000)
		{
			commissionRate=20;
		}
            	printf("Commission rate is %d%%\n", commissionRate);
            	commission = (weeklySales*commissionRate)/100;
            	printf("Total commission on sales is: $%.2f\n", commission);
            	netIncome = 300 + commission;
            	printf("Net income is: $%.2f\n", netIncome);
		printf("Do you want to continue type -1 to exit: \n");
		scanf("%d", &exit);
		if(exit==-1)
		{
			printf("Exiting the sales commission calculator.\n");
			break;
		}
		else
		{
			return main();
		}
	}
}
