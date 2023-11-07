/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:09:47 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/07 11:26:22 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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
