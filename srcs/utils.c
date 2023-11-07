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