/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:08:44 by sebasari          #+#    #+#             */
/*   Updated: 2024/08/29 15:00:16 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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