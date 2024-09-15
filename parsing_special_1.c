/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_special_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:27:03 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/15 18:58:07 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_special	*ft_get_redi_herodoc(t_special *special)
{
	t_list	*new;

	new = ft_lstnew("<<");
	ft_lstadd_front(&special->nodes_s, new);
	special->nodes_s->content = malloc(sizeof(char) * 3);
	ft_strlcpy(special->nodes_s->content, "<<", 3);
		printf("cafer 2\n");
	ft_lstprint_s(special);
	return (special);
}

t_special	*ft_get_redi_append(t_special *special)
{
	t_list	*new;

	new = ft_lstnew(">>");
	ft_lstadd_front(&special->nodes_s, new);
	special->nodes_s->content = malloc(sizeof(char) * 3);
	ft_strlcpy(special->nodes_s->content, ">>", 3);
	printf("cafer 2\n");
	ft_lstprint_s(special);
	return (special);
}

t_minishell	*ft_assign_special_type(t_minishell *mini)
{
	t_list	*tmp;
	char	*str;

	tmp = mini->nodes_t;
	while (tmp != NULL)
	{
		str = (char *)tmp->content;
		if (ft_strcmp(str, "|") == 0)
			tmp->type = PIPE;
		else if ((ft_strcmp(str, ">") == 0))
			tmp->type = GREATER;
		else if ((ft_strcmp(str, "<") == 0))
			tmp->type = SMALLER;
		else if ((ft_strcmp(str, ">>") == 0))
			tmp->type = APPEND;
		else if ((ft_strcmp(str, "<<") == 0))
			tmp->type = HERE_DOC;
		else
			tmp->type = STRING;
		tmp = tmp->next;
	}
	return (mini);
}