//#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int	i;
	int	max_nbr;

	i = 1;
	max_nbr = tab[0];
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (tab[i] > max_nbr)
			max_nbr = tab[i];
		i++;
	}
	return (max_nbr);
}

// int main()
// {
// 	int nbrs[] = {-2, 43, 123, 0, 444, 12, 1};
// 	printf("%d\n", max(nbrs, 7));
// 	return (0);
// }
