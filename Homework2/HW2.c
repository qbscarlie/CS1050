/***
  Carlie Procell
  Homework 2
  Due 24 October 2015
  Lab Section J
  LCPN87
***/

#include<stdio.h>
#include<stdlib.h>

#define STU_INFO_ROWSIZE 6
#define STU_INFO_COLSIZE 2

//function prototypes
int checkID(int stuInfo[][2], int idEntered);
void processUndergrad(double billInfo[6][3], int id, int rowNumber);
void processGraduate(double billInfo[6][3], int id, int rowNumber);
void processPhD(double billInfo[6][3], int id, int rowNumber);
int checkHours(int hours, int type);
void processFinalReport(int stuInfo[][2], double billInfo[6][3]);

//main function
int main(void)
{
	int inputID;
	int stuInfo[][2]={ {394003920,2},
			  {388920394,3},
			  {499230076,1},
			  {298760112,2},
			  {592493811,3},
			  {355982306,3}};
	int selection;
	double billInfo[6][3]={0};
	do{
	printf("Enter the student ID: ");
	scanf("%d", &inputID);
	int rowID = checkID(stuInfo, inputID);
	while(rowID==-1)
	{
		printf("\nInvalid Student ID. Please type again: ");
		scanf("%d", &inputID);
		int rowID = checkID(stuInfo, inputID);
	}
	//goes to process type based on second column in stuInfo array
	switch(stuInfo[rowID][1]){
		case 1: processUndergrad(billInfo, inputID, rowID);
			break;
		case 2: processGraduate(billInfo, inputID, rowID);
			break;
		case 3: processPhD(billInfo, inputID, rowID);
			break;
	}
	printf("\nDo you want to continue for next student? If yes hit 1 else hit 0: ");
	scanf("%d", &selection);
	}	while(selection==1);
	processFinalReport(stuInfo,billInfo);
}
//checks that student id is in array
int checkID(int stuInfo[][2], int idEntered)
{
	int i;
	for(i=0; i<6; i++)
	{
		if(idEntered==stuInfo[i][0])
			return i;
	}
	return -1;
}
//processes for undergrad
void processUndergrad(double billInfo[6][3], int id, int rowNumber)
{
	int hours;
	printf("\nEnter the number of credit hours: ");
	scanf("%d", &hours);
	while(checkHours(hours, 1) == 0)
	{
		printf("\nUndergrad students must be enrolled in 3-18 hours. Enter again: ");
		scanf("%d", &hours);
	}
	int scholarship;
	printf("\nEnter scholarship amount: $");
	scanf("%d", &scholarship);
	while(scholarship > .5 * (hours * 750))
	{
		printf("Scholarship can't be more than half of tuition. Enter scholarship again: $");
		scanf("%d", &scholarship);
	}
	int tuition = 750 * hours;
	int total = tuition - scholarship;
	printf("\nUndergrad student %d tuition is:",id);
	printf("\nGross\t\t\t $%d",tuition);
	printf("\nScholarship Amount\t$%d",scholarship);
	printf("\nTotal Tuition Bill\t$%d",total);
	billInfo[rowNumber][0]=tuition;
	billInfo[rowNumber][1]=scholarship;
	billInfo[rowNumber][2]=total;
}
//processes for grad
void processGraduate(double billInfo[6][3], int id, int rowNumber)
{
	int hours;
	printf("\nEnter the number of credit hours: ");
	scanf("%d", &hours);
	while(checkHours(hours, 2) == 0)
	{
		printf("\nGrad students must be enrolled in 3-12 hours. Enter again: ");
		scanf("%d", &hours);
	}
	int scholarship;
	printf("\nEnter scholarship amount: $");
	scanf("%d", &scholarship);
	while(scholarship > .75 * (hours * 1000))
	{
		printf("\nScholarship can't be greater than 75%% of tuition. Enter the correct amount again: $");
		scanf("%d", &scholarship);
	}
	int tuition = 1000 * hours;
	int total = tuition - scholarship;
	printf("\nGraduate student %d tuition is:",id);
	printf("\nGross\t\t\t $%d",tuition);
	printf("\nScholarship Amount\t$%d",scholarship);
	printf("\nTotal Tuition Bill\t$%d",total);
	billInfo[rowNumber][0]=tuition;
	billInfo[rowNumber][1]=scholarship;
	billInfo[rowNumber][2]=total;
}
//processes for phd
void processPhD(double billInfo[6][3], int id, int rowNumber)
{
	int hours;
	printf("\nEnter the number of credit hours: ");
	scanf("%d", &hours);
	while(checkHours(hours, 3) == 0)
	{
		printf("\nPhD students must be enrolled in 3-9 hours. Enter again: ");
		scanf("%d", &hours);
	}
	int stipend;
	printf("\nEnter stipend amount: $");
	scanf("%d", &stipend);
	while(stipend > 10000)
	{
		printf("\nStipend amount wrong. Enter correct amount again: $");
		scanf("%d", &stipend);
	}
	int tuition = 1200 * hours;
	int total = tuition - stipend;
	int selection;
	printf("\nPhD student %d tuition is:",id);
	printf("\nGross\t\t\t $%d",tuition);
	printf("\nStipend Amount\t\t$%d", stipend);
	printf("\nTotal Tuition Bill\t$%d",total);
	billInfo[rowNumber][0]=tuition;
	billInfo[rowNumber][1]=stipend;
	billInfo[rowNumber][2]=total;
}
//checks that hours are correct for each type
int checkHours(int hours, int type)
{
	switch(type){
	case 1: if(hours<3 || hours>18)
			return 0;
		else
			return 1;
	case 2: if(hours<3 || hours>12)
			return 0;
		else
			return 1;
	case 3: if(hours<3 || hours>9)
			return 0;
		else
			return 1;
	}
}
//processes final report of all student id's looked up
void processFinalReport(int stuInfo[][2], double billInfo[6][3])
{
	printf("\nSTUDENT BILLING REPORT\n");
	printf("\nID\t\tTYPE\tGROSS\t\tDISCOUNT\tNET\n");
	int i;
	for(i=0;i<6;i++)
	{
		if(billInfo[i][0]!=0)
		printf("%d\t%d\t%.2f\t\t%.2f\t\t%.2f\n",stuInfo[i][0],stuInfo[i][1],(float)billInfo[i][0],(float)billInfo[i][1],(float)billInfo[i][2]);
	}	
}
