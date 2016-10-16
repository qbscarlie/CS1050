/**
  Carlie Procell
  LCPN87
  Section J
  Favorite place: Djibouti
  **/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100
//function prototypes
int length(char *s);
char* copy(char *s);
char* reverse(char *s);
void clear(char *s);
int search(char *s, char c);
int prefix(char *s1, char *s2);

//this is the main function
int main()
{
	char *s;
	char string[MAX];
	s = string;
	char s1[MAX];
	char s2[MAX];
	char c;
	printf("\nEnter a string: ");
	scanf("%s", string);
	printf("\nInput string is %s", string);
	printf("\nLength of string is %d", length(s));
	copy(s);
	reverse(s);
	//I was going to put the printf's in main, but then I kept going to seg fault city and gave up :/
	printf("\nEnter a character for the search operation: ");
	scanf(" %c", &c);
	while((search(s,c))==-1)
	{
		printf("Character not found in %s, please try again ", s);
		scanf(" %c", &c);
	}
	printf("\nCharacter %c is present at the index %d in the string %s", c, search(s, c), s);
	printf("\nEnter a string for the prefix operation: ");
	scanf("%s", s1);
	printf("\nEnter a string to check for prefix: ");
	scanf("%s", s2);
	if((prefix(s1,s2))==1)
	{
		printf("\n%s is a prefix of the string %s", s2, s1);
		return 0;
	}
	else
	{
		printf("\n%s is not a prefix of the string %s", s2, s1);
		return 0;
	}
}
//this is the length function
int length(char *s)
{
	int length = 0;
	while(s[length]!='\0')
	{
		length++;
	}
	return length;
}
//this is the copy function
char* copy(char *s)
{
	char *s2;
	char *s3;
	int len = length(s);
	s2 = (char*) malloc((len+1) * sizeof(char));
	s2[len]='\0';
	s3 = s;
	int i = 0;
	while(*s3 !='\0')
	{
		s2[i++] = *s3++;
	}
	printf("\nCopy of string is %s", s2);
	return s2;
	clear(s2);
}
//this is the reverse function
char* reverse(char *s)
{
	char *s2;
	char *s3;
	int len, i;
	s3 = s;
	for(i=len-1; i>=0; i--)
		s2[len-i-1]=s[i];
	s2[len]='\0';
	printf("\nReverse of string is %s\n", s2);
	return s2;
	clear(s2);
}
//this is the clear function
void clear(char *s)
{
	free(s);
	s = NULL;
}
//this is the search function
int search(char *s, char c)
{
	int i;
	for(i=0;i<length(s);i++)
	{
		while(s[i]==c)
			return i;
		while(s[i]==c)
			return -1;
	}
	clear(s);
}
//this is the prefix function
int prefix(char *s1, char *s2)
{
	int i;
	for(i=0;i<length(s1);i++)
	{
		while(*(s1+i)==*(s2+i))
			return 1;
		while(*(s1+i)!=*(s2+i))
			return 0;
	}
	clear(s1);
	clear(s2);
}
