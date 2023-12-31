/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:09:47 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/08 15:31:36 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	file_size(char *file)
{
	int		f;
	int		count;
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

char	*ft_strcat(char *dest, char *src)
{
	char	*cat_str;
	int		i;
	int		j;

	cat_str = malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 1));
	if (cat_str == NULL)
		return (NULL);
	i = 0;
	while (dest[i])
	{
		cat_str[i] = dest[i];
		i++;
	}
	free(dest);
	j = 0;
	while (src[j])
	{
		cat_str[i + j] = src[j];
		j++;
	}
	cat_str[i + j] = '\0';
	return (cat_str);
}

char	*ft_read_stdin(void)
{
	char	buff;
	char	*map;
	int		buf_is_empty;

	buff = 'p';
	map = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!map || !buff)
		return (NULL);
	buf_is_empty = 1;
	while (read(STDIN_FILENO, &buff, 1) != 0)
	{
		buf_is_empty = 0;
		map = ft_strcat(map, &buff);
	}
	if (buf_is_empty)
		return (NULL);
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
	if (close(f) < 0)
		return (1);
	return (0);
}

char	*ft_file_str(char *file)
{
	char	*str;
	int		size;

	size = file_size(file);
	if (size < 1)
		return (NULL);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (file_read(file, str))
		return (NULL);
	return (str);
}
