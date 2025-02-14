/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:37:06 by anktiri           #+#    #+#             */
/*   Updated: 2025/02/11 21:50:02 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validate_input(char *str)
{
	int	i;
	int	sign_count;

	i = 0;
	sign_count = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		sign_count++;
		if (sign_count > 1)
			return (0);
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_trim_input(char *str)
{
	int		start;
	int		end;
	char	*result;

	start = 0;
	while (str[start] == ' ')
		start++;
	end = ft_strlen(str) - 1;
	while (end > start && str[end] == ' ')
		end--;
	result = malloc(end - start + 2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, str + start, end - start + 2);
	return (result);
}

int	ft_check_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;

	current = stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->content == compare->content)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

void	ft_handle_error(t_stack **stack)
{
	ft_putstr_fd("Error\n", 2);
	if (stack && *stack)
		ft_clear_stack(stack);
	exit(1);
}

int	ft_count_numbers(char *str, char delimiter)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == delimiter)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != delimiter)
				i++;
		}
	}
	return (count);
}
