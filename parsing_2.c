/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:58:15 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/02 14:15:13 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_find_next_hashtag(int start, char *input)
{
	int	len;

	len = 0;
	start++;
	while (input[start++] != ' ')
		len++;
	return (len);
}

t_white	*ft_regular(int *index, char *input, t_white *white)
{
	int		len;
	char	*str;

	len = 3;
	str = ft_substr(input, *index + 1, len);
	white->nodes_w = ft_lstnew(str);
	if (white->nodes_w->next != NULL)
		ft_lstadd_front(&white->nodes_w, white->nodes_w);
	white->nodes_w->content = malloc(sizeof(char *));
	white->nodes_w->content = str;
	*index = len + 1;
	ft_lstprint_w(white);
	return (white);
}
