/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:22:54 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/03 15:23:00 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	do_sort(t_stack *a, t_stack *b, int len)
{
	if (len == 1 || sorted(a))
		return ;
	if (len == 2)
		sort_two(a, 'a');
	else if (len == 3)
		sort_stack_of_three(a, 'a');
	else if (len < QUICKSORT_BATCH + 3)
		selection_sort(a, b, len);
	else
		quick_sort(a, b, len);
}

int			main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		stack_len;
	int		flag;

	if (ac < 2)
		return (0);
	flag = 0;
	a = create_stack();
	if (ft_strequ(av[1], "-v"))
	{
		flag = 1;
		av++;
	}
	stack_len = fill_stack(a, ac, av);
	b = create_stack();
	if (a->top)
		do_sort(a, b, stack_len);
	if (flag)
		print_stack(a);
	free_stack(a);
	free_stack(b);
	return (0);
}
