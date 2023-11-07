/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:24:23 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/07 12:47:12 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	throw_error();

int ft_linelen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

//TODO check duplicated chars (check no all values)
int ft_check_first_line(char *str, char *symbols)
{
	int		i;
	int		size;
	char	*num;

	size = ft_check_file(str);
	i = size - 1;
	while (i > (3 - (size - i)))
	{
		symbols[3 - (size - i)] = str[i];
		i++;
	}
	i = 0;
	num = (char *)malloc((size - 3 + 1) * sizeof (char));
	if (!num)
		throw_error();
	while (size - i > 3)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			throw_error();
		num[i] = str[i];
		i++;
	}
	return (ft_atoi(num));
}

int	ft_get_cell_status(char *symbols, char c)
{
	int i;
	int result;

	i = 0;
	while (symbols[i])
	{
		if (symbols[i] == c)
			break;
		i++;
	}
	if (i < 2)
		return (i);
	throw_error();
}

void	ft_check_board(char *file, int lines, char *symbols)
{
	int	**matrix;
	int	line_size;
	int	i;
	int	j;
	int	k;

	matrix = (int **)malloc((lines + 1) * sizeof(int *));
	if(!matrix)
		throw_error();
	matrix[lines] = 0;

	i = 0;
	while(file[i] != '\n')
		i++;
	line_size = ft_linelen(&file[i]);

	j = -1;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			if (k != line_size)
				throw_error();
			j++;
			matrix[j] = (int *)malloc((line_size) * sizeof (int));
			k = 0;
		}
		else
		{
			matrix[j][k] = ft_get_cell_status(symbols, file[i]);
		}
	}
}

ft_check_file(char *file)
{
	char	symbols[3];
	int		lines;

	lines = ft_check_first_line(file, symbols);
	ft_check_board(file, lines, symbols);
}
