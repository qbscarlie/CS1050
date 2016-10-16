/**
  Carlie Procell
  Prelab 9
  **/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100
//function prototypes
int length(char *s);
char* copy(char *s);
char* reverse(char *s);
void clear(char *s);

int main()
{
	char *s;
	char string[MAX];
	s = string;
	printf("\nEnter a string: ");
	scanf("%s", string);
	printf("\nInput string is %s", string);
	printf("\nLength of string is %d", length(s));
	copy(s);
	reverse(s);
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


