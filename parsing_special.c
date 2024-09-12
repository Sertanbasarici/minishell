/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:07:59 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/11 15:00:34 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_special_type(char *input, int i)
{
	if (input[i] == '<' || input[i] == '>' || input[i] == '|')
	{
		if ((input[i] == '>' && input[i + 1] == '>') || (input[i] == '<' && input[i + 1] == '<' ))
			return (1);
		else
			return (1);
	}
	return (0);
}

t_special	*ft_find_the_type(char *input, int i, t_special *special)
{
	if (input[i - 1] != '<' && input[i] == '<' && input[i + 1] != '<')
		special = ft_get_redi_in(special, input, i);
	else if (input[i - 1] != '>' && input[i] == '>' && input[i + 1] != '>')
		special = ft_get_redi_out(special, input, i);
	else if (input[i - 1] != '<' && input[i] == '<' && input[i + 1] == '<')
		special = ft_get_redi_herodoc(special);
	else if (input[i - 1] != '>' && input[i] == '>' && input[i + 1] == '>')
		special = ft_get_redi_append(special);
	else if (input[i] == '|' )
		special = ft_get_pipe(special, input, i);
	return (special);
}

t_special	*ft_get_redi_in(t_special *special, char *input, int i)
{
	char	*str;
	t_list	*new;

	str = ft_substr(input, i, 1);
	new = ft_lstnew(str);
	ft_lstadd_front(&special->nodes_s, new);
	special->nodes_s->content = malloc(sizeof(char) * 2);
	ft_strlcpy(special->nodes_s->content, str, 2);
	printf("cafer 2\n");
	ft_lstprint_s(special);
	return (special);
}

t_special	*ft_get_redi_out(t_special *special, char *input, int i)
{
	char	*str;
	t_list	*new;

	str = ft_substr(input, i, 1);
	new = ft_lstnew(str);
	ft_lstadd_front(&special->nodes_s, new);
	special->nodes_s->content = malloc(sizeof(char) * 2);
	ft_strlcpy(special->nodes_s->content, str, 2);
	printf("cafer 2\n");
	ft_lstprint_s(special);
	return (special);
}

t_special	*ft_get_pipe(t_special *special, char *input, int i)
{
	char *str;
	t_list	*new;

	str = ft_substr(input, i, 1);
	new = ft_lstnew(str);
	ft_lstadd_front(&special->nodes_s, new);
	special->nodes_s->content = malloc(sizeof(char) * 2);
	ft_strlcpy(special->nodes_s->content, str, 2);
	printf("cafer 2\n");
	ft_lstprint_s(special);
	return (special);
}