/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:51:11 by codespace         #+#    #+#             */
/*   Updated: 2025/02/17 17:46:23 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
}

void	check_leaks(void)
{
	system("leaks -q push_swap");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = ft_create_stack(ac, av);
	stack_b = NULL;
	if (ft_stack_size(stack_a) == 3)
		sort_three(&stack_a);
	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	atexit(check_leaks);
}
