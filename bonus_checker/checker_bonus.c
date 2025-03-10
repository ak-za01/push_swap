/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:51:11 by codespace         #+#    #+#             */
/*   Updated: 2025/03/10 14:36:24 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	opps_pr(t_stack **a, t_stack **b)
{
	char	*opp;

	opp = get_next_line(0);
	while (opp)
	{
		if (check_opps(opp))
		{
			apply_opps(opp, a, b);
			free(opp);
			opp = get_next_line(0);
		}
		else
		{
			free(opp);
			return (0);
		}
	}
	return (1);
}

static void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!opps_pr(stack_a, stack_b))
	{
		ft_putstr_fd("\033[0;31mError\n", 2);
		return ;
	}
	check_order(*stack_a, *stack_b);
}

void	ll(void)
{
	system("leaks checker");
}

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
	// atexit(ll);
	return (0);
}
