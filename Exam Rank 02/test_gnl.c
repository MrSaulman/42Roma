

int main(int ac, char **av){
	//Thx to mprigent for the main
	int		fd;
	char	*line;
	(void)ac;

	fd = open(av[1], O_RDONLY);
    while ((line = get_next_line(fd)) != 0)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	// system("leaks gnl");
	return (0);
}
