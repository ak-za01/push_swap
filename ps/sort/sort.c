/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:12:25 by anktiri           #+#    #+#             */
/*   Updated: 2025/03/10 15:30:35 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_reverse(t_stack **a, t_stack **b)
{
	while (*a)
		push(a, b, 'b');
	while (*b)
	{
		push(b, a, 'a');
		rotate(a, 'a', 1);
	}
}

void	list_index(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*copy;
	int		index;

	if (!stack || !(*stack))
		return ;
	tmp = *stack;
	while (tmp)
	{
		index = 0;
		copy = *stack;
		while (copy)
		{
			if (tmp->content > copy->content)
				index++;
			copy = copy->next;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stack_size(*a);
	if (size <= 1)
		return ;
	list_index(a);
	if (size == 2)
		swap(a, 'a', 1);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size <= 5)
		sort_five(a, b);
	else if (ft_validate_reverse_order(*a))
		sort_reverse(a, b);
	else
	{
		push_chunks_to_b(a, b, size);
		push_back_to_a(a, b);
	}
}
