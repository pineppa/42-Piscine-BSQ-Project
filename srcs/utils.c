#include <unistd.h>
#include <stdlib.h>

void    throw_error(void)
{
    write(1, "map error\n", 10);
    exit(1);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

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

int	ft_atoi(char *str)
{
	int	val;
	int	sign;

	val = 0;
	sign = 1;
	if (!*str)
		return (0);
	while ((*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
			|| *str == '\t' || *str == '\v') && *str)
		str++;
	while ((*str == '+' || *str == '-') && *str)
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while ((*str >= '0' && *str <= '9') && *str)
	{
		val = 10 * val + (*str - '0');
		str++;
	}
	return (val * sign);
}
