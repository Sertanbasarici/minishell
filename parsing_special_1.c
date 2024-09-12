/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_special_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melcuman <melcuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:27:03 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/09 19:01:55 by melcuman         ###   ########.fr       */
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