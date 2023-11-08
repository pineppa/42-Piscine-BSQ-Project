/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:28 by jsala             #+#    #+#             */
/*   Updated: 2023/11/08 17:09:34 by jsala            ###   ########.fr       */
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
	matrix = ft_check_file(file, &sizes, symbols);
	if (!matrix)
		return (1);
	pos_max = ft_get_bsq_pos(matrix, sizes);
	ft_print_sol(matrix, symbols, sizes, pos_max);
	free_matrix(matrix, sizes.r);
	return (0);
}

void	ft_resolve_files(int argc, char **argv)
{
	int		i;
	char	*file;

	i = 1;
	while (i < argc)
	{
		file = ft_file_str(argv[i]);
		if (!file)
			throw_error();
		else
		{
			if (exec_solver(file))
				throw_error();
			free(file);
		}
		i++;
		if (argc != 2)
			ft_putchar('\n');
	}
}

int	main(int argc, char **argv)
{
	char	*file;

	if (argc == 1)
	{
		file = ft_read_stdin();
		if (!file)
		{
			throw_error();
			return (0);
		}
		ft_putchar('\n');
		if (exec_solver(file))
			throw_error();
		return (0);
	}
	else
		ft_resolve_files(argc, argv);
	return (0);
}
