/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:58:15 by sebasari          #+#    #+#             */
/*   Updated: 2024/08/30 20:58:09 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_whitespace(char c)
{
	if (c == '#')
		return (1);
	return (0);
}

t_white	*ft_white_space(char *input, int i, t_white *white)
{
	static int	start;
	char		*str;

	str = ft_substr(input, start, i);
	start = i + 1;
	white->nodes_w = ft_lstnew(str);
	if (white->nodes_w->next != NULL)
		ft_lstadd_front(&white->nodes_w, white->nodes_w);
	white->nodes_w->content = malloc(sizeof(char *));
	white->nodes_w->content = str;
	ft_lstprint_w(white);
	return (white);
}