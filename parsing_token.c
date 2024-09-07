/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:04:05 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/06 16:40:59 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_control_token(t_token *token)
{
	int			i;
	char		*str;
	t_list		*tmp;
	t_quote		*quotes;
	t_special	*special;

	quotes = malloc(sizeof(t_quote));
	quotes->nodes_q = malloc(sizeof(t_list));
	quotes->nodes_q->next = NULL;
	special = malloc(sizeof(t_special));
	special->nodes_s = malloc(sizeof(t_list));
	quotes->nodes_q->next = NULL;
	tmp = token->nodes_t;
	while (tmp -> next != NULL)
	{
		str = (char *)tmp->content;
		i = 0;
		while (str[i])
		{
			if (ft_is_quotes_there_index(str[i])) {
				printf("gecti 1\n");
				quotes = add_q_to_nodes(&i, str, quotes);
			}
			if (ft_special_type(str, i)) {
				printf("gecti 2\n");
				special = ft_find_the_type(str, i, special);
			}
			i++;
		}
		tmp = tmp->next;
	}
	token = ft_free_undesired(token);
}

int	parse_init(char *input)
{
	char		**str;
	t_token		*token;

	token = malloc(sizeof(t_token));
	token->nodes_t = malloc(sizeof(t_token));
	token->nodes_t->next = NULL;
	input = ft_strtrim(input, " ");
	str = ft_split(input, ' ');
	token = ft_tokenazition(str, token);
	ft_split_free(str);
	ft_lstprint_t(token);
	ft_control_token(token);
	return (0);
}

t_token	*ft_tokenazition(char **str, t_token *token)
{
	int	i;
	t_list *new;

	i = ft_strlen_adjusted(str) - 1;
	while (i >= 0)
	{
		new	= ft_lstnew(str[i]);
		ft_lstadd_front(&token->nodes_t, new);
		token->nodes_t->content = malloc((ft_strlen(str[i]) + 1) * sizeof(char));
		ft_strlcpy(token->nodes_t->content, str[i], ft_strlen(str[i]) + 1);
		i--;
	}
	return (token);
}

t_token	*ft_free_undesired(t_token *token)
{
	t_list	*tmp;
	t_list	*tmp_pre;
	char	*str;

	tmp = token->nodes_t;
	str = (char *)tmp->content;
	if (ft_is_quotes_there_index(str[0]) || ft_special_type(str, 0))
	{
		token->nodes_t = tmp->next;
		ft_lstdelone(tmp, del);
		ft_lstprint_t(token);
		return (token);
	}
	
	tmp_pre = tmp;
	tmp = tmp_pre->next;
	str = (char *)tmp->content;
	while (tmp_pre->next != NULL && (!ft_is_quotes_there_index(str[0]) || !ft_special_type(str, 0)))
	{
		tmp_pre = tmp_pre->next;
		tmp = tmp_pre->next;
		printf("%s \n", str);
		str = (char *)tmp->content;
	}

	if ((ft_is_quotes_there_index(str[0]) || ft_special_type(str, 0)))
	{
		tmp_pre->next = tmp->next;
		ft_lstdelone(tmp, del);
	}
	ft_lstprint_t(token);
	return (token);
}
