/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:14:08 by jsala             #+#    #+#             */
/*   Updated: 2023/11/07 12:47:49 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// File used only to initiate functions and pass test 2D arrays

#include <stdlib.h>
#include "../includes/ft.h"

int	ft_min(int val1, int val2, int val3)
{
	int res;

	if (val1 < 0 || val2 < 0 || val3 < 0)
		return (-1); // Do we need to do this??
	res = val1;
	if (val2 < res)
		res = val2;
	if (val3 < res)
		res = val3;
	return (res);
}

void	ft_max_size(int **cache, t_coord pos)
{
	cache[pos.r][pos.c] = 1 + ft_min(
			cache[pos.r + 1][pos.c + 1],
			cache[pos.r + 1][pos.c],
			cache[pos.r][pos.c + 1]
			);
}

int	ft_check_max_pos(int **cache, t_coord pos_max)
{
	int r;
	int	c;
	t_coord	pos;
	int val;

	r = 0;
	c = 0;
	val = 0;

	while (r <= pos_max.r)
	{
		while (c <= pos_max.c)
		{
			if (cache[pos.r][pos.c] > val)
			{
				pos.r = r
				pos.c = c;
				val = cache[pos.r][pos.c];
			}
			c++;
		}
		r++;
	return (pos);
}

int ft_get_bsq_pos(int **cache, int rows, int cols)
{
	int	r;
	int	c;
	// Assumes that with 1 and 0 the last line
	// and column are already correctly done
	// --> Check cases for 1x1, 2x2, 0x0;
	if (rows < 1 || cols < 1)
		return (-1);
	r = rows - 2;
	c = cols - 2;
	while (r >= 0)
	{
		while (c >= 0)
		{
			if (cache[r][c] != 0)
				ft_max_size(cache, r, c);
			col--;
		}
		row--;
	}
	pos = ft_check_max_pos(cache, size);
	return (pos);
}
