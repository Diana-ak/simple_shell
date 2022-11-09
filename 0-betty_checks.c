#include <stdio.h>
#include <stdlib.h>

/**
 * main- Entry Level
 * Description: Sum up two operands from commandline
 * @ergv: a char piointer to array containing two operands
 * @argc: a count on the number of operands in array
 * Return: reeturns sum of the two operands  or error
 */

int main(int argc, char *argv[])
{
	int sum;

	if (argc <= 1)
		perror("No Operands");
	sum = atoi(argv[1]) + atoi(argv[2]);
	printf("%d\n", sum);
	return (sum);
}
