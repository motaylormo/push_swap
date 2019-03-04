/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:23:54 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/03 15:23:57 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** Push 1 or 2 minimum values from a to b
** Sorted inversely in b, for when they're flipped when they're moved back to a
*/

static int	push_two_min(t_stack *a, t_stack *b, int len)
{
	int	min_i;
	int	nmin_i;

	min_i = index_of_minmax(min, a, -1);
	nmin_i = index_of_minmax(min, a, min_i);
	if (dist_to_top(nmin_i, len) < dist_to_top(min_i, len))
	{
		move_nth_to_top(a, 'a', nmin_i, len);
		call_op(pb, a, b, 0);
		move_nth_to_top(a, 'a', index_of_minmax(min, a, -1), len - 1);
		call_op(pb, a, b, 0);
		if (ORDERED(b->top->n, b->top->next->n))
			call_op(sb, a, b, 0);
		return (2);
	}
	else
	{
		move_nth_to_top(a, 'a', min_i, len);
		call_op(pb, a, b, 0);
		return (1);
	}
}

void		selection_sort(t_stack *a, t_stack *b, int len)
{
	while (len > 3)
	{
		len -= push_two_min(a, b, len);
	}
	(len == 3) ? sort_stack_of_three(a, 'a') : sort_two(a, 'a');
	while (b->top)
		call_op(pa, a, b, 0);
}
