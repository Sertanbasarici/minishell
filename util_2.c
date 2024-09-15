/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:13:07 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/15 14:35:34 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen_adjusted(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void del(void *content)
{
	free(content);
}

char *ft_strtok(char *str, char *delim)
{
	static char *next;
	if (str != NULL)
		next = str;
	if (next == NULL)
		return NULL;
	while (*next && ft_strchr(delim, *next))
		next++;
	if (*next == '\0')
		return NULL;
	char *mini_start = next;
	while (*next && !ft_strchr(delim, *next))
		next++;
	if (*next)
	{
		*next = '\0';
		next++;
	}
	return mini_start;
}

char	*ft_tab_to_space(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\t')
			input[i] = ' ';
		i++;
	}
	return (input);
}

t_minishell *ft_deleteLastNode(t_minishell *mini)
{
	t_list *tmp;

	tmp = mini->nodes_t;
	if (tmp == NULL)
		return NULL;
	if (tmp->next == NULL)
	{
		free(tmp);
		tmp = NULL;
		return NULL;
	}
	while (tmp->next->next != NULL) {
		tmp = tmp->next;
	}
	free(tmp->next);
	tmp->next = NULL;
	return (mini);
}
