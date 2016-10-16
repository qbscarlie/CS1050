/**
Carlie Procell
Section J
Prelab 4
**/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void displayMenu ();// Function prototype 
int check_option(int opt);// Function prototype
int generateNumber();
int cube (int a);
float division(int a, int b);

int main()
{	
	int select = 0;
	
	
	srand(time(NULL));
	displayMenu();// calling function
	scanf("%d", &select);
	
	while( check_option(select) == 0)// if 0, do invalid message
		{
			printf("\nINVALID INPUT! TRY AGAIN!");
			displayMenu();
			scanf("%d", &select);
		}
	int a = generateNumber(); // calling function
	int b = generateNumber ();	// calling function
	int ans = 0;
	if ( select == 1) {
		ans = cube (a);
		printf("\nCube of %d is %d", a, ans);
	}
	else
	{
		float answer = division(a, b);
		if (a > b)
		printf("\nDiv(%d, %d) = %f", a, b, answer);
		
		else
		printf("\nDiv(%d, %d) = %f", b, a, answer); 
	}
			
	return 0;
}

void displayMenu ()
{
	printf("\nPlease select an operation\n 1: Cube\n 2: Division\n Enter your choice:");
}

int check_option(int opt)// sending to while
{
	if (opt != 1 && opt != 2 )
		return 0;
		
	else 
		
		return 1;
}

int generateNumber ()// random number generator
{
	int a = 0;
	a = rand() % 10;// generates random number 0 to 9
	
	return a;
}

int cube (a)// initializing cube
	{
		return a;
	}
	
float division (int a, int b)// initializing div
	{ 
	//figure out which 'int' is bigger
	//have the bigger 'int'
		if (a > b)
		{	
			return (float) a / b;
		}
		else 
		{
			return (float) b / a;
		}
	}
	
	
