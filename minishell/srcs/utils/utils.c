/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:57:35 by mgumberi          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*addchar(char	*line, int len, char c)
{
	char	*new_line;
	int		i;

	new_line = malloc(len + 2);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	free(line);
	new_line[len] = c;
	new_line[len + 1] = '\0';
	return (new_line);
}

static char	*get_str(char	*buffer, int	*pos, int	*bytes)
{
	char	*str;
	char	c;
	int		len;

	len = 0;
	str = NULL;
	while (1)
	{
		if (*pos >= *bytes)
		{
			*bytes = read(STDIN_FILENO, buffer, 1);
			if (*bytes <= 0)
				break ;
			*pos = 0;
		}
		c = buffer[*pos];
		str = addchar(str, len, c);
		if (!str)
			break ;
		*pos += 1;
		len++;
		if (c == '\n')
			break ;
	}
	return (str);
}

char	*silent_reader(void)
{
	static char	buffer[1];
	static int	pos;
	static int	bytes;
	char		*str;
	int			len;

	str = get_str(buffer, &pos, &bytes);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len && str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}

void	shell_cleanup(t_shell *shell)
{
	free_env(&shell->env);
	rl_clear_history();
}
