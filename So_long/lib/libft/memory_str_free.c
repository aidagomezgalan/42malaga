/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_str_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:29:23 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/29 20:19:41 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	memory_str_free(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}
