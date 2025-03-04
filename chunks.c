/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:00:25 by anktiri           #+#    #+#             */
/*   Updated: 2025/03/03 20:28:16 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_final_chunk(t_stack **a, t_stack **b, int *pushed, int size)
{
	if ((*a)->index <= size)
	{
		push(a, b, 'b');
		(*pushed)++;
	}
	else
		rotate(a, 'a', 1);
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

static int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	else
		return (11);
}

void	push_chunks_to_b(t_stack **a, t_stack **b, int size)
{
	int	chunk_count;
	int	chunk_size;
	int	i;
	int	pushed;

	chunk_count = get_chunk_count(size);
	chunk_size = size / chunk_count;
	i = 0;
	pushed = 0;
	while (ft_stack_size(*a) > 0) // Push all elements to stack B
	{
		if (pushed >= size - chunk_size)
			process_final_chunk(a, b, &pushed, size);
		else
			handle_current_element(a, b, &i, chunk_size);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 'a', 0);
	rotate(stack_b, 'b', 0);
	ft_printf("rr\n");
}
