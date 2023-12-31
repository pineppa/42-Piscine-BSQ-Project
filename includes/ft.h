/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:38:46 by jsala             #+#    #+#             */
/*   Updated: 2023/11/08 16:43:08 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define BUFF_SIZE 8192

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_coord
{
	int	r;
	int	c;
}	t_coord;

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strlen(char *s);
void	throw_error(void);
int		ft_min(int val1, int val2, int val3);
int		ft_atoi(char *str);
char	*ft_strcat(char *s1, char *s2);
char	*ft_read_stdin(void);
char	*ft_file_str(char *file);
int		ft_check_first_line(char *str, char *symbols);
int		**ft_check_file(char *file, t_coord *sizes, char *symbols);
void	ft_print_sol(int **matrix, char *sym, t_coord sizes, t_coord pos_max);
t_coord	ft_get_bsq_pos(int **matrix, t_coord sizes);
int		ft_check_duplicated(char *symbols);
int		ft_linelen(char *str);
int		ft_get_cell_status(char *symbols, char c);
int		ft_check_nlines(int lines, int **matrix);
int		ft_read_symbols(int size, char *str, char *symbols);

#endif
