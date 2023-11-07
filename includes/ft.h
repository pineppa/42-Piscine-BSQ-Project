#ifndef BSQ
# define BSQ

# define BUFF_SIZE 8192

int		ft_atoi(char *str);
void	ft_putchar(char c);
char	*ft_strcat(char *s1, char *s2);

typedef struct	s_coord
{
	int r;
	int c;
}	t_coord;

#endif
