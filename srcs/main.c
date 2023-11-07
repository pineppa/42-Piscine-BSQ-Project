/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:28 by jsala             #+#    #+#             */
/*   Updated: 2023/11/07 18:55:25 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	char	*file;
	int		**matrix;
	t_coord	sizes;
	t_coord pos_max;
	int	i;
	int j;

	if (argc == 2)
		file = ft_file_str(argv[1]);
	else if (argc == 1)
		file = ft_read_stdin();
	else
	{
		throw_error('Z');
		return (1);
	}
	matrix = ft_check_file(file, &sizes);
	pos_max = ft_get_bsq_pos(matrix, sizes);
	printf("%d, %d \n", pos_max.r, pos_max.c);
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
	ft_print_sol(matrix, ".xo", sizes, pos_max); //ft_print_sol(matrix, symbols, sizes, pos_max)
	return (0);
}
