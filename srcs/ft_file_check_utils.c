/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:15:43 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/07 20:24:57 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_check_duplicated(char *symbols)
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
				throw_error('U');
			j++;
		}
		i++;
	}
}

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	ft_get_cell_status(char *symbols, char c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (symbols[i] == c)
			break ;
		i++;
	}
	if (i == 0)
		return (1);
	else if (i == 1)
		return (0);
	throw_error('C');
	return (-1);
}

void	ft_check_nlines(int lines, int **matrix)
{
	int	count;

	count = 0;
	while (matrix[count])
		count++;
	if (count != lines)
		throw_error('A');
}
