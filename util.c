/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:08:44 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/12 09:59:59 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_split_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_error()
{
	printf("error\n");
	exit(1);
}

void	ft_lstprint_s(t_special *special)
{
	t_list *tmp;


	tmp = special->nodes_s;
	while (tmp->next != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}

void	ft_lstprint(t_quote *quotes)
{
	t_list *tmp;

	tmp = quotes->nodes_q;
	while (tmp->next != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}

void	ft_lstprint_t(t_token *token)
{
	t_list *tmp;

	tmp = token->nodes_t;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}

int	ft_get_size_double_point(char **str)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (str[i])
	{
		size += ft_strlen(str[i]);
		i++;
	}
	return (size);
}

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
	char *token_start = next;
	while (*next && !ft_strchr(delim, *next))
		next++;
	if (*next)
	{
		*next = '\0';
		next++;
	}
	return token_start;
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