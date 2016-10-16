/****
Name: Carlie Procell
Lab 2 Section J
Date: 2 September 2015
****/

#include<stdio.h>

int main()
{
	int num1;
	int num2;
	int sum;
	int product;
	int quotient1;
	int quotient2;
	int remainder1;
	int remainder2;
	
	printf("\n Enter the first integer: ");
	scanf("%d", &num1);

	printf("\n Enter the second integer: ");
	scanf("%d", &num2);

	sum = num1 + num2;
	product = num1 * num2;
	quotient1 = num1 / num2;
	quotient2 = num2 / num1;
	remainder1 = num1 % num2;
	remainder2 = num2 % num1;
	
	printf("The sum of %d and %d is %d ", num1,num2,sum);
	printf("\nThe product of %d and %d is %d", num1,num2,product);
	printf("\nFor %d divided by %d is %d and remainder is %d", num1,num2,quotient1,remainder1);
	printf("\nFor %d divided by %d is %d and remainder is %d", num2,num1,quotient2,remainder2);
	
	if(num1>num2)
	{
		printf("\n %d is the bigger number", num1);
	}
	else
	{
		printf("\n %d is the bigger number", num2);
	}
	if(num1%2==0)
	{
		printf("\n %d is an even number", num1);
	}
	else
	{
		printf("\n %d is an odd number", num1);
	}
	if(num2%2==0)
	{
		printf("\n %d is an even number", num2);
	}
	else
	{
		printf("\n %d is an odd number\n", num2);
	}
}
