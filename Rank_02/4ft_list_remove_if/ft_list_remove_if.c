#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*node;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	node = *begin_list;
	if (cmp(data_ref, node->data) == 0)
	{
		*begin_list = node->next;
		free(node);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	node = *begin_list;
	ft_list_remove_if(&node->next, data_ref, cmp);
}
