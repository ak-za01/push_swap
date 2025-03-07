/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:50:37 by codespace         #+#    #+#             */
/*   Updated: 2025/03/06 21:33:22 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_has_only_spaces(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse_argument(char *arg, t_stack **stack)
{
	char	**split_args;
	int		i;
	int		error;
	int		value;

	if (!arg || !*arg || ft_has_only_spaces(arg))
		return (0);
	split_args = ft_split(arg, ' ');
	if (!split_args)
		return (0);
	i = 0;
	while (split_args[i])
	{
		value = ft_convert_to_integer(split_args[i], &error);
		if (error)
		{
			ft_free_split_array(split_args);
			return (0);
		}
		ft_add_to_stack(stack, value);
		i++;
	}
	ft_free_split_array(split_args);
	return (1);
}

int	ft_convert_to_integer(char *str, int *error)
{
	long	value;
	int		err;
	char	*trimmed;

	*error = 0;
	err = 0;
	trimmed = ft_trim_input(str);
	if (!trimmed || !ft_validate_input(trimmed) || ft_has_only_spaces(str))
	{
		free(trimmed);
		*error = 1;
		return (0);
	}
	value = ft_atoi(trimmed, &err);
	free(trimmed);
	if (err)
	{
		*error = 1;
		return (0);
	}
	return ((int)value);
}

void	ft_free_split_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_validate_stack_order(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
