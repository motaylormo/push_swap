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

t_stack		*create_stack(void)
{
	t_stack	*stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		error_and_exit();
	stack->top = NULL;
	return (stack);
}

t_node		*create_node(int num)
{
	t_node	*node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		error_and_exit();
	node->n = num;
	node->next = NULL;
	return (node);
}

static void	push_to_bottom(t_stack *s, t_node *new)
{
	t_node	*node;

	if (!s->top)
	{
		s->top = new;
		return ;
	}
	node = s->top;
	while (node && node->next)
		node = node->next;
	node->next = new;
}

void		free_stack(t_stack *s)
{
	t_node	*node;

	while (s->top)
	{
		node = s->top;
		s->top = (node->next) ? node->next : NULL;
		free(node);
	}
	free(s);
	s = NULL;
}

int			fill_stack(t_stack *s, int ac, char **av)
{
	int		len;
	char	*str;
	int		i;

	if (ac < 2)
		return (0);
	i = 1;
	str = av[i++];
	len = 0;
	while (*str)
	{
		check_is_integer(str);
		push_to_bottom(s, create_node(ft_atoi(str)));
		len++;
		if (ft_strchr(str, ' '))
			str = ft_strchr(str, ' ') + 1;
		else if (i < ac)
			str = av[i++];
		else
			break ;
	}
	check_for_duplicates(s);
	return (len);
}
