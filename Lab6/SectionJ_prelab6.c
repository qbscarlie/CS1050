/**
Name: Carlie Procell
Pawprint: LCPN87
Prelab6
**/
#include<stdio.h>
#include<math.h>

//function prototypes
void display_option();
int check_option(int);
int check_year(int);
int check_amount(float);

int main(void)
{
    int selection, year;
    float amount, amountCI, interestEarned;
    double interestRate;
    display_option();
    scanf("%d", &selection);
    
    while(check_option(selection) < 1 || check_option(selection) > 3)
    {
        printf("Incorrect choice, please make a choice again\n");
        display_option();
        scanf("%d", &selection);
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
    while(check_year(year) < 1 || check_year(year) > 10)
    {
        printf("Incorrect value, year should be between 1-10\n");
        printf("Enter a year: ");
        scanf("%d", &year);
    }
    
    printf("Enter the amount: ");
    scanf("%f", &amount);
    while(check_amount(amount) <= 0)
    {
        printf("Incorrect value, enter the amount again\n");
        printf("Enter the amount: ");
        scanf("%f", &amount);
    }
    
    amountCI = amount * pow(interestRate, (double)year);
    printf("Total amount earned after 3 years is $%.2f\n", amountCI);
    interestEarned = amountCI - amount;
    printf("Total interest earned on the amount $%.2f is $%.2f\n", amount, interestEarned);
    return 0;
}

void display_option()
{
    printf("Bank account type\n");
    printf("(1) Checking\n");
    printf("(2) Saving\n");
    printf("(3) Fixed deposit\n");
    printf("Please make a selection: ");
}
int check_option(int selection)
{
    if(selection < 1 || selection > 3)
        return 0;
    else
        return 1;
}
int check_year(int year)
{
    if(year<1 || year>10)
        return 0;
    else
        return 1;
    
}
int check_amount(float amount)
{
    if(amount<=0)
        return 0;
    else
        return 1;
}
