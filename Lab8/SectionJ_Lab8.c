/*****
  Carlie Procell
  LCPN87
  Section J
  Fav avenger = Thor
  *****/

#include<stdio.h>

#define MAX 100
//function prototypes
int length(char s[]);
int replace(char s[], int i);
void copy(char s[], char s2[]);
void merge(char s[], char s1[], char s2[]);

//main function
int main()
{
	char s[100];
	char s1[100];
	char s2[100];
	int i;
	printf("Enter a string: ");
	scanf("%s", s);
	printf("\nLength of string is %i", length(s));
	copy(s,s2);
	printf("\nCopy of first string is %s", s2);
	printf("\nEnter a position for the replacement operation: ");
	scanf("%i", &i);
	while(i>length(s))
	{
		printf("\nInvalid position");
		printf("\nEnter a position for the replacement operation: ");
		scanf("%i", &i);
	}
	replace(s,i);
	printf("\nString after replacement operation is %s\n", s);
	printf("\nEnter second string: ");
	scanf("%s", s1);
	printf("\nSecond string is %s", s1);
	merge(s, s1, s2);
	printf("\nMerged string is %s", s2);
	return 1;
}
//function to find length
int length(char s[])
{
	int length=0;
	while(s[length]!='\0')
	{
		length++;
	}
	return length;
}
//function to replace character in string
int replace(char s[], int i)
{
	i--;
	s[i]='#';
	return 1;
}
//function to copy strings
void copy(char s[], char s2[])
{
	int i;
	for(i=0; s[i]!='\0'; ++i)
	{
		s2[i]=s[i];
	}
	s2[i]='\0';
}
//function to merge strings
void merge(char s[], char s1[], char s2[])
{
	int i;
	int j=0;
	for(i=0; i<MAX; i++)
	{
		s2[i]=s[j];
		if(s2[i]=='#')
		{
			j=0;
			s=s1;
			s2[++i]=s[j];
		}
	   /** else if(s2[i]=='\0')
		{
			j=0;
			s=s1;
			s2[i]=s[j];
		}**/
		j++;
	}
	s[i]='\0';
}

