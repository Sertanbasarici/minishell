/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:04:05 by sebasari          #+#    #+#             */
/*   Updated: 2024/08/30 21:10:13 by sebasari         ###   ########.fr       */
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

t_mini	*add_q_to_nodes(int *index, char *input, t_mini *q_nodes)
{
	int		len;
	char	*str;

	len = ft_find_next_q(*index, input);
	str = ft_substr(input, *index + 1, len);
	q_nodes->nodes_q = ft_lstnew(str);
	if (q_nodes->nodes_q->next != NULL)
		ft_lstadd_front(&q_nodes->nodes_q, q_nodes->nodes_q);
	q_nodes->nodes_q->content = malloc(sizeof(char *));
	q_nodes->nodes_q->content = str;
	*index += len + 1;
	ft_lstprint(q_nodes);
	return (q_nodes);
}

int	ft_is_quotes_there_index(char c)
{
	if (c == '\0')
		return (0);
	if (c == '\'')
		return (1);
	else if (c == '\"')
		return (1);
	return (0);
}

int	parse_init(char *input)
{
	int			i;
	t_mini		*each_nodes;
	t_special	*special;
	t_white		*white;
	char		**str;

	i = 0;
	input = ft_strtrim(input, " ");
	str = ft_split(input, ' ');
	input = ft_replace_hashtag(str);
	ft_split_free(str);
	printf("%s \n", input);
	white = malloc(sizeof(t_white));
	special = malloc(sizeof(t_special));
	each_nodes = malloc(sizeof(t_mini));
	while (input[i])
	{
		if (special_type(input, i))
			special = ft_find_the_type(input, i, special);
		if (ft_is_whitespace(input[i]))
			ft_white_space(input, i, white);
		if (ft_is_quotes_there_index(input[i]))
			each_nodes = add_q_to_nodes(&i, input, each_nodes);
		i++;
	}
	return (0);
}
