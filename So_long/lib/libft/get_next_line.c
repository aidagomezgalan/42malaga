/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:19:10 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/05 19:19:10 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*read(fichero, puntero al buffer de transferencia, n bytes a transferir)
Valor devuelto: nº bytes leídos
*/

#include "libft.h"

char	*ft_new_buffer(char *buffer1, char *buffer2)
{
	char	*buffer;

	buffer = ft_strjoin(buffer1, buffer2);
	free(buffer1);
	return (buffer);
}

char	*ft_buffer_read(int fd, char *buffer)
{
	char	*temp_buffer;
	int		bytes_read;

	bytes_read = 1;
	temp_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(temp_buffer);
			return (NULL);
		}
		temp_buffer[bytes_read] = '\0';
		buffer = ft_new_buffer(buffer, temp_buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(temp_buffer);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = (char *)malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*buffer = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_buffer_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line (buffer);
	buffer = ft_update_buffer(buffer);
	return (line);
}
