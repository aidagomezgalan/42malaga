#include "list.h"

void	swap_values(t_list *a, t_list *b)
{
	int	swap;

	swap = a->data;
	a->data = b->data;
	b->data = swap;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		swapped = 1;
	t_list	*tmp = lst;

	while (swapped == 1)
	{
		swapped = 0;
		while (tmp != 0 && tmp->next != 0)
		{
			//Si el primero no es menor o igual (según la función ascending del main)
			//se intercambian para ordenar de manera ascendente
			if (cmp(tmp->data, tmp->next->data) == 0)
			{
				swap_values(tmp, tmp->next);
				swapped = 1;
			}
			tmp = tmp->next;
		}
		tmp = lst;
	}
	return (lst);
}
