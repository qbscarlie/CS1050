/**
Name: Carlie Procell
Pawprint: LCPN87
Lab Code: Willow Tree
**/
#include<stdio.h>
#include<math.h>

int main(void)
{
	int selection, year;
	float amount, amountCI, interestEarned;
	double interestRate;

	printf("Bank account type\n\n");
	printf("(1) Checking\n");
	printf("(2) Saving\n");
	printf("(3) Fixed Deposit\n");
	printf("Please make a selection: ");
	scanf("%d", &selection);
	
	while(selection<1 || selection>3)
	{
		printf("Incorrect choice, please make a choice again\n");
		return main();
	}
		switch(selection)
		{
			case 1:
			interestRate = 1.01;
			break;

			case 2:
			interestRate = 1.03;
			break;

			case 3:
			interestRate = 1.07;
			break;
		}
		printf("Enter a year: ");
		scanf("%d", &year);
		while(year<1 || year>10)
		{
			printf("Incorrect value, year should be between 1-10\n");
			printf("Enter a year: ");
			scanf("%d", &year);
		}
		while(year>=1 && year<=10)
		{
			printf("Enter the amount: ");
			scanf("%f", &amount);

			while(amount<=0)
			{
				printf("Incorrect value, enter the amount again: ");
				scanf("%f", &amount);
			}
			amountCI = amount * pow(interestRate, (double)year);
			printf("Total amount earned after 3 years is $%.2f\n", amountCI);
			interestEarned = amountCI - amount;
			printf("Total interest earned on the amount $%.2f is $%.2f\n", amount, interestEarned);
			return 0;
		}
}


