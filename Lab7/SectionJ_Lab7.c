/***
Name: Carlie Procell
pawprint: lcpn87
Lab 7, Section J
Lab code: my fav mode of transportation is velociraptor
***/
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define MAX 100

int check_error(int);
void initialize_array(int[], int );
void print_array(int [], int);
float average(int[], int);
int count_numbers(int[], int, int);
int common_numbers(int[], int[], int);

int main(void)
{
    srand(time(NULL));
    int selection, selection2;
    int array[MAX], array2[MAX];
    
    printf("Enter the size of the input:\n");
    scanf("%d", &selection);
    
    while(check_error(selection) == 0)
    {
        printf("Invalid input. Enter the size of the input again:\n");
        scanf("%d", &selection);
    }
    
    initialize_array(array, selection);
    initialize_array(array2, selection);
    print_array(array, selection);
    print_array(array2, selection);
    average(array, selection);
    printf("\nAverage of first array is %.2f\n", average(array, selection));
    average(array2, selection);
    printf("\nAverage of second array is %.2f\n", average(array2, selection));
    printf("\nEnter a number: \n");
    scanf("%d", &selection2);
    count_numbers(array, selection, selection2);
    printf("\nThe count of number %d in the first array is %d", selection2, count_numbers(array, selection, selection2));
    count_numbers(array2, selection, selection2);
    printf("\nThe count of number %d in the second array is %d", selection2, count_numbers(array2, selection, selection2));
    common_numbers(array, array2, selection);
    printf("\nThe number of common numbers in the two arrays are %d", common_numbers(array, array2, selection));
    return 0;
}


int check_error(int selection)
{
    if(selection < 1 || selection > 100)
     return 0;
    else
     return 1;
}

void initialize_array(int array[], int size )
{
    int i;
    for (i=0; i<size; i++)
	array[i] = rand() % 10;
}

void print_array(int array[], int size)
{
    int i;    
    printf("\nInput array\n");
    for (i=0; i<size; i++)
	printf("%3d",array[i]);
}

float average(int array[], int size)
{
	int i, sum;
	sum=0;
	float average;
	for(i=0; i<size; i++)
		sum = sum + array[i];
	average=(float)sum/(float)size;
	return average;
}
int count_numbers(int array[], int size, int num)
{
	int i, count;
	count=0;
	for(i=0; i<size; i++)
	{
		if(array[i]==num)
			++count;
	}
	return count;
}
int common_numbers(int array[], int array2[], int size)
{
	int i, j, common;
	for(i=0; i<size; i++)
	{
		common=0;
		for(j=0; j<size; j++)
		{
			if(array[i]==array2[j])
				common++;
		}
	}
	return common;
}
