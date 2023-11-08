/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:24:23 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/08 16:52:38 by molasz-a         ###   ########.fr       */
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
	if (ft_read_symbols(size, str, symbols))
		return (-1);
	num = (char *)malloc((size - 3 + 1) * sizeof (char));
	if (!num)
		return (-1);
	num[size - 3] = '\0';
	i = 0;
	while (i < size - 3 && str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		num[i] = str[i];
		i++;
	}
	value = ft_atoi(num);
	free(num);
	return (value);
}

int	ft_write_line(int *counts, char *symbols, int **matrix, t_coord *sizes)
{
	if (counts[3] == '\n')
	{
		if (counts[2] != sizes->c && counts[1] > -1)
			return (1);
		matrix[++counts[1]] = (int *)malloc((sizes->c + 1) * sizeof (int));
		if (!matrix[counts[1]])
			return (1);
		matrix[counts[1]][sizes->c] = -1;
		counts[2] = 0;
	}
	else
	{
		matrix[counts[1]][counts[2]] = ft_get_cell_status(symbols, counts[3]);
		if (matrix[counts[1]][counts[2]] < 0)
			return (1);
		counts[2]++;
	}
	return (0);
}

int	ft_write_matrix(char *file, int **matrix, char *symbols, t_coord *sizes)
{
	int	counts[4];

	counts[0] = 0;
	counts[1] = -1;
	counts[2] = 0;
	counts[3] = 0;
	while (file[counts[0]] != '\n' && file[counts[0]])
		counts[0]++;
	sizes->c = ft_linelen(&file[counts[0] + 1]);
	if (sizes->c < 1)
		return (1);
	while (file[counts[0]])
	{
		if (counts[1] > sizes->r - 1)
			return (1);
		counts[3] = file[counts[0]];
		if (ft_write_line(counts, symbols, matrix, sizes))
			return (1);
		counts[0]++;
	}
	if (counts[1] < sizes->r)
		return (1);
	return (0);
}

int	**ft_create_matrix(int lines)
{
	int	**matrix;

	matrix = (int **)malloc((lines + 1) * sizeof(int *));
	if (!matrix)
		return (NULL);
	matrix[lines] = NULL;
	return (matrix);
}

int	**ft_check_file(char *file, t_coord *sizes, char *symbols)
{
	int	**matrix;
	int	lines;

	if (ft_strlen(file) <= 5)
		return (NULL);
	lines = ft_check_first_line(file, symbols);
	if (ft_check_duplicated(symbols))
		return (NULL);
	sizes->r = lines;
	matrix = ft_create_matrix(lines);
	if (!matrix)
		return (NULL);
	if (ft_write_matrix(file, matrix, symbols, sizes))
		return (NULL);
	return (matrix);
}
