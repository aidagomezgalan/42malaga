//#include <stdio.h>
#include <stdlib.h>

int	nbr_size(int start, int end)
{
	int	size;

	if (end < 0)
		size = ((end - start) * -1) + 1;
	else
		size = (end - start) + 1;
	return (size);
}

int	*ft_rrange(int start, int end)
{
	int	*numbers;
	int	i;

	i = 0;
	numbers = (int *)malloc(sizeof(int) * nbr_size(start, end));
	if (numbers)
	{
		while (start != end)
		{
			numbers[i] = end;
			if (start > end)
				end++;
			else
				end--;
			i++;
		}
	}
	numbers[i] = end;
	return (numbers);
}

// int	main(void)
// {
// 	int	i = 0;
// 	int	n1 = 0;
// 	int	n2 = -2;
// 	int	*numbers = ft_rrange(n1, n2);

// 	while (i < nbr_size(n1, n2))
// 		printf("%d ", numbers[i++]);
// 	printf("\n");
// 	return (0);
// }
