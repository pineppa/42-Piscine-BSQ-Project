/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:24:23 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/07 19:36:12 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

//TODO check duplicated chars (check no all values)
int	ft_check_first_line(char *str, char *symbols)
{
	int		i;
	int		size;
	char	*num;

	size = ft_linelen(str);
	i = size - 1;
	while (i > size - 4)
	{
		symbols[i - (size - 3)] = str[i];
		i--;
	}
	i = 0;
	num = (char *)malloc((size - 3 + 1) * sizeof (char));
	if (!num)
		throw_error('A');
	while (size - i > 3)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			throw_error('B');
		num[i] = str[i];
		i++;
	}
	return (ft_atoi(num));
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

int	**ft_check_board(char *file, int lines, char *symbols, t_coord *sizes)
{
	int	**matrix;
	int	line_size;
	int	i;
	int	j;
	int	k;

	matrix = (int **)malloc((lines + 1) * sizeof(int *));
	if (!matrix)
		throw_error('D');
	matrix[lines] = NULL;
	i = 0;
	while (file[i] != '\n')
		i++;
	line_size = ft_linelen(&file[i + 1]);
	sizes->c = line_size;
	j = -1;
	k = line_size;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			if (k != line_size && j > -1)
			{
				throw_error('E');
			}
			j++;
			matrix[j] = (int *)malloc((line_size + 1) * sizeof (int));
			matrix[j][line_size] = -1;
			k = 0;
		}
		else
		{
			matrix[j][k] = ft_get_cell_status(symbols, file[i]);
			k++;
		}
		i++;
	}
	if (j != lines)
		throw_error('H');
	matrix[j] = NULL;
	return (matrix);
}

int	**ft_check_file(char *file, t_coord *sizes, char *symbols)
{
	int	lines;

	lines = ft_check_first_line(file, symbols);
	sizes->r = lines;
	printf("%s, %d\n", symbols, lines);
	return (ft_check_board(file, lines, symbols, sizes));
}
