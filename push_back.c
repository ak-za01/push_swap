/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:00:33 by anktiri           #+#    #+#             */
/*   Updated: 2025/02/26 12:27:47 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest_index(t_stack *stack)
{
	int	max_index;

	max_index = INT_MIN;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}

static int	find_position(t_stack *stack, int max_index)
{
	int	pos;

	pos = 0;
	while (stack && stack->index != max_index)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

static void	rotate_to_position(t_stack **b, int pos)
{
	int	size;
	int	i;

	size = ft_stack_size(*b);
	i = 0;
	if (pos <= size / 2)
	{
		while (i++ < pos)
			rotate(b, 'b', 1);
	}
	else
	{
		while (i++ < size - pos)
			reverse_rotate(b, 'b', 1);
	}
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max_index;
	int	pos;

	while (*b)
	{
		max_index = find_highest_index(*b);
		pos = find_position(*b, max_index);
		rotate_to_position(b, pos);
		push(b, a, 'a');
	}
}
