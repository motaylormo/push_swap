/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:04:07 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/03 13:04:09 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		error_and_exit(t_stack *s)
{
	free_stack(s);
	ft_putendl("\033[0;31mError");
	ft_putstr("\033[0m");
	exit(1);
}

void		check_for_duplicates(t_stack *s)
{
	t_node	*node;
	t_node	*inner;
	int		curr_num;
	int		tally;

	node = s->top;
	while (node)
	{
		curr_num = node->n;
		tally = 0;
		inner = s->top;
		while (inner)
		{
			if (inner->n == curr_num)
				tally++;
			inner = inner->next;
		}
		if (tally != 1)
			error_and_exit(s);
		node = node->next;
	}
}

void		check_is_integer(char *str, t_stack *s)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str != ' ')
	{
		if (!ft_isdigit(*str))
			error_and_exit(s);
		num = (num * 10) + (*str - '0');
		str++;
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			error_and_exit(s);
	}
}
