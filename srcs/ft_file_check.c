/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:24:23 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/08 11:39:07 by molasz-a         ###   ########.fr       */
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
	while (--i > size - 4 && str[i])
	{
		if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
			return (-1);
		symbols[i - (size - 3)] = str[i];
	}
	num = (char *)malloc((size - 3 + 1) * sizeof (char));
	if (!num)
		return (-1);
	i = 0;
	while (size - i > 3 && str[i])
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

int	ft_init_write_matrix(int *i, int *j, int *k, char *file)
{
	*i = 0;
	*j = -1;
	*k = 0;
	while (file[*i] != '\n' && file[*i])
		*i += 1;
	return (ft_linelen(&file[*i + 1]));
}

int	ft_write_matrix(char *file, int **matrix, char *symbols, t_coord *sizes)
{
	int	line_size;
	int	i;
	int	j;
	int	k;

	line_size = ft_init_write_matrix(&i, &j, &k, file);
	sizes->c = line_size;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			if (k != line_size && j > -1)
				return (1);
			matrix[++j] = (int *)malloc((line_size + 1) * sizeof (int));
			if (!matrix[j])
				return (1);
			matrix[j][line_size] = -1;
			k = 0;
		}
		else
		{
			matrix[j][k] = ft_get_cell_status(symbols, file[i]);
			if (matrix[j][k] < 0)
				return (1);
			k++;
		}
		i++;
	}
	matrix[j] = NULL;
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

	lines = ft_check_first_line(file, symbols);
	if (ft_check_duplicated(symbols))
		return (NULL);
	sizes->r = lines;
	matrix = ft_create_matrix(lines);
	if (!matrix)
		return (NULL);
	if (ft_write_matrix(file, matrix, symbols, sizes))
		return (NULL);
	if (ft_check_nlines(lines, matrix))
		return (NULL);
	return (matrix);
}
