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
	else if (ft_strequ(str, "sb"))
		return (sb);
	else if (ft_strequ(str, "ss"))
		return (ss);
	else if (ft_strequ(str, "pa"))
		return (pa);
	else if (ft_strequ(str, "pb"))
		return (pb);
	else if (ft_strequ(str, "ra"))
		return (ra);
	else if (ft_strequ(str, "rb"))
		return (rb);
	else if (ft_strequ(str, "rr"))
		return (rr);
	else if (ft_strequ(str, "rra"))
		return (rra);
	else if (ft_strequ(str, "rrb"))
		return (rrb);
	else if (ft_strequ(str, "rrr"))
		return (rrr);
	return (-1);
}

int			main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		code;

	if (ac < 2)
		return (0);
	a = create_stack();
	fill_stack(a, ac, av);
	b = create_stack();
	while (get_next_line(0, &line))
	{
		code = get_code(line);
		if (code == -1)
		{
			free_stack(b);
			error_and_exit(a);
		}
		call_op(code, a, b, 'm');
	}
	ft_putendl((sorted(a)) ? "\033[1;32mOK" : "\033[1;33mKO");
	ft_putstr("\033[0m");
	free_stack(a);
	free_stack(b);
	return (0);
}
