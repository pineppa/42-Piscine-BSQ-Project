#ifndef FT_H
# define FT_H

# define BUFF_SIZE 8192

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_coord
{
	int r;
	int c;
}	t_coord;

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strlen(char *s);
void	throw_error(char c);
int		ft_min(int val1, int val2, int val3);
int		ft_atoi(char *str);
char	*ft_strcat(char *s1, char *s2);
char	*ft_read_stdin(void);
char	*ft_file_str(char *file);
int		ft_check_first_line(char *str, char *symbols);
int		**ft_check_file(char *file, t_coord *sizes, char *symbols);
void	ft_print_sol(int **matrix, char *sym, t_coord sizes, t_coord pos_max);
t_coord	ft_get_bsq_pos(int **matrix, t_coord sizes);

#endif
