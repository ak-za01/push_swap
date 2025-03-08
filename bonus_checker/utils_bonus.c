/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:54:57 by anktiri           #+#    #+#             */
/*   Updated: 2025/03/08 17:48:49 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while (s1[a] && (s1[a] == s2[a]) && a < n - 1)
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}

int	check_opps(char *opp)
{
	if (!ft_strncmp(opp, "sa\n", 3) || !ft_strncmp(opp, "sb\n", 3)
		|| !ft_strncmp(opp, "ss\n", 3) || !ft_strncmp(opp, "pa\n", 3)
		|| !ft_strncmp(opp, "pb\n", 3) || !ft_strncmp(opp, "ra\n", 3)
		|| !ft_strncmp(opp, "rb\n", 3) || !ft_strncmp(opp, "rr\n", 3)
		|| !ft_strncmp(opp, "rra\n", 4) || !ft_strncmp(opp, "rrb\n", 4)
		|| !ft_strncmp(opp, "rrr\n", 4))
		return (1);
	return (0);
}

void	apply_opps(char *opp, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(opp, "sa\n", 3))
		swap(a);
	else if (!ft_strncmp(opp, "sb\n", 3))
		swap(b);
	else if (!ft_strncmp(opp, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(opp, "pa\n", 3))
		push(b, a);
	else if (!ft_strncmp(opp, "pb\n", 3))
		push(a, b);
	else if (!ft_strncmp(opp, "ra\n", 3))
		rotate(a);
	else if (!ft_strncmp(opp, "rb\n", 3))
		rotate(b);
	else if (!ft_strncmp(opp, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(opp, "rra\n", 4))
		reverse_rotate(a);
	else if (!ft_strncmp(opp, "rrb\n", 4))
		reverse_rotate(b);
	else if (!ft_strncmp(opp, "rrr\n", 4))
		rrr(a, b);
}

void	check_order(t_stack *a, t_stack *b)
{
	if (ft_validate_stack_order(a) && !b)
		ft_putstr_fd("\033[0;32mOK\n", 1);
	else
		ft_putstr_fd("\033[0;31mKO\n", 1);
}
