/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:17:38 by asalvemi          #+#    #+#             */
/*   Updated: 2022/02/24 18:23:34 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../include/utils.h"

int	redirect_in(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	redirect_out(const char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static void	run_cmd(const char *cmd, t_cmd *cmd_arg, char *envp[])
{
	int	i;

	i = 0;
	cmd_init(cmd, cmd_arg);
	while (i < 5)
	{
		execve(cmd_arg->cmd[i++], cmd_arg->argv, envp);
	}
	perror(cmd_arg->argv[0]);
	exit(1);
}

int	run_child(t_pipe *pipe_vars, char *envp[])
{
	connect_pipe(pipe_vars->pipefd, STDOUT_FILENO);
	redirect_in(pipe_vars->av[pipe_vars->index - 1]);
	run_cmd(pipe_vars->av[pipe_vars->index], &pipe_vars->cmd_arg, envp);
	return (1);
}

int	main(int argc, char const *argv[], char *envp[])
{
	t_pipe	pipe_vars;

	pipe_vars.argc = argc;
	pipe_vars.av = argv;
	pipe_vars.index = argc - 3;
	if (argc != 5)
		return (0);
	if (pipe(pipe_vars.pipefd) == -1)
		exit(1);
	pipe_vars.pid = fork();
	if (pipe_vars.pid < 0)
		exit(1);
	if (pipe_vars.pid > 0)
	{
		waitpid(pipe_vars.pid, &pipe_vars.status, 0);
		if (WIFEXITED(pipe_vars.status) == 0)
			exit(1);
		redirect_out(argv[argc - 1]);
		connect_pipe(pipe_vars.pipefd, STDIN_FILENO);
		run_cmd(argv[argc - 2], &pipe_vars.cmd_arg, envp);
	}
	else if (pipe_vars.pid == 0)
		run_child(&pipe_vars, envp);
	return (0);
}
