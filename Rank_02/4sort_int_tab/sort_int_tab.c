//#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				temp;

	i = 0;
	//size - 1 para comparar el penúltimo con el último
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

// int	main(void)
// {
// 	int	a[6] = {9, 7, 6, 4, 5, 10};
// 	int	i = 0;
// 	int	size = 6;

// 	sort_int_tab(a, size);
// 	while (i < size)
// 		printf("%d\n", a[i++]);
// 	return (0);
// }
