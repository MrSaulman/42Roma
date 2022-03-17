/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:17:44 by asalvemi          #+#    #+#             */
/*   Updated: 2022/02/24 18:18:58 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/utils.h"

size_t	ft_strlen(char *str)
{
	size_t	leng;

	leng = 0;
	while (*str != '\0')
	{
		str++;
		leng++;
	}
	return (leng);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		count;
	int		count2;
	int		tot_len;
	char	*pt;

	count = -1;
	count2 = 0;
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	tot_len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	pt = (char *)malloc(tot_len + 1);
	if (!pt)
		return (0);
	while (s1[++count] != '\0')
		pt[count] = s1[count];
	while (s2[count2] != '\0')
	{
		pt[count] = s2[count2];
		count2++;
		count++;
	}
	pt[count] = '\0';
	return (pt);
}

void	cmd_init(const char *cmd, t_cmd *strt)
{
	char	**chunk;

	chunk = ft_split(cmd, ' ');
	strt->cmd[0] = ft_strjoin("/bin/", chunk[0]);
	strt->cmd[1] = ft_strjoin("/usr/local/bin/", chunk[0]);
	strt->cmd[2] = ft_strjoin("/usr/bin/", chunk[0]);
	strt->cmd[3] = ft_strjoin("/usr/sbin/", chunk[0]);
	strt->cmd[4] = ft_strjoin("/sbin/", chunk[0]);
	strt->cmd[5] = 0;
	strt->argv = (char *const *)chunk;
}

void	connect_pipe(int pipefd[2], int io)
{
	dup2(pipefd[io], io);
	close(pipefd[0]);
	close(pipefd[1]);
}
