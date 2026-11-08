/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "parser.h"
# include "shell.h"
# include <sys/types.h>

/*executor.c*/
int		execute_pipeline(t_cmd *pipeline, t_shell *shell);

/*executor_single.c*/
int		execute_single(t_cmd *cmd, t_shell *shell);

/*executor_multi.c*/
int		execute_multi(t_cmd *pipeline, t_shell *shell);
int		count_cmds(t_cmd *pipeline);

/*executor_child.c*/
void	run_child(t_cmd *cmd, t_shell *shell, int *fds);

/*executor_redir.c*/
int		apply_redirs(t_cmd *cmd);

/*executor_heredoc.c*/
int		run_heredocs(t_cmd *pipeline, t_shell *shell);

/*executor_heredoc_read.c*/
char	*read_heredoc_line(void);

/*executor_path.c*/
char	*find_executable(char *name, t_env *env);

/*executor_builtin.c*/
int		is_builtin(char *name);
int		run_builtin(t_cmd *cmd, t_shell *shell);

/*executor_wait.c*/
pid_t	fork_one(t_cmd *cmd, t_shell *shell, int *fds);
int		wait_children(pid_t *pids, int count);

#endif
