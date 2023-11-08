/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:28 by jsala             #+#    #+#             */
/*   Updated: 2023/11/08 12:22:10 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	free_matrix(int **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		i++;
	}
}

int	exec_solver(char *file)
{
	t_coord	sizes;
	t_coord	pos_max;
	int		**matrix;
	char	symbols[4];

	symbols[3] = '\0';
	sizes.r = 0;
	sizes.c = 0;
	matrix = ft_check_file(file, &sizes, symbols); //Print matrix if not error
	if (!matrix)
		return (1);
	pos_max = ft_get_bsq_pos(matrix, sizes);
	ft_print_sol(matrix, symbols, sizes, pos_max);
	free_matrix(matrix, sizes.r);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*file;
	int		i;

	if (argc == 1)
	{
		file = ft_read_stdin();
		ft_putchar('\n');
		if (exec_solver(file))
				throw_error('S');
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		file = ft_file_str(argv[i]);
		if (!file)
			throw_error('F');
		else
		{
			if (exec_solver(file))
				throw_error('S');
			free(file);
		}
		i++;
		if (i != argc)
			ft_putchar('\n');
	}
	return (0);
}
