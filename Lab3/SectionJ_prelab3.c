/**
Carlie Procell
Section J
Prelab 3
**/
#include<stdio.h>
#include<math.h>
int main()
{
	int selection, selection2, area;	

	printf("Area calculation\n");
	printf("(1) Square\n");
	printf("(2) Cube\n");
	printf("(3) Circle\n");
	printf("Please make a selection: \n");
	scanf("%d", &selection);
	while(selection<1 || selection>3)
	{
		printf("Invalid choice, make a selection again: \n");
		scanf("%d", &selection);
	}
	while(selection >= 1 || selection <= 3)
	{
		printf("Enter a positive number: \n");
		scanf("%d", &selection2);
		if(selection2 <= 0)
		{
			printf("Number can't be negative or zero\n");
			printf("Enter a positive number: \n");
			scanf("%d", &selection2);
		}
		else
		{
			switch(selection)
			{
				case 1:
				area = selection2 * selection2;
				printf("Length of side of square is %d\n", selection2);
				printf("Area of square is %d\n", area);
				return 0;

				case 2:
				area = 6*selection2*selection2;
				printf("Length of side of cube is %d\n", selection2);
				printf("Area of cube is %d\n", area);
				return 0;

				case 3:
				area = 3.14159*selection2*selection2;
				printf("Radius of circle is %d\n", selection2);
				printf("Area of circle is %d\n", area);
				return 0;
			}
		}
	}
}
