/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:08:44 by sebasari          #+#    #+#             */
/*   Updated: 2024/08/30 20:59:19 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_split_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_error()
{
	printf("error\n");
	exit(1);
}

void	ft_lstprint_w(t_white *white)
{
	t_list *tmp;

	tmp = white->nodes_w;
	while (tmp != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}

void	ft_lstprint_s(t_special *special)
{
	t_list *tmp;


	tmp = special->nodes_s;
	while (tmp != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}

void	ft_lstprint(t_mini *q_nodes)
{
	t_list *tmp;

	tmp = q_nodes->nodes_q;
	while (tmp != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}

int	ft_get_size_double_point(char **str)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (str[i])
	{
		size += ft_strlen(str[i]);
		size++;
		i++;
	}
	return (size);
}

char	*ft_replace_hashtag(char **str)
{
	int		i;
	int		j;
	char	*input;
	int		size;
	char	*tmp;

	i = 0;
	j = 0;
	size = ft_get_size_double_point(str);
	input = malloc(sizeof(char) * (size + 1));
	tmp = input;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			*(input++) = str[i][j++];
		*input = '#';
		input++;
		i++;
	}
	*input = '\0';
	input = tmp;
	return (input);
}