/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:08:48 by jsala             #+#    #+#             */
/*   Updated: 2023/11/07 12:16:01 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void    ft_print_sol(int **cached, char *symbols, t_coord sizes, t_coord pos_max)
{
	t_coord p;
	int i;

	p.r = -1;
	p.c = -1;
	i = 0;
	while (++p.r < sizes.r)
	{
		while (++p.c < sizes.c)
		{
			if (cached[p.r][p.c] == 0)
				ft_putchar(symbols[1]);
			else if ((pos_max.r < p.r && p.r < pos.r + val) 
					&& (pos_max.c < sizes.c && p.c < pos.c + val))
				ft_putchar(symbols[2]);
			else
				ft_putchar(symbols[0]);
		}
		write(1, "\n", 1);
	}
}