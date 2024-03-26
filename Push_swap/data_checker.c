/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:13:38 by aidgomez          #+#    #+#             */
/*   Updated: 2024/02/04 14:20:42 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char *str)
{
	int		i;
	int		length;
	long	num;

	i = 0;
	length = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		length++;
		i++;
	}
	if (length == 0 || (length > 10 && str[0] != '-' && str[0] != '+'))
		return (0);
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	is_duplicated(char **nums)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nums[i])
	{
		while (nums[j])
		{
			if (i != j && ft_atoi(nums[i]) == ft_atoi(nums[j]))
			{
				return (1);
			}
			else
				j++;
		}
		j = 1;
		i++;
	}
	return (0);
}

int	is_sorted(char **nums)
{
	int	i;

	i = 0;
	while (nums[i] && nums[i + 1])
	{
		if (ft_atoi(nums[i]) >= ft_atoi(nums[i + 1]))
			return (0);
		else
			i++;
	}
	return (1);
}

char	**str_split(char **argv)
{
	int		i;
	char	**nums;
	char	*temp;

	i = 1;
	temp = ft_strdup(argv[i]);
	while (argv[i] && argv[i + 1])
	{
		temp = ft_strjoin_free(temp, " ");
		temp = ft_strjoin_free(temp, argv[i + 1]);
		i++;
	}
	nums = ft_split(temp, ' ');
	free(temp);
	return (nums);
}

int	data_checker(char **nums)
{
	int		i;

	i = 0;
	if (nums[i] == NULL)
		return (0);
	while (nums[i])
	{
		if (!is_int(nums[i]))
			return (0);
		i++;
	}
	if (is_sorted(nums))
	{
		memory_str_free(nums);
		exit(EXIT_FAILURE);
	}
	if (is_duplicated(nums))
		return (0);
	return (1);
}
