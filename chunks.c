/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:00:25 by anktiri           #+#    #+#             */
/*   Updated: 2025/02/26 12:35:08 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_final_chunk(t_stack **a, t_stack **b, int *pushed, int size)
{
	if ((*a)->index <= size - 4)
	{
		push(a, b, 'b');
		(*pushed)++;
	}
	else
		rotate(a, 'a', 1);
}

static void	handle_current_element(t_stack **a, t_stack **b, t_chunk_data *data)
{
	if ((*a)->index <= data->i)
	{
		push(a, b, 'b');
		rotate(b, 'b', 1);
		data->i++;
		data->pushed++;
	}
	else if ((*a)->index <= data->i + data->chunk_size)
	{
		push(a, b, 'b');
		data->i++;
		data->pushed++;
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
	t_chunk_data	data;

	data.chunk_count = get_chunk_count(size);
	data.chunk_size = size / data.chunk_count;
	data.i = 0;
	data.pushed = 0;
	while (ft_stack_size(*a) > 3)
	{
		if (data.pushed >= size - 3 - data.chunk_size)
			process_final_chunk(a, b, &data.pushed, size);
		else
			handle_current_element(a, b, &data);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 'a', 0);
	rotate(stack_b, 'b', 0);
	ft_printf("rra\n");
}
