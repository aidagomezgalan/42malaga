/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_to_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:25:25 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/29 19:18:50 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**fd_to_array(char *str)
{
	int		fd;
	char	**astr;
	char	*line;
	char	*temp;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	temp = NULL;
	while (line)
	{
		temp = ft_strjoin_free(temp, line);
		free(line);
		line = get_next_line(fd);
	}
	astr = ft_split(temp, '\n');
	free(temp);
	close(fd);
	if (!astr)
		return (NULL);
	return (astr);
}
