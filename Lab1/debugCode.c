/*
Carlie Procell
LCPN87
Lab code : My first assignment
 */
#include<stdio.h>

int main()
{
	int i, y, x;

	printf("\n Enter the first number: ");
	scanf("%d", x);

	printf("\n Enter the second number: ");
	scanf("%d", &y);

	if(x>y)
	{
		printf("\n is the largest number", x);
	}
	else
	{
		printf("\n %d is the largest number", y);
	}

	printf("\n");
	return 0;
}
