#include <stdio.h>
#include <stdlib.h>
void alert(char *mes,char *file)
{
	if(file)
	{
		printf("%s",mes);
		printf("%s",file);
	}
	else
		printf("%s",mes);
	exit(1);
}
int cmp(const void *a, const void *b)
{
     return *(int*)a - *(int*)b;
 }
int main(int argc, char *argv[])
{
	FILE *in;
	FILE *out;
	int *numbers=NULL;
	int start=1;
	int count=0;
	int input;
	int *more_numbers;
	int i=0;
	if(argc<3)
		alert("Wrong parametrs format","");
	while(start<argc-1)
	{
		in=fopen(argv[start],"r");
		if(!in)
			alert("Couldn't open input file: ",argv[start]);
		while(!feof(in))
		{
			int read=fscanf(in,"%d",&input);
			if(!read)
			{
				fclose(in);
				alert("Wrong input type in file: ",argv[start]);
			}
			count++;
			more_numbers = (int*) realloc (numbers, count * sizeof(int));
			if (more_numbers) 
			{
				numbers=more_numbers;
				numbers[count-1]=input;
			}
			else
			{
				free (numbers);
				alert("Error (re)allocating memory","");
			}
		}
		start++;
	}
	qsort(numbers, count, sizeof(int),cmp);
	out=fopen(argv[argc-1],"w");
	if(!out)
        alert("Couldn't create output file: ",argv[argc-1]);
	for(;i<count;i++) 
	{
		int write=fprintf (out,"%d\n",numbers[i]);
		if(!write)
		{
			fclose(out);
			alert("Couldn't write number to output file","");
		}
	}
	free (numbers);
	return 0;
}