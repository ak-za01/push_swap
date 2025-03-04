/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:12:25 by anktiri           #+#    #+#             */
/*   Updated: 2025/03/03 20:28:43 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stack_size(*a);
	if (size <= 1)
		return ;
	list_index(a);
	if (size <= 3)
		sort_three(a);
	else
	{
		push_chunks_to_b(a, b, size);
		//sort_three(a);
		push_back_to_a(a, b);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, 'a', 0);
	reverse_rotate(stack_b, 'b', 0);
	ft_printf("rrr\n");
}
