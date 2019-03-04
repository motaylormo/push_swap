/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:03:08 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/25 16:31:39 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack*)malloc(sizeof(stack));
	stack->top = NULL;
	return (stack);
}

t_node	*create_node(int num)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(node));
	node->n = num;
	node->next = NULL;
	return (node);
}

int		fill_stack(t_stack *s, int ac, char **av)
{
	t_node	*node;
	char	**str;
	int		i;

	if (ac == 2)
		str = ft_strsplit(av[1], ' ');
	else
		str = av + 1;
	i = 0;
	while (str[i])
	{
		check_is_integer(str[i]);
		if (i == 0)
		{
			s->top = create_node(ft_atoi(str[i++]));
			node = s->top;
		}
		else
		{
			node->next = create_node(ft_atoi(str[i++]));
			node = node->next;
		}
	}
	check_for_duplicates(s);
	return (i);
}
