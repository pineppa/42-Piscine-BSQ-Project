char	*ft_file_str(char *str);
void	ft_check_file(char *file);

int	main(int argc, char **argv)
{
	char	*file;

	if (argc == 2)
		file = ft_file_str(argv[1]);
	//TODO read input
	else
		file = 0;

	ft_check_file(file);
}