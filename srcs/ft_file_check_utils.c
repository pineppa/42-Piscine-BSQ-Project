/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:15:43 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/08 12:18:54 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_duplicated(char *symbols)
{
	int	i;
	int	j;

	i = 0;
	while (symbols[i])
	{
		j = i + 1;
		while (symbols[j])
		{
			if (symbols[i] == symbols[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

int	ft_get_cell_status(char *symbols, char c)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (symbols[i] == c)
			break ;
		i++;
	}
	if (i == 0)
		return (1);
	else if (i == 1)
		return (0);
	return (-1);
}

int	ft_check_nlines(int lines, int **matrix)
{
	int	count;

	count = 0;
	while (matrix[count])
		count++;
	if (count != lines)
		return (1);
	return (0);
}
