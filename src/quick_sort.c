/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:23:42 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/03 15:23:45 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** Push 1 or 2 maximum values from b to a
** Max numbers go first, so mins end up on top
*/

static int	push_two_max(t_stack *a, t_stack *b, int len)
{
	int	max_i;
	int	nmax_i;

	max_i = index_of_minmax(max, b, -1);
	nmax_i = index_of_minmax(max, b, max_i);
	if (dist_to_top(nmax_i, len) < dist_to_top(max_i, len))
	{
		move_nth_to_top(b, 'b', nmax_i, len);
		call_op(pa, a, b, 0);
		move_nth_to_top(b, 'b', index_of_minmax(max, b, -1), len - 1);
		call_op(pa, a, b, 0);
		if (!ORDERED(a->top->n, a->top->next->n))
			call_op(sa, a, b, 0);
		return (2);
	}
	else
	{
		move_nth_to_top(b, 'b', max_i, len);
		call_op(pa, a, b, 0);
		return (1);
	}
}

static int	get_partition(t_stack *a, t_stack *b, int len, int partition)
{
	int	b_len;

	b_len = 0;
	while (len--)
	{
		if (!ORDERED(a->top->n, partition))
		{
			call_op(pb, a, b, 0);
			b_len++;
		}
		else
			call_op(ra, a, b, 0);
	}
	return (b_len);
}

static void	selection_sort_partition(t_stack *a, t_stack *b, int b_len)
{
	int	i;

	i = 0;
	while (b->top)
		i += push_two_max(a, b, b_len - i);
}

void		quick_sort(t_stack *a, t_stack *b, int len)
{
	int	*pivot;
	int	b_len;
	int	unsorted_len;
	int	batch;
	int	i;

	batch = (len / QUICKSORT_BATCH > 6) ? (len / 6) : QUICKSORT_BATCH;
	unsorted_len = len;
	pivot = get_median(a, len);
	i = 1;
	while (unsorted_len)
	{
		b_len = get_partition(a, b, unsorted_len, pivot[(i * batch)]);
		selection_sort_partition(a, b, b_len);
		unsorted_len -= b_len;
		move_nth_to_top(a, 'a', len - unsorted_len, len);
		i++;
	}
	free(pivot);
}
