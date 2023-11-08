/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:08:48 by jsala             #+#    #+#             */
/*   Updated: 2023/11/08 10:52:01 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_print_sol(int **matrix, char *sym, t_coord sizes, t_coord pos_max)
{
	t_coord	p;
	int		i;
	int		max_val;

	p.r = -1;
	i = 0;
	max_val = matrix[pos_max.r][pos_max.c];
	while (++p.r < sizes.r)
	{
		p.c = -1;
		while (++p.c < sizes.c)
		{
			if (matrix[p.r][p.c] == 0)
				ft_putchar(sym[1]);
			else if ((pos_max.r <= p.r && p.r < pos_max.r + max_val)
				&& (pos_max.c <= p.c && p.c < pos_max.c + max_val))
				ft_putchar(sym[2]);
			else
				ft_putchar(sym[0]);
		}
		write(1, "\n", 1);
	}
}
