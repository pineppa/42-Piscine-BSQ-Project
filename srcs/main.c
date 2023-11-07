/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:28 by jsala             #+#    #+#             */
/*   Updated: 2023/11/07 22:27:21 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void exec_solver(char *file)
{
	t_coord	sizes;
	t_coord	pos_max;
	int		**matrix;
	char	symbols[4];

	symbols[3] = '\0';
	matrix = ft_check_file(file, &sizes, symbols);
	free(file);
	pos_max = ft_get_bsq_pos(matrix, sizes);
/*
	i = 0;
	while(i < sizes.r)
	{
		j = 0;
		while (j < sizes.c)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	*/
	ft_print_sol(matrix, symbols, sizes, pos_max);
	//free_matrix(matrix); // ToDo: create function
}

int	main(int argc, char **argv)
{
	char	*file;
	int		i;
//	int		j;

	if (argc == 1)
	{
		file = ft_read_stdin();
		printf("%s", file);
		exec_solver(file);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		file = ft_file_str(argv[i]);
		exec_solver(file);
		i++;
	}
	return (0);
}
