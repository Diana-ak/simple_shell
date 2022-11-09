#include <stdio.h>
#include <stdlib.h>
/**
 * main- Entry Level
 * Description: This function handles commandline with arguments
 * @argv: a char pinter to an array
 * @argc: array elements count\
 * Return: returns 0 (Always success)
 */

int main(int argc, char *argv[])
{
	int i;


	printf("The number of argumenst inserted is %d and they include:", argc);
	if (argc > 1)
	{
		for (i = 0; i <= argc; i++)
		{
			printf("%s\n", argv[i]);
		}
	} else
	{
		printf("%s\n", argv[0]);
	}
	return (0);
}
