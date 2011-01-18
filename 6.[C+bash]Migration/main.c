#include<stdio.h>
int main(int argc, const char **argv)
{
	int a[100][100],b[100][100],c[100][100],rep,i,j,y;
	if(argc!=2)
		printf("Wrong parametr format\n");
	rep=atoi(argv[1]);
	if(rep==0)
		printf("Wrong parametr format\n");
	for(y = 0; y < rep; y++)
		for(i = 0; i < 100; i++) 
			for(j = 0; j < 100; j++)
				c[i][j] = a[i][j]*b[j][i];
	return 0;
}