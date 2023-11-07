/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:28 by jsala             #+#    #+#             */
/*   Updated: 2023/11/07 18:05:22 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	char	*file;
	int		**matrix;
	int		i;
	int		j;

	if (argc == 2)
		file = ft_file_str(argv[1]);
	else if (argc == 1)
	{
		//TODO read input
		return (0);
	}
	else
	{
		throw_error('Z');
		return (1);
	}
	matrix = ft_check_file(file);

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j] != -1)
		{
			printf("%d, ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
