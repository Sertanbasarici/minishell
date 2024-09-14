/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:04:05 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/14 19:16:49 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_control_token(t_token *token)
{
	int			i;
	char		*str;
	t_list		*tmp;
	t_special	*special;

	special = malloc(sizeof(t_special));
	special->nodes_s = malloc(sizeof(t_list));
	special->nodes_s->next = NULL;
	tmp = token->nodes_t;
	while (tmp != NULL)
	{
		str = (char *)tmp->content;
		i = 0;
		while (str[i])
		{
			if (ft_is_quotes_there_index(str[i]))
				tmp = add_q_to_nodes(&i, str, tmp);
			if (ft_special_type(str, i)) {
				printf("gecti 2\n");
				special = ft_find_the_type(str, i, special);
			}
			i++;
		}
		tmp = tmp->next;
	}
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
	ft_control_token(token);
	printf("%d \n", ft_lstsize(token->nodes_t));
	ft_lstprint_t(token);
	token->size = ft_getsize(token);
	ft_spread(token);
//	ft_execute_command(token);
	return (0);
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
		token->nodes_t->index = i;
		token->nodes_t->content = malloc((ft_strlen(str[i]) + 1) * sizeof(char));
		ft_strlcpy(token->nodes_t->content, str[i], ft_strlen(str[i]) + 1);
		i--;
	}
	token = ft_deleteLastNode(token);
	return (token);
}
