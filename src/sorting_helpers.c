/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:24:49 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/03 15:24:52 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		index_of_minmax(int code, t_stack *s, int i_exception)
{
	t_node	*node;
	int		i;
	int		most;
	int		most_i;

	node = s->top;
	most = node->n;
	i = 0;
	while (node)
	{
		if ((i != i_exception) &&
			(code == max) ? !ORDERED(node->n, most) : ORDERED(node->n, most))
		{
			most = node->n;
			most_i = i;
		}
		i++;
		node = node->next;
	}
	return (most_i);
}

void	move_nth_to_top(t_stack *s, char code, int nth, int len)
{
	if (nth + 1 > len / 2)
		while (nth++ < len)
			(code == 'a') ? call_op(rra, s, NULL, 0) : call_op(rrb, NULL, s, 0);
	else
		while (nth--)
			(code == 'a') ? call_op(ra, s, NULL, 0) : call_op(rb, NULL, s, 0);
}

int		dist_to_top(int nth, int len)
{
	return ((nth + 1 > len / 2) ? len - nth : nth);
}

void	sort_two(t_stack *s, char code)
{
	if (!ORDERED(s->top->n, s->top->next->n))
		(code == 'a') ? call_op(sa, s, NULL, 0) : call_op(sb, NULL, s, 0);
}

void	sort_stack_of_three(t_stack *s, char code)
{
	int	min_i;

	min_i = index_of_minmax(min, s, -1);
	if (min_i == 0 && !sorted(s))
	{
		(code == 'a') ? call_op(rra, s, NULL, 0) : call_op(rrb, NULL, s, 0);
		sort_two(s, code);
	}
	if (min_i == 1)
	{
		if (!ORDERED(s->top->n, s->top->next->next->n))
			(code == 'a') ? call_op(ra, s, NULL, 0) : call_op(rb, NULL, s, 0);
		else
			sort_two(s, code);
	}
	if (min_i == 2)
	{
		if (!ORDERED(s->top->n, s->top->next->next->n))
			sort_two(s, code);
		(code == 'a') ? call_op(rra, s, NULL, 0) : call_op(rrb, NULL, s, 0);
	}
}
