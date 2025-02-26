/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:12:25 by anktiri           #+#    #+#             */
/*   Updated: 2025/02/26 12:10:59 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void list_index(t_stack **stack)
{
    t_stack *tmp;
    t_stack *copy;
    int index;

    if (!stack || !(*stack))
        return;
    
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

static void sort_three(t_stack **a)
{
    int first = (*a)->content;
    int second = (*a)->next->content;
    int third = (*a)->next->next->content;

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

static void push_chunks_to_b(t_stack **a, t_stack **b)
{
    int size = ft_stack_size(*a);
    int chunks = (size <= 100) ? 5 : 11;
    int nums_per_chunk = size / chunks;
    int i = 0;
    int pushed = 0;

    // Continue until we've pushed all but 3 elements
    while (ft_stack_size(*a) > 3)
    {
        // Check if we need to adjust chunk boundaries for remaining elements
        if (pushed >= size - 3 - nums_per_chunk)
        {
            // For the final chunk, increase the range to catch all remaining high indices
            if ((*a)->index <= size - 4)
            {
                push(a, b, 'b');
                pushed++;
            }
            else
                rotate(a, 'a', 1);
        }
        else if ((*a)->index <= i)
        {
            push(a, b, 'b');
            rotate(b, 'b', 1);
            i++;
            pushed++;
        }
        else if ((*a)->index <= i + nums_per_chunk)
        {
            push(a, b, 'b');
            i++;
            pushed++;
        }
        else
            rotate(a, 'a', 1);
    }
}

static int find_highest_index(t_stack *stack)
{
    int max_index = INT_MIN;
    while (stack)
    {
        if (stack->index > max_index)
            max_index = stack->index;
        stack = stack->next;
    }
    return max_index;
}

static void push_back_to_a(t_stack **a, t_stack **b)
{
    while (*b)
    {
        int max_index = find_highest_index(*b);
        t_stack *current = *b;
        int pos = 0;
        int i = 0;
        
        while (current && current->index != max_index)
        {
            current = current->next;
            pos++;
        }

        if (pos <= ft_stack_size(*b) / 2)
        {
            while (i++ < pos)
                rotate(b, 'b', 1);
        }
        else
        {
            while (i++ < ft_stack_size(*b) - pos)
                reverse_rotate(b, 'b', 1);
        }
        push(b, a, 'a');
    }
}

void ft_sort(t_stack **a, t_stack **b)
{
    int size = ft_stack_size(*a);
    
    if (size <= 1)
        return;
    
    list_index(a);

    if (size == 2)
    {
        if ((*a)->content > (*a)->next->content)
            swap(a, 'a', 1);
    }
    else if (size == 3)
        sort_three(a);
    else
    {
        push_chunks_to_b(a, b);
        sort_three(a);
        push_back_to_a(a, b);
    }
}
