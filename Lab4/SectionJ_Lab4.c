/**
Carlie Procell
Section J
Lab 4
Lab code: Fartz
**/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function prototypes
void display_option() ;
int check_guess(int guess) ;
int throw_dice() ;
int lucky_seven(int sum, int guess) ;

int main()
{
	int guess = 0;
	int guess1 = 0;
	srand(time(NULL));
	display_option();
	scanf("%d", &guess);
	
	while(check_guess(guess) < 1 || check_guess(guess) > 3)
	{
		printf("\nInvalid choice");
		display_option();
		scanf("%d", &guess);
	}
	int sum = throw_dice();
	guess1 = lucky_seven(sum, guess);
}

void display_option()
{
	printf("\nEnter your guess (1) Lucky 7 (2) above 7 (3) below 7:");
	printf("\nPlease select an option: ");
}

int check_guess(int guess)
{
	if(guess != 1 && guess != 2 && guess != 3)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int throw_dice()
{
	int a = 0;
	a = 1 +  rand() % 7;
	int b = 0;
	b = 1 + rand() % 7;
	int sum = 0;
	sum = a + b;
	return sum;
}

int lucky_seven(int sum, int guess)
{
	while(guess == 1)
	{
		if(sum==7)
		{
			printf("\nYou win your guess is correct the dices sum is %d\n", sum);
		}
		else
		{
			printf("\nYou lost your guess is incorrect the dices sum is %d\n", sum);
		}
		return 0;
	}
	while(guess == 2)
	{
		if(sum < 7)
		{
			printf("\nYou win your guess is correct the dices sum is %d\n", sum);
		}
		else
		{
			printf("\nYou lost your guess is incorrect the dices sum is %d\n", sum);
		}
		return 0;
	}
	while(guess == 3)
	{
		if(sum > 7)
		{
			printf("\nYou win your guess is correct the dices sum is %d\n", sum);
		}
		else
		{
			printf("\nYou lost your guess is incorrect the dices sum is %d\n", sum);
		}
		return 0;
	}
}
