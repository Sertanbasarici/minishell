/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_mini.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:04:05 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/15 14:34:20 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_control_token(t_minishell *mini)
{
	int			i;
	char		*str;
	t_list		*tmp;
	t_special	*special;

	special = malloc(sizeof(t_special));
	special->nodes_s = malloc(sizeof(t_list));
	special->nodes_s->next = NULL;
	tmp = mini->nodes_t;
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
	t_minishell		*mini;

	mini = malloc(sizeof(t_minishell));
	mini->nodes_t = malloc(sizeof(t_list));
	mini->nodes_t->next = NULL;
	input = ft_tab_to_space(input);
	input = ft_strtrim(input, " ");
	str = ft_split(input, ' ');
	mini = ft_tokanazition(str, mini);
	mini = ft_assign_special_type(mini);
	ft_lstprint_t(mini);
	printf("%d \n", mini->nodes_t->type);
//	ft_control_token(mini);
//	ft_spread(mini);
//	ft_execute_command(mini);
	return (0);
}

int	ft_getsize(t_minishell *mini)
{
	int	size;
	t_list *tmp;
	char	*str;

	tmp = mini->nodes_t;
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

char	*ft_split_with_redirect(t_list *mini, t_list **head)
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
		(*head) = mini;
	else if ((ft_special_type((char *)tmp->content, 0)))
		(*head) = mini->next;
	str[len] = '\0';
	return (str);
}

void	ft_spread(t_minishell *mini)
{
	t_list	*tmp;
	t_list	*tmp_1;
	char	*str;
	int		i;


	mini->full_cmd = malloc(sizeof(char *) * (mini->size + 1));
	i = 0;
	tmp = mini->nodes_t;
	tmp_1 = mini->nodes_t;
	while (tmp != NULL)
	{
		str = (char *)tmp->content;
		if (ft_special_type(str, 0) || tmp->next == NULL)
		{
			mini->full_cmd[i] = ft_split_with_redirect(tmp, &tmp_1);
			printf("%s\n", mini->full_cmd[i]);
			i++;
		}
		tmp = tmp->next;
	}
	mini->full_cmd[i] = NULL;
}


t_minishell	*ft_tokanazition(char **str, t_minishell *mini)
{
	int	i;
	int	j;
	t_list *new;

	j = 0;
	i = ft_strlen_adjusted(str) - 1;
	while (i >= 0)
	{
		new	= ft_lstnew(str[i]);

		ft_lstadd_front(&mini->nodes_t, new);
		mini->nodes_t->index = j;
		mini->nodes_t->content = malloc((ft_strlen(str[i]) + 1) * sizeof(char));
		ft_strlcpy(mini->nodes_t->content, str[i], ft_strlen(str[i]) + 1);
		i--;
		j++;
	}
	mini = ft_deleteLastNode(mini);
	return (mini);
}
