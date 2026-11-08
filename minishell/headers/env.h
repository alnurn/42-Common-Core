/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:56:28 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../libft/libft.h"

typedef struct s_env
{
	char			*key;
	char			*content;
	struct s_env	*next;
	struct s_env	*previous;
}	t_env;

/*environment.c*/
t_env	*dup_env(char **envp);
void	free_env(t_env **envp);
t_env	*get_env(const char *key, t_env *envp);

/*env_set.c*/
int		env_set(t_env **envp, const char *key, const char *value);
int		env_declare(t_env **envp, const char *key);

/*env_build.c*/
char	**build_envp(t_env *envp);

//------------   LINKED LISTS   -------------//

/*env_lstnew.c*/
t_env	*env_lstnew(char *key, char *content);
/*env_lstdelone.c*/
void	env_lstdelone(t_env *lst, void (*del)(void *));
/*env_lstclear.c*/
void	env_lstclear(t_env **lst, void (*del)(void *));
/*env_lstadd_back.c*/
void	env_lstadd_back(t_env **lst, t_env *new_node);
/*env_lstlast.c*/
t_env	*env_lstlast(t_env *lst);
/*env_lstremove.c*/
void	env_lstremove(t_env **lst, const char *key);

#endif
