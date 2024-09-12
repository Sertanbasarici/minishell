/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melcuman <melcuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:44:46 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/09 19:02:55 by melcuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_find_next_q(int start, char *input)
{
	int	len;

	len = 0;
	if (input[start] == '\'')
	{
		start++;
		if (ft_single_quotes_finised(input, start))
			ft_error();
		while (input[start] != '\'' && input[start++] != '\n')
			len++;
	}
	else if (input[start] == '\"')
	{
		start++;
		if (ft_double_quotes_finised(input, start))
			ft_error();
		while (input[start] != '\"' && input[start++] != '\n')
			len++;
	}
	return (len);
}

t_quote	*add_q_to_nodes(int *index, char *input, t_quote *quotes)
{
	int			len;
	char		*str;
	t_list		*new;

	len = ft_find_next_q(*index, input);
	str = ft_substr(input, *index + 1, len);
	new = ft_lstnew(str);
	ft_lstadd_front(&quotes->nodes_q, new);
	quotes->nodes_q->content = malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_strlcpy(quotes->nodes_q->content, str, len + 1);
	*index += len + 1;
	printf("cafer 1\n");
	ft_lstprint(quotes);
	free(str);
	return (quotes);
}

int	ft_is_quotes_there_index(char c)
{
	
	if (c == '\0') {
		printf("%c \n", c);
		return (0);
	}
	if (c == '\''){
		printf("%c \n", c);
		return (1);
	}
	else if (c == '\"')
		return (1);
	return (0);
}
