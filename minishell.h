/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:07:13 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/15 18:47:08 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <sys/wait.h>

typedef struct s_special
{
	t_list	*nodes_s;
}			t_special;

typedef struct	s_minishell
{
	t_list			*nodes_t;
	int				token_num;
	int				size;
	char			**full_cmd;
}					t_minishell;

int			check_if_empty(char *str);

// initialize
void		adjsut_all(char *input);

// adjust quotes
int			ft_single_quotes_finised(char *input, int index);
int			ft_quotes_num(char *input);
int			ft_is_quotes_there(char *input);
int			ft_is_quotes_there_index(char c);
int			ft_quotes(char *input);
int			ft_last_index_check(char *str);
void		ft_dollar_sign(char *str);
void		ft_back_slash(char *str);
int			ft_double_quotes_check(char *str, int index);
int			ft_double_quotes_finised(char *input, int index);
int			ft_even_odd(char *str, char c);
t_list		*add_q_to_nodes(int *index, char *input, t_list *mini_list);
int			ft_find_next_q(int start, char *input);
t_list		*ft_getridof_q(t_list *nodes_t);
t_list		*ft_basic_q(t_list *nodes_t, int	len);

//parse init()
int			parse_init(char *input);
t_minishell	*ft_tokanazition(char **str, t_minishell *mini);
void		ft_control_token(t_minishell *mini);
char		*ft_split_with_redirect(t_list *mini, t_list **head);
void		ft_spread(t_minishell *mini);
int			ft_getsize(t_minishell *mini);
t_minishell	*ft_deleteLastNode(t_minishell *mini);

// util
void		ft_error();
void		ft_lstprint_s(t_special *special);
void		ft_lstprint_t(t_minishell *mini);
int			ft_get_size_double_point(char **str);
void		ft_split_free(char **str);
void		del(void *content);
int			ft_strlen_adjusted(char **str);
char		*ft_strtok(char *str, char *delim);
char		*ft_tab_to_space(char *input);
int			ft_strcmp(const char *s1, const char *s2);

//redirect
int			ft_special_type(char *input, int i);
t_special	*ft_find_the_type(char *input, int i, t_special *special);
t_special	*ft_get_redi_in(t_special *special, char *input, int i);
t_special	*ft_get_redi_out(t_special *special, char *input, int i);
t_special	*ft_get_pipe(t_special *special, char *input, int i);
t_special	*ft_get_redi_herodoc(t_special *special);
t_special	*ft_get_redi_append(t_special *special);
t_minishell	*ft_assign_special_type(t_minishell *mini);

//execute
void		ft_execute_command(t_minishell *mini);
char		*ft_find_command_path(char *command);
#endif
