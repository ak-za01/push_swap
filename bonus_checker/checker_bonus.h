/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:52:55 by codespace         #+#    #+#             */
/*   Updated: 2025/03/08 17:49:05 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "GNL/get_next_line_bonus.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

// Error Handling
int					ft_validate_input(char *str);
char				*ft_trim_input(char *str);
int					ft_check_duplicates(t_stack *stack);
void				ft_handle_error(t_stack **stack);
int					ft_count_numbers(char *str, char delimiter);

// Stack Operations
t_stack				*ft_create_stack(int ac, char **av);
void				ft_clear_stack(t_stack **stack);
void				ft_add_to_stack(t_stack **stack, int value);
t_stack				*ft_last_stack_node(t_stack *stack);
int					ft_stack_size(t_stack *stack);
void				list_index(t_stack **stack);

// Parsing Functions
int					ft_atoi(char *str, int *error);
int					ft_parse_argument(char *arg, t_stack **stack);
int					ft_convert_to_integer(char *str, int *error);
void				ft_free_split_array(char **array);
int					ft_validate_stack_order(t_stack *stack);

// Extra Helper Functions
int					ft_isdigit(int c);
void				ft_putstr_fd(char *s, int fd);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
char				**ft_split(char const *s, char c);

// Stack Operations
void				swap(t_stack **stack);
void				push(t_stack **src, t_stack **dst);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// Operations
int					check_opps(char *opp);
void				apply_opps(char *opp, t_stack **a, t_stack **b);
void				check_order(t_stack *a, t_stack *b);

#endif