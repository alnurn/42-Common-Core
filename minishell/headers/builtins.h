/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:56:28 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "env.h"
# include "shell.h"

/*builtin_echo.c*/
int		builtin_echo(char **args);

/*builtin_pwd.c*/
int		builtin_pwd(void);

/*builtin_cd.c*/
int		builtin_cd(char **args, t_shell *shell);

/*builtin_env.c*/
int		builtin_env(char **args, t_shell *shell);

/*builtin_export.c*/
int		builtin_export(char **args, t_shell *shell);

/*builtin_export_utils.c*/
int		is_valid_identifier(char *str);

/*builtin_export_sorted.c*/
t_env	**collect_ptrs(t_env *env, int count);
void	sort_ptrs(t_env **arr, int count);

/*builtin_export_print.c*/
int		export_no_args(t_shell *shell);

/*builtin_unset.c*/
int		builtin_unset(char **args, t_shell *shell);

/*builtin_exit.c*/
int		builtin_exit(char **args, t_shell *shell);

#endif
