/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:14:08 by jsala             #+#    #+#             */
/*   Updated: 2023/11/07 10:49:50 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// File used only to initiate functions and pass test 2D arrays

#include <stdlib.h>
#define N = 5

int	ft_min(int val1, int val2, int val3)
{
	int res;

	if (val1 < 0 || val2 < 0 || val3 < 0)
		return (-1); // Do we need to do this??
	res = val1;
	if (val2 < res)
		res = val2;
	if (val3 < res)
		res = val3
	return (res);
}

void	ft_max_size(int **cache, int row, int col)
{
	cache[r][c] = 1 + ft_min(
			cache[r + 1][c + 1], cache[r + 1][c], cache[r][c + 1]
			);
}

int	ft_check_max_pos(int **cache, int rows, int cols)
{
	r = 0;
	c = 0;
	pos = 0;
	val = 0;

	while (r <= rows)
	{
		while (c <= cols)
		{
			if (cache[r][c] > val)
			{
				pos = r * size + c;
				val = cache[r][c];
			}
			col++;
		}
		row++;
	return (pos); // Return the position as a row * size + col (Possible because it is a square)
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
	pos = ft_check_max_pos(cache, size)
	return (pos);
}

int	main(void)
{
	int	**cached;

	**cached = NULL;
	cached = (int **)malloc(sizeof(int *) * N);
	for (int i = 0, i < N, i++)
	{
		cached[i] = malloc(sizeof(int) * N);
		for (int j = 0, j < N, j++)
			cached[i][j] = 1;
	}
	ft_get_bsq_pos(chached);
//	ft_print_sol();
	for (int i = 0; i < N; i++){
		free(*cached);
	}
	free(cached);
	return (0)
}
