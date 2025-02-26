/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:51:57 by anktiri           #+#    #+#             */
/*   Updated: 2025/02/22 16:09:17 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, 'a', 0);
	swap(stack_b, 'b', 0);
	ft_printf("ss\n");
}
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 'a', 0);
	rotate(stack_b, 'b', 0);
	ft_printf("rra\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, 'a', 0);
	reverse_rotate(stack_b, 'b', 0);
	ft_printf("rrr\n");
}