#include "push_swap.h"

void sort_three(t_stack **a)
{
    int first = (*a)->content;
    int second = (*a)->next->content;
    int third = (*a)->next->next->content;

    if (first > second && second < third && first < third) // Case: 2 1 3
        swap(a, 'a');
    else if (first > second && second > third) // Case: 3 2 1
    {
        swap(a, 'a');
        reverse_rotate(a, 'a');
	}
    else if (first > second && second < third && first > third) // Case: 3 1 2
        rotate(a, 'a');
    else if (first < second && second > third && first < third) // Case: 1 3 2
    {
        swap(a, 'a');
		rotate(a, 'a');
    }
    else if (first < second && second > third && first > third) // Case: 2 3 1
		reverse_rotate(a, 'a');
}
