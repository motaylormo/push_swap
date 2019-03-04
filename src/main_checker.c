/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:23:10 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/03 15:23:13 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_code(char *str)
{
	if (ft_strequ(str, "sa"))
		return (sa);
	if (ft_strequ(str, "sb"))
		return (sb);
	if (ft_strequ(str, "ss"))
		return (ss);
	if (ft_strequ(str, "pa"))
		return (pa);
	if (ft_strequ(str, "pb"))
		return (pb);
	if (ft_strequ(str, "ra"))
		return (ra);
	if (ft_strequ(str, "rb"))
		return (rb);
	if (ft_strequ(str, "rr"))
		return (rr);
	if (ft_strequ(str, "rra"))
		return (rra);
	if (ft_strequ(str, "rrb"))
		return (rrb);
	if (ft_strequ(str, "rrr"))
		return (rrr);
	error_and_exit();
	return (0);
}

int			main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = create_stack();
	b = create_stack();
	fill_stack(a, ac, av);
	while (get_next_line(0, &line))
		call_op(get_code(line), a, b, 'm');
	ft_putendl((sorted(a)) ? "\033[1;32mOK" : "\033[1;33mKO");
	ft_putstr("\033[0m");
	return (0);
}
