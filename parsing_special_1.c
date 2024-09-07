/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_special_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:27:03 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/05 15:52:39 by sebasari         ###   ########.fr       */
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
	ft_lstprint_s(special);
	return (special);
}