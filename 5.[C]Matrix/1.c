#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define x 2500
#define y 100

int main()
{
	int matrix[x][y];
	int i,j,k;
	int rep=x*10,tmp;
	clock_t start,intermediate,finish;
	
	start=clock();
	
	for(k=0;k<rep;k++)
		for(i=0;i<x;i++)
			for(j=0;j<y;j++)
				tmp=matrix[i][j];

	intermediate = clock();

	for(k=0; k<rep;k++)
		for(i=0; i<x; i++)
			for(j=0; j<y; j++)
				tmp=matrix[j][i];

	finish = clock();

	printf("by rows: %d <--must be smaller\nby columns: %d\n", (int)(intermediate-start), (int)(finish-intermediate));
	return 0;
}