/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:14:08 by jsala             #+#    #+#             */
/*   Updated: 2023/11/08 15:41:16 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_max_size(int **matrix, t_coord pos)
{
	matrix[pos.r][pos.c] = 1 + ft_min(
			matrix[pos.r + 1][pos.c + 1],
			matrix[pos.r + 1][pos.c],
			matrix[pos.r][pos.c + 1]
			);
}

t_coord	ft_check_max_pos(int **matrix, t_coord sizes)
{
	t_coord	p;
	t_coord	pos_max;
	int		max_val;

	pos_max.r = 0;
	pos_max.c = 0;
	p.r = 0;
	max_val = 0;
	while (p.r < sizes.r)
	{
		p.c = 0;
		while (p.c < sizes.c)
		{
			if (matrix[p.r][p.c] > max_val)
			{
				pos_max.r = p.r;
				pos_max.c = p.c;
				max_val = matrix[p.r][p.c];
			}
			p.c++;
		}
		p.r++;
	}
	return (pos_max);
}

t_coord	ft_get_bsq_pos(int **matrix, t_coord sizes)
{
	t_coord	p;
	t_coord	pos_max;

	p.r = sizes.r - 2;
	while (p.r >= 0)
	{
		p.c = sizes.c - 2;
		while (p.c >= 0)
		{
			if (matrix[p.r][p.c] != 0)
				ft_max_size(matrix, p);
			p.c--;
		}
		p.r--;
	}
	pos_max = ft_check_max_pos(matrix, sizes);
	return (pos_max);
}
