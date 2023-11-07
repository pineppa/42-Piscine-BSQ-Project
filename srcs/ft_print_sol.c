/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:08:48 by jsala             #+#    #+#             */
/*   Updated: 2023/11/07 12:34:55 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_print_sol(int **cached, char *sym, t_coord sizes, t_coord pos_max)
{
	t_coord	p;
	int		i;
	int		val;

	p.r = -1;
	p.c = -1;
	i = 0;
	val = cached[pos_max.r][pos_max.c];
	while (++p.r < sizes.r)
	{
		while (++p.c < sizes.c)
		{
			if (cached[p.r][p.c] == 0)
				ft_putchar(sym[1]);
			else if ((pos_max.r < p.r && p.r < pos_max.r + val)
				&& (pos_max.c < sizes.c && p.c < pos_max.c + val))
				ft_putchar(sym[2]);
			else
				ft_putchar(sym[0]);
		}
		write(1, "\n", 1);
	}
}
