/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:24:23 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/08 12:14:37 by jsala            ###   ########.fr       */
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
	int	i;
	int	j;
	int	k;

	sizes->c = ft_init_write_matrix(&i, &j, &k, file);
	while (file[i] && j < sizes->r)
	{
		if (file[i] == '\n')
		{
			if (k != sizes->c && j > -1)
				return (-1);
			matrix[++j] = (int *)malloc((sizes->c + 1) * sizeof (int));
			if (!matrix[j])
				return (-1);
			matrix[j][sizes->c] = -1;
			k = 0;
		}
		else
		{
			matrix[j][k] = ft_get_cell_status(symbols, file[i]);
			if (matrix[j][k] < 0)
				return (-1);
			k++;
		}
		i++;
	}
	return (j);
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
	int count_lines;

	lines = ft_check_first_line(file, symbols);
	if (ft_check_duplicated(symbols))
		return (NULL);
	sizes->r = lines;
	matrix = ft_create_matrix(lines);
	if (!matrix)
		return (NULL);
	count_lines = ft_write_matrix(file, matrix, symbols, sizes);
	if (count_lines < 0 || count_lines != lines)
		return (NULL);
	return (matrix);
}
