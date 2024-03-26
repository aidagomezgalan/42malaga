#include <stdio.h>
#include <stdlib.h>

void	fprime(char *str)
{
	int	n = atoi(str);
	int	factor = 2;
	//Controlar la impresión del primer factor
	int	first = 1;

	if (n == 1)
		printf("1");
	while (factor <= n)
	{
		if (n % factor == 0)
		{
			if (first == 1)
				printf("%d", factor);
			else
				printf("*%d", factor);
			first = 0;
			n /= factor;
		}
		else
			factor++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fprime(argv[1]);
	printf("\n");
	return (0);
}
