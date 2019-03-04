/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:22:10 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/26 15:30:57 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** Swap the first 2 elements at the top of stack.
** Do nothing if there is only one or no elements.
*/

static int	swap(t_stack *s)
{
	int	n1;
	int	n2;

	if (!(s->top && s->top->next))
		return (0);
	n1 = s->top->n;
	n2 = s->top->next->n;
	s->top->n = n2;
	s->top->next->n = n1;
	return (1);
}

/*
** Take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/

static int	push(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!b->top)
		return (0);
	node = b->top;
	b->top = b->top->next;
	node->next = a->top;
	a->top = node;
	return (1);
}

/*
** Shift up all elements of stack a by 1.
** The first element becomes the last one.
**
** (1) 2 3 4 ^		2 3 4 1
**  |        |
**  ----------
*/

static int	rotate(t_stack *s)
{
	t_node	*first;
	t_node	*curr;

	if (!(s->top && s->top->next))
		return (0);
	first = s->top;
	s->top = s->top->next;
	curr = s->top;
	while (curr->next)
		curr = curr->next;
	curr->next = first;
	first->next = NULL;
	return (1);
}

/*
** Shift down all elements of stack b by 1.
** The last element becomes the first one.
**
** ^ 1 2 3 (4)		4 1 2 3
** |        |
** ----------
*/

static int	reverse_rotate(t_stack *s)
{
	t_node	*last;
	t_node	*pre_last;

	if (!(s->top && s->top->next))
		return (0);
	last = s->top;
	while (last->next)
	{
		pre_last = last;
		last = last->next;
	}
	pre_last->next = NULL;
	last->next = s->top;
	s->top = last;
	return (1);
}

static char	*g_print_code[] = {
	[sa] = "sa",
	[sb] = "sb",
	[ss] = "ss",
	[pa] = "pa",
	[pb] = "pb",
	[ra] = "ra",
	[rb] = "rb",
	[rr] = "rr",
	[rra] = "rra",
	[rrb] = "rrb",
	[rrr] = "rrr"
};

void		call_op(int code, t_stack *a, t_stack *b, int print)
{
	int	ret;

	if (code == sa || code == ss)
		ret = swap(a);
	if (code == sb || code == ss)
		ret = swap(b);
	if (code == pa)
		ret = push(a, b);
	if (code == pb)
		ret = push(b, a);
	if (code == ra || code == rr)
		ret = rotate(a);
	if (code == rb || code == rr)
		ret = rotate(b);
	if (code == rra || code == rrr)
		ret = reverse_rotate(a);
	if (code == rrb || code == rrr)
		ret = reverse_rotate(b);
	if (ret == 1 && print != 'm')
		ft_putendl(g_print_code[code]);
}
