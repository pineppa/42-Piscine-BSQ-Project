/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:14:08 by jsala             #+#    #+#             */
/*   Updated: 2023/11/07 18:44:59 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_max_size(int **cache, t_coord pos)
{
	cache[pos.r][pos.c] = 1 + ft_min(
			cache[pos.r + 1][pos.c + 1],
			cache[pos.r + 1][pos.c],
			cache[pos.r][pos.c + 1]
			);
}

t_coord	ft_check_max_pos(int **cache, t_coord pos_max)
{
	t_coord	p;
	int val;

	p.r = 0;
	val = 0;
	while (p.r <= pos_max.r)
	{
		p.c = 0;
		while (p.c <= pos_max.c)
		{
			if (cache[p.r][p.c] > val)
			{
				pos_max.r = p.r;
				pos_max.c = p.c;
				val = cache[p.r][p.c];
			}
			p.c++;
		}
		p.r++;
	}
	return (p);
}

t_coord	ft_get_bsq_pos(int **matrix, t_coord sizes)
{
	t_coord	p;
	t_coord pos;
	// Assumes that with 1 and 0 the last line
	// and column are already correctly done
	// --> Check cases for 1x1, 2x2, 0x0;
	// if (sizes.r < 1 || sizes.c < 1)
	//	return (p);
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
	pos = ft_check_max_pos(matrix, sizes);
	return (pos);
}
