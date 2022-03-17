/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:18:16 by asalvemi          #+#    #+#             */
/*   Updated: 2022/02/24 18:24:17 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_cmd
{
	const char		*cmd[6];
	char *const		*argv;
}					t_cmd;

typedef struct s_pipe
{
	int			argc;
	char const	**av;
	int			status;
	int			index;
	pid_t		pid;
	int			pipefd[2];
	t_cmd		cmd_arg;
}					t_pipe;

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	cmd_init(const char *cmd, t_cmd *strt);
void	connect_pipe(int pipefd[2], int io);

#endif
