/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:27:03 by sebasari          #+#    #+#             */
/*   Updated: 2024/08/29 14:30:11 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_special	*ft_get_redi_herodoc(t_special *special)
{
	special->nodes_s = ft_lstnew("<<");
	if (special->nodes_s->next != NULL)
		ft_lstadd_front(&special->nodes_s, special->nodes_s);
	special->nodes_s->content = malloc(sizeof(char *));
	special->nodes_s->content = "<<";
	ft_lstprint_s(special);
	return (special);
}

t_special	*ft_get_redi_append(t_special *special)
{
	special->nodes_s = ft_lstnew(">>");
	if (special->nodes_s->next != NULL)
		ft_lstadd_front(&special->nodes_s, special->nodes_s);
	special->nodes_s->content = malloc(sizeof(char *));
	special->nodes_s->content = ">>";
	ft_lstprint_s(special);
	return (special);
}