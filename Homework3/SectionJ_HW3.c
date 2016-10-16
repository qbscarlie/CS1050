/***
  Carlie Procell
  Section J
  Homework 3
  LCPN87
  ***/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

//function prototypes
int load_data(char*, char**, int*, float*, int);
void print_data(char**, int*, float*, int);
int check_account(char**, int*, char*, int, int);
int string_compare(char*, char*);
int highest_amount(float*, int);
int lowest_amount(float*, int);
float average_amount(float*, int);
void write_data(char*, char**, int*, float*, int, int, int, float);
int length(char* s);

//main function
int main(int argc, char *argv[])
{
	if(argc!=4)
	{
		printf("\n Insufficient arguments \n ");
		return 0;
	}
	
	int n=atoi(argv[2]);
	int *acn,d, choice;
	float *amt, amount;
	
	char **name;
	
	acn=malloc(sizeof(int)*n);	
	amt=malloc(sizeof(float)*n);
	name=malloc(sizeof(char*)*n);
	char *str=malloc(sizeof(char)*n);
	
	int i;
	for (i=0;i<n;i++)
	{
		*(name+i)=malloc(sizeof(char)*100);
	}
	
	int size=load_data(argv[1], name, acn, amt, n);
	
	if(size==0)
	{
		printf("\n Unable to open the input file \n");
		return 0;
	}
	
	print_data(name, acn, amt, n);
	
	printf("\nEnter a name: ");
	scanf("%s", str);
	
	printf("\nEnter an account number: ");
	scanf("%d", &d);
	
	//Call check account function and display its output
	int checkAct=check_account(name, acn, str, n, d);
	if(checkAct==-1)
	{
		printf("\nThis user does not have an account.");
	}
	int highindex=0;
	highindex = highest_amount(amt, n);
	printf("\n%s has the highest amount $%.2f in the account number %d\n", *(name+highindex), *(amt+highindex), *(acn+highindex));
	int lowindex=0;
	lowindex = lowest_amount(amt, n);
	printf("\n%s has the lowest amount $%.2f in the account number %d\n", *(name+lowindex), *(amt+lowindex), *(acn+lowindex));
	float avg=0;
	avg = average_amount(amt, n);
	printf("\nThe average amount is $%.2f\n", avg);
	write_data(argv[3],name, acn, amt, n, highindex, lowindex, avg);
	
	free(acn);
	free(amt);
	
	for (i=0;i<n;i++)
	{
		free(*(name+i));
	}
	free(name);
	return 0;
}

//function to find length of the string
int length(char* s)
{
	int length=0;
	while(*(s+length)!='\0')
	{
		length++;
	}
	return length;
}

//function to load data
int load_data(char* filename, char **name, int *x , float *y, int size)
{
	int i=0;
	FILE* file=fopen(filename,"r");
	if(file==NULL)
	{
		return 0;
	}
	
	int id ;
	float amt;
	char n[100];
	
	for(i=0;i<size;i++)
	{
		fscanf(file,"%s %d %f",n,&id,&amt);
		
		strcpy(*(name+i),n);
		*(x+i)=id;
		*(y+i)=amt;
		
	}
		
	fclose(file);
	return 1;
}

//function to print data
void print_data(char** n, int* acn, float* amt, int size)
{
	printf("\nName\tAccount No.\tAmount\n");
	int i;
	for(i=0;i<size;i++)
	{
		printf("%s\t\t%d\t%.2f\n", *(n+i), *(acn+i), *(amt+i));
	}

}
//function to check account
int check_account(char** n, int* acn, char* name, int size, int d)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(string_compare(*(n+i), name)==1)
		{
			if(*(acn+i) == d)
				return i;
			else
				return -1;
		}
	}
	return -1;
}

//function to compare strings
int string_compare(char* name1, char* name2)
{
	int i;
	for(i=0;i<length(name1);i++)
	{
		if(*(name1+i)!=(*(name2+i)))
			return 0;
	}
	return 1;
}

//function to find highest amount
int highest_amount(float* highest, int size)
{
	int i, index=0;
	for(i=1;i<size;i++)
	{
		if(*(highest+i)>*(highest+index))
			index=i;
	}
	return index;
}

//function to find lowest amount
int lowest_amount(float* lowest, int size)
{
	int i, index=0;
	for(i=1;i<size;i++)
	{
		if(*(lowest+i)<*(lowest+index))
			index=i;
	}
	return index;
}

//function to find avg amount
float average_amount(float* money, int size)
{
	int i;
	float sum=0, avg;
	for(i=0;i<size;i++)
	{
			sum+=*(money+i);
	}
	avg=sum/size;
	return avg;
}

//function to write data
void write_data(char* filename, char** name, int* acn, float* amt, int n, int highindex, int lowindex, float avg)
{
	FILE*output = fopen(filename, "w");
	fprintf(output, "Name\tAccount No.\tAmount\n");
	int i;
	for(i=0;i<n;i++)
	{
		fprintf(output, "%s\t%d\t\t%.2f\n", *(name+i), *(acn+i), *(amt+i));
	}
	fprintf(output, "%s has the highest amount $%.2f in the account number %d\n", *(name+highindex), *(amt+highindex), *(acn+highindex));
	fprintf(output, "%s has the lowest amount $%.2f in the account number %d\n", *(name+lowindex), *(amt+lowindex), *(acn+lowindex));
	fprintf(output, "The average amount is $%.2f\n", avg);
}


