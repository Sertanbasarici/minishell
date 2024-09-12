/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:04:05 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/12 23:52:50 by sebasari         ###   ########.fr       */
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
	// ft_command(token);
	// token = ft_free_undesired(token);
}

int	parse_init(char *input)
{
	char		**str;
	t_token		*token;

	token = malloc(sizeof(t_token));
	token->nodes_t = malloc(sizeof(t_token));
	token->nodes_t->next = NULL;
	input = ft_tab_to_space(input);
	input = ft_strtrim(input, " ");
	str = ft_split(input, ' ');
	token = ft_tokenazition(str, token);
	ft_split_free(str);
//	ft_lstprint_t(token);
	token->size = ft_getsize(token);
	ft_spread(token);
//	ft_execute_command(token);
//	ft_control_token(token);
	return (0);
}

t_token *ft_deleteLastNode(t_token *token)
{
	t_list *tmp;

	tmp = token->nodes_t;
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
	return (token);
}

int	ft_getsize(t_token *token)
{
	int	size;
	t_list *tmp;
	char	*str;


	tmp = token->nodes_t;
	size = 1;
	while (tmp->next != NULL)
	{
		str = (char *)tmp->content;
		if (ft_special_type(str, 0))
			size++;
		tmp = tmp->next;
	}
	return (size);
}

char	*ft_split_with_redirect(t_list *token, t_list **head)
{
	int		i;
	char	*str;
	t_list	*tmp;
	int		len;
	char	*str_tmp;
	int j;

	j = 0;
	len = 0;
	tmp = *head;
	while (tmp != NULL && !(ft_special_type((char *)tmp->content, 0)))
	{
		len += ft_strlen((char *)tmp->content);
		tmp = tmp->next;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	tmp = *head;
	while (tmp != NULL && !(ft_special_type((char *)tmp->content, 0)))
	{
		str_tmp = (char *)tmp->content;
		i = 0;
		while (str_tmp[i])
			str[j++] = str_tmp[i++];
		tmp = tmp->next;
	}
	if (tmp == NULL)
		(*head) = token;
	else if ((ft_special_type((char *)tmp->content, 0)))
		(*head) = token->next;
	str[len] = '\0';
	return (str);
}

void	ft_spread(t_token *token)
{
	t_list	*tmp;
	t_list	*tmp_1;
	char	*str;
	int		i;


	token->full_cmd = malloc(sizeof(char *) * (token->size + 1));
	i = 0;
	tmp = token->nodes_t;
	tmp_1 = token->nodes_t;
	while (tmp != NULL)
	{
		str = (char *)tmp->content;
		if (ft_special_type(str, 0) || tmp->next == NULL)
		{
			token->full_cmd[i] = ft_split_with_redirect(tmp, &tmp_1);
			printf("%s\n", token->full_cmd[i]);
			i++;
		}
		tmp = tmp->next;
	}
	token->full_cmd[i] = NULL;
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
	token = ft_deleteLastNode(token);
	return (token);
}
