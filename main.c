/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:27:07 by sebasari          #+#    #+#             */
/*   Updated: 2024/08/09 15:35:12 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc((sizeof(char)) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_even_odd(char *str, char c)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			counter++;
		i++;
	}
	return (counter);
}

int	ft_double_quotes_check(char *str, int index)
{
	
	if (ft_even_odd(str, '\"') % 2 == 1)
		return (1);
	index++;
	while (str[index])
	{
		if (str[index] == '\"')

		index++;
	}
	return (0);
}

int	ft_quotes_finised(char *input, int index)
{
	int	checker;

	checker = 0;
	while (input[index])
	{
		if (input[index] == '\'')
		{
			if (ft_even_odd(input, '\'') % 2 == 1)
				return (1);
		}
		else if (input[index] == '\"')
		{
			/*if (ft_double_quotes_check(input))
				return (1);*/
		}
		index++;
	}
	return (0);
}

int	ft_quotes_num(char *input)
{
	int	i;

	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '\"')
			return (i);
		i++;
	}
	return (0);
}

int ft_is_quotes_there(char *input)
{
	int	i;

	while (input[i])
	{
		if (input[i] == '\"')
			return (1);
		if (input[i] == '\'')
			return (2);
		i++;
	}
	return (0);
}

int	ft_quotes(char *input)
{
	int index;

	index = 0;
	if (ft_is_quotes_there(input) == 1)
	{
		index = ft_quotes_num(input);
		if (ft_quotes_finised(input, index) == 1)
		{
			printf("error\n");
			return (1);
		}
	}
	if (ft_is_quotes_there(input) == 2)
	{
		index = ft_quotes_num(input);
		if (ft_quotes_finised(input, index) == 1)
		{
			printf("error\n");
			return (1);
		}
	}
	return (0);
}

int	ft_last_index_check(char *str)
{
	if (str[ft_strlen(str) - 1] == '\\')
	{
		printf("error\n");
		return (1);
	}
	return (0);
}

int main()
{
	char *input;

	while (1) 
	{
		input = readline("minishell$ ");
		if (ft_last_index_check(input))
			exit(1);
		if (ft_quotes(input) == 1)
			exit(1);
		add_history(input);
	}
	return 0;
}
