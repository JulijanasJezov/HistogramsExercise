#include <stdio.h>
int main(int argc, char *argv[])
{
	int numsInFile[200];
	int i = 0, j, arrayCount = 0, amountOfInteger, sumOFNumbers = 0, meanValue, previousAmount = 0, sumOfNumbers, median, modeValue;

	FILE *fp = fopen(argv[1], "r");
	while(!feof(fp))
	{
		fscanf(fp, "%d", &j);
		if( j < 0 || j > 9)
		{
			fprintf(stderr, "Number %d is out of range\n", j);

		}
		else
		{	
			numsInFile[i] = j;
			i++;
			arrayCount++;
		}
	}
	fclose(fp);

	for (i = 0; i < 10; i++)
	{
		amountOfInteger = 0;
		for (j = 0; j < arrayCount; j++)
		{
			sumOfNumbers = sumOfNumbers + numsInFile[j];
			if (i == numsInFile[j])
			{
				amountOfInteger++;
			}
		}

		if(amountOfInteger > previousAmount)
		{
			previousAmount = amountOfInteger;
			modeValue = i;
		}
		if(amountOfInteger > 70)
		{
			fprintf(stderr, "The lenght of number %d  was too long\n", i);
			return -1;
		}
		
		printf("%d (%d) :", i, amountOfInteger);
		
		for (j = 0; j < amountOfInteger; j++)
		{
			printf("=");
		}
		putchar('\n');
	}
	
	meanValue = sumOfNumbers / arrayCount;
	median = arrayCount / 2;
	if( median & 1)
	{
		printf("The mean is %d, median is %d and the mode is %d\n", meanValue, numsInFile[median], modeValue);
	}
	else
	{
		printf("The mean is %d, median is %d and the mode is %d\n", meanValue, (numsInFile[median] + numsInFile[median - 1]) / 2, modeValue);
	}
}
