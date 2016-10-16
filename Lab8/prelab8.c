//Carlie Procell
//Prelab 8
//Section J

#include<stdio.h>

//function prototypes
int length(char s[]);
int replace(char s[], int i);

int main()
{
	char s[100];
	int i;
	printf("Enter a string: ");
	scanf("%s", &s);
	printf("\nLength of string is %i", length(s));
	printf("\nEnter a position for the replacement operation: ");
	scanf("%i",&i);
	while(i>length(s))
	{
		printf("\nInvalid position");
		printf("\nEnter a position for the replacement operation: ");
		scanf("%i",&i);
	}
	replace(s,i);
	printf("\nString after replacement operation is %s",s);
	return 1;
}
int length(char s[])
{
	int length=0;
	while(s[length]!='\0')
	{
		length++;
	}
	return length;
}
int replace(char s[], int i)
{
	i--;
	s[i]='#';
	return 1;
}

