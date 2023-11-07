/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:09:47 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/07 15:49:54 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/ft.h"

void    throw_error(void);

int	file_size(char *file)
{
	int 	f;
	int 	count;
	char	c;

	count = 0;
	f = open(file, O_RDONLY);
	if (f < 0)
		return (-1);
	while (read(f, &c, 1))
		count++;
	if (close(f) < 0)
		return (-1);
	return (count);
}

char	*ft_read_stdin(void)
{
	char	*buff;
	int		size;
	char	*map;
	int		buf_is_empty;

	buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	size = 1;
	buf_is_empty = 1;
	while (size != 0)
	{
		buf_is_empty = 0;
		size = read(STDIN_FILENO, buff, BUFF_SIZE);
		buff[size] = '\0';
		ft_strcat(map, buff);
	}
	if (buf_is_empty)
		throw_error();
	return (map);
}

int	file_read(char *file, char *str)
{
	int		f;
	int		i;
	char	c;

	f = open(file, O_RDONLY);
	if (f < 0)
		return (1);
	i = 0;
	while (read(f, &c, 1))
		str[i++] = c;
	return (0);
}

char *ft_file_str(char *file)
{
	char	*str;
	int		size;

	size = file_size(file);
	if (size < 1)
		throw_error();
	str = (char *)malloc((size + 1) * sizeof(char));
	str[size] = '\0';
	if (file_read(file, str))
		throw_error();
	return (str);
}
