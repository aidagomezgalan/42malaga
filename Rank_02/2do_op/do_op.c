#include <stdio.h>
#include <stdlib.h>

void	do_op(char *s1, char operator, char *s2)
{
	int	result;

	if (operator == '+')
		result = atoi(s1) + atoi(s2);
	else if (operator == '-')
		result = atoi(s1) - atoi(s2);
	else if (operator == '*')
		result = atoi(s1) * atoi(s2);
	else if (operator == '/')
		result = atoi(s1) / atoi(s2);
	else if (operator == '%')
		result = atoi(s1) % atoi(s2);
	printf("%i", result);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		do_op(argv[1], argv[2], argv[3]);
	printf("\n");
}
