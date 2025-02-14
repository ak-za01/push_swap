/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:51:11 by codespace         #+#    #+#             */
/*   Updated: 2025/02/14 18:56:35 by codespace        ###   ########.fr       */
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
	while (stack_a)
	{
		ft_printf("Stack A:\n");
		ft_print_stack(stack_a);
		ft_printf("Stack B:\n");
		push(&stack_a, &stack_b);
		ft_print_stack(stack_b);
	}
	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	atexit(check_leaks);
}
