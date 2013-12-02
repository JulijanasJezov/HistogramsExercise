#include<stdio.h>

int main(int argc, char *argv[])
{
	int c, j, i, x = 'a';
	char array1[25];		//letters stored here
	int array2[25];			//counter stored here
	int max = 0;

	for(i = 0 ; i < 26; i++)
	{
		array1[i] = x;
		x++;
	}
	for(i = 0 ; i < 26; i++)
	{
		array2[i] = 0;
	}
	
	FILE *fp = fopen(argv[1], "r");
	while((c = fgetc(fp)) != -1)
	{	
		c = tolower(c);
		for( i = 0 ; i < 26; i++)
		{
			if(c == array1[i])
			{
				array2[i]++;
			}
		}
	}
	fclose(fp);
	for(i = 0 ; i < 26; i++)
	{
		if(array2[i] != 0)
		{
			printf("The Letter '%c' occurs %d times.\n", array1[i], array2[i]);
		}
	}
	for(i = 0 ; i < 26; i++)
	{
		if(array2[i] > max)
		{
			max = array2[i];
		}
	}
	if(max >= 10)
	{
		max = 10;
	}

	putchar('\n');
	i = 10;
	while (i != -1)
	{
	printf("%d", i);
		if (i == 10)
		{
			for (j=0; j<26; j++)
                {
                        if (array2[j] > i)
                        {
                                printf("+");
                        }
                        else
                        {
                                printf(" ");
                        }
                }


		}
		if (i!=10)
		{
		putchar(' ');
		for (j=0; j<26; j++)
		{
			if (array2[j] > i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		}
		
		if ( i != 10)
		{
		putchar('\n');
		printf("%d", i);
		putchar(' ');
		for (j=0; j<26;j++)
		{
			if (array2[j] >= i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}

		}
		}
		putchar('\n');

		i = i -1;
	}

	
	printf("\n  abcdefghijklmnopqrstuvwxyz\n");
	putchar('\n');	
}
