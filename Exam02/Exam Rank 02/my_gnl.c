/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:41:38 by ffrau             #+#    #+#             */
/*   Updated: 2022/02/22 17:15:29 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFFER_SIZE 5

char	*get_next_line(int fd)
{
	char storage[999999];
	char *malloc_storage;
	char buffer[1];
	int i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	i = 0;
	storage[i] = 0;
	// On success, read returns the number of bytes (zero indicates end of file)
	while (read(fd, buffer, 1) == 1)
	{
		storage[i] = buffer[0];
		storage[i + 1] = '\0';
		if (storage[i] == '\n')
			break;
		i++;
	}
	if (!storage[0])
		return (NULL);
	malloc_storage = malloc(i + 1);
	if (!malloc_storage)
		return (NULL);
	i = 0;
	while (storage[i])
	{
		malloc_storage[i] = storage[i];
		i++;
	}
	malloc_storage[i] = '\0';
	return (malloc_storage);
}

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
