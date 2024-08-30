/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:19:50 by sebasari          #+#    #+#             */
/*   Updated: 2024/02/18 16:06:33 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	if (!tmp)
		tmp = new;
	else
	{
		while (tmp -> next != NULL)
			tmp = tmp -> next;
		new -> next = tmp -> next;
		tmp -> next = new;
	}
}
