/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:22:32 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/03 15:22:35 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		sorted(t_stack *s)
{
	t_node	*node;
	int		sorted;

	sorted = 0;
	node = s->top;
	while (node && node->next)
	{
		if (node->n > node->next->n)
			sorted++;
		node = node->next;
	}
	return ((sorted == 0) ? 1 : 0);
}

void	print_stack(t_stack *s)
{
	t_node	*node;

	node = s->top;
	while (node)
	{
		ft_putnbr(node->n);
		ft_putchar('\n');
		node = node->next;
	}
}
