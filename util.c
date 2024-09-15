/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:08:44 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/15 14:35:34 by sebasari         ###   ########.fr       */
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

void	ft_lstprint_s(t_special *special)
{
	t_list *tmp;


	tmp = special->nodes_s;
	while (tmp->next != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}

void	ft_lstprint_t(t_minishell *mini)
{
	t_list *tmp;

	tmp = mini->nodes_t;
	while (tmp)
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
		i++;
	}
	return (size);
}
