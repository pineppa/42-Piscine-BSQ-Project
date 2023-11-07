/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:08:48 by jsala             #+#    #+#             */
/*   Updated: 2023/11/07 11:50:18 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_print_sol(int **cached, char *symbols, int rows, int cols, t_point pos)
{
	int r;
	int c;
	int i;

	r = -1;
	c = -1;
	i = 0;
	while (++r < rows)
	{
		while (++c < cols)
		{
			if (cached[r][c] == 0)
				ft_putchar(symbols[1]);
			else if ((pos.x < r && r < pos.x + val) && (pos.y < c && c < pos.y + val))
				ft_putchar(symbols[2]);
			else
				ft_putchar(symbols[0]);
		}
		write(1, "\n", 1);
	}
}