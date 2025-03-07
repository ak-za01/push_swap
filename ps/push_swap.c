/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:51:11 by codespace         #+#    #+#             */
/*   Updated: 2025/03/07 21:40:56 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = ft_create_stack(ac, av);
	if (!stack_a)
		return (0);
	stack_b = NULL;
	if (!ft_validate_stack_order(stack_a))
		ft_sort(&stack_a, &stack_b);
	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	return (0);
}
