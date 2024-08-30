/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:58:15 by sebasari          #+#    #+#             */
/*   Updated: 2024/08/29 16:44:44 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_whitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_find_the_charecter(char *input, int i, int start)
{
	while (start < i)
	{
		if (ft_isprint(input[start]))
			return (start);
		start++;
	}
	return (0);
}

t_white	*ft_white_space(char *input, int i, t_white *white)
{
	char			*str;
	static int		start;

	start = ft_find_the_charecter(input, i, start);
	str = ft_substr(input, start, i - start);
	white->nodes_w = ft_lstnew(str);
	if (white->nodes_w->next != NULL)
		ft_lstadd_front(&white->nodes_w, white->nodes_w);
	white->nodes_w->content = malloc(sizeof(char *));
	white->nodes_w->content = str;
	ft_lstprint_w(white);
	return (white);
	return(0);
}