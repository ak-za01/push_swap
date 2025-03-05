/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:20:53 by anktiri           #+#    #+#             */
/*   Updated: 2025/03/05 11:30:41 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lowest_index(t_stack *stack)
{
	int	min_index;

	min_index = INT_MAX;
	while (stack)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (min_index);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	if (first > second && second < third && first < third)
		swap(a, 'a', 1);
	else if (first > second && second > third)
	{
		swap(a, 'a', 1);
		reverse_rotate(a, 'a', 1);
	}
	else if (first > second && second < third && first > third)
		rotate(a, 'a', 1);
	else if (first < second && second > third && first < third)
	{
		swap(a, 'a', 1);
		rotate(a, 'a', 1);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(a, 'a', 1);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int index;

	index = find_lowest_index(*a);
	while ((*a)->index != index)
		rotate(a, 'a', 1);
	push(a, b, 'b');
	sort_three(a);
	push(b, a, 'a');
}

int	find_position(t_stack *stack, int target_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	pos;

	pos = find_position(*a, 0);
	if (pos <= ft_stack_size(*a) / 2)
	{
		while ((*a)->index != 0)
			rotate(a, 'a', 1);
	}
	else
	{
		while ((*a)->index != 0)
			reverse_rotate(a, 'a', 1);
	}
	push(a, b, 'b');
	sort_four(a, b);
	push(b, a, 'a');
}
