/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:00:25 by anktiri           #+#    #+#             */
/*   Updated: 2025/03/10 14:32:01 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_chunk_count(int size)
{
	if (size <= 20)
		return (3);
	else if (size <= 100)
		return (7);
	else
		return (15);
}

static void	handle_current_element(t_stack **a, t_stack **b, int *i, int chunk_size)
{
	if ((*a)->index <= *i)
	{
		push(a, b, 'b');
		rotate(b, 'b', 1);
		(*i)++;
	}
	else if ((*a)->index <= *i + chunk_size)
	{
		push(a, b, 'b');
		(*i)++;
	}
	else
		rotate(a, 'a', 1);
}

void	push_chunks_to_b(t_stack **a, t_stack **b, int size)
{
	int	chunk_count;
	int	chunk_size;
	int	pushed;

	chunk_count = get_chunk_count(size);
	chunk_size = size / chunk_count;
	pushed = 0;
	while (ft_stack_size(*a) > 0)
	{
		if (pushed >= size - chunk_size)
		{
			push(a, b, 'b');
			pushed++;
		}
		else
			handle_current_element(a, b, &pushed, chunk_size);
	}
}

int	ft_validate_reverse_order(t_stack *stack)
{
	if (!stack)
		return (1);
		
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
