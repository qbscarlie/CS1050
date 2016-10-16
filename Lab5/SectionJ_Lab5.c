/**
Carlie Procell
Section J
Lab 5
Lab code: Tesla
**/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function prototypes
int lucky_seven(int, int);

void display_option();

int throw_dice();

int check_guess(int );



int main()
{
	int num;
	
	float choice;
	srand(time(NULL));
	display_option();
		
			printf("\nPlease select a option: ");
			scanf("%d", &choice);
			while(check_guess(choice)==0);
			{

				printf("\nInvalid choice");
				display_option();
				printf("\nPlease select a option: ");
				scanf("%d", &choice);
			}
			
			throw_dice();
	

				if(lucky_seven(num, choice))
   		        {
                      printf("\nYou win your guess is correct the dices sum is %f \n",  num);
                                      
                }
              		else
              		{
                          printf("\nYou lost your guess is incorrect the dices sum is %f \n", num);
                                        	
                                        
         			 }
						
	return 0;
}

int check_guess(int x)
{

	if(x<1 | x>3)
		return 0;
	else
		return 1;

}

void display_option()
{

 printf("\nEnter your guess (1) Lucky 7 (2) above 7 (3) below 7: ");
    
}


int lucky_seven(int x, int option)
{

	switch(option)
	{

		case 1: 
		
		if(option=7)
			return 1;
		else
			return 0;
		break;


		
        case 2:

                if(option>7)
                        return 1;
                else
                        return 0;
                break;
		
	    case 3:

                if(option<7)
                        return 1;
                else
                        return 0;
                break;
	}

}



int throw_dice()
{
	int x=1+rand()%7;

	int y=1+rand()%7;
	
	int num = x + y;

	printf("\n Sum of dice is %d ", num);
	
	return num;
}





