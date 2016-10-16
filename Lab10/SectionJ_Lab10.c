/**
  Carlie Procell
  LCPN87
  Lab 10 Section J
  Lab code: fav food: tacos
  **/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv)
{
	//error check # arguments
	//test scores to ifs
	//compute avg
	//if statements for avg
	/**firstName = atoi(argv[1]);
	int lastName = atoi(argv[2]);**/
	int score1 = atoi(argv[3]);
	int score2 = atoi(argv[4]);
	int score3 = atoi(argv[5]);
	int finalScore;
	float avgScore;
	char finalGrade;
	if(argc!=2)
	{
		printf("\nInsufficient arguments");
		return 1;
	}
	else
	{
		finalScore == argv[3] + argv[4] + argv[5];
		finalScore == (finalScore)/3;
		printf("\nThe total score for student %s %s is %f and overall grade is (where a grade will go) in the course", argv[1], argv[2], finalScore);
	}
	return 0;
}

