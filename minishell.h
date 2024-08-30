/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:07:13 by sebasari          #+#    #+#             */
/*   Updated: 2024/08/30 20:59:08 by sebasari         ###   ########.fr       */
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

typedef struct s_white
{
	t_list	*nodes_w;
	char	**full_cmd;
}			t_white;

typedef struct s_special
{
	t_list	*nodes_s;
	char	**full_cmd;
}			t_special;

typedef struct s_mini
{
	t_list	*nodes_q;
	char	**full_cmd;
}			t_mini;


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
int			parse_init(char *input);
t_mini		*add_q_to_nodes(int *index, char *input, t_mini *q_nodes);
int			ft_find_next_q(int start, char *input);

void		ft_error();
void		ft_lstprint(t_mini *q_nodes);
void		ft_lstprint_s(t_special *special);
void		ft_lstprint_w(t_white *white);
char		*ft_replace_hashtag(char **str);
int			ft_get_size_double_point(char **str);
void		ft_split_free(char **str);

int			special_type(char *input, int i);
t_special	*ft_find_the_type(char *input, int i, t_special *special);
t_special	*ft_get_redi_in(t_special *special, char *input, int i);
t_special	*ft_get_redi_out(t_special *special, char *input, int i);
t_special	*ft_get_pipe(t_special *special, char *input, int i);
t_special	*ft_get_redi_herodoc(t_special *special);
t_special	*ft_get_redi_append(t_special *special);



int			ft_is_whitespace(char c);
t_white		*ft_white_space(char *input, int i, t_white *white);
#endif
