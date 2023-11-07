/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:24:23 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/07 21:09:29 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_first_line(char *str, char *symbols)
{
	int		i;
	int		size;
	char	*num;
	int		value;

	size = ft_linelen(str);
	i = size;
	while (--i > size - 4)
		symbols[i - (size - 3)] = str[i];
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
	value = ft_atoi(num);
	free(num);
	return (value);
}

void	ft_init_write_matrix(int *i, int *j, int *k)
{
	*i = 0;
	*j = -1;
	*k = 0;
}

int	**ft_write_matrix(char *file, int **matrix, char *symbols, t_coord *sizes)
{
	int	line_size;
	int	i;
	int	j;
	int	k;

	ft_init_write_matrix(&i, &j, &k);
	while (file[i] != '\n')
		i++;
	line_size = ft_linelen(&file[i + 1]);
	sizes->c = line_size;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			if (k != line_size && j > -1)
				throw_error('E');
			matrix[++j] = (int *)malloc((line_size + 1) * sizeof (int));
			matrix[j][line_size] = -1;
			k = 0;
		}
		else
			matrix[j][k++] = ft_get_cell_status(symbols, file[i]);
		i++;
	}
	matrix[j] = NULL;
	return (matrix);
}

int	**ft_create_matrix(int lines)
{
	int	**matrix;

	matrix = (int **)malloc((lines + 1) * sizeof(int *));
	if (!matrix)
		throw_error('D');
	matrix[lines] = NULL;
	return (matrix);
}

int	**ft_check_file(char *file, t_coord *sizes, char *symbols)
{
	int	**matrix;
	int	lines;

	lines = ft_check_first_line(file, symbols);
	ft_check_duplicated(symbols);
	sizes->r = lines;
	matrix = ft_create_matrix(lines);
	ft_write_matrix(file, matrix, symbols, sizes);
	ft_check_nlines(lines, matrix);
	return (matrix);
}
