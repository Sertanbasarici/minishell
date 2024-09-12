/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:58:15 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/10 17:47:41 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void ft_execve(t_list *token)
// {
// 	// if (&token->next.content[0] == '-')
//     char *str;
//     char *argv[] = { "ls", "-l", "-a", NULL }; // Komut ve argümanlar
//     char *envp[] = { NULL };       // Çevresel değişkenler, burada boş

//     str = (char *)token->content;

//     if (str && ft_strncmp(str, "ls", ft_strlen(str)) == 0)
//     {
//         // execve'nin argümanları
//         execve("/bin/ls", argv, envp);
        
//         // execve başarılı bir şekilde çağrıldıysa, aşağıdaki kod çalışmaz
//         perror("execve");
//         exit(EXIT_FAILURE);
//     }
// }

// void	ft_command(t_token *token)
// {
// 	// buildin command veya exec (ls) controlu
// 	t_list *tmp;

// 	tmp = token->nodes_t;
// 	while (tmp->next != NULL)
// 	{
// 		// if ()
// 		tmp = tmp->next;
// 	}
// }