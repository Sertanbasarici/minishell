/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melcuman <melcuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:27:07 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/09 16:34:32 by melcuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char	*input;

	while (1) 
	{
		input = readline("minishell$ ");
		parse_init(input); // parsing input
		add_history(input); // add history
	}
	return 0;
}
