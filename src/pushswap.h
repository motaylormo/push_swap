/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:43:37 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/27 19:20:17 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>

/*
** To get descending order rather than ascending, replace it with:
** ORDERED(a, b) (a > b)
*/
# define ORDERED(a, b) (a <= b)
# define QUICKSORT_BATCH 25

typedef struct	s_node
{
	int				n;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	t_node	*top;
}				t_stack;

enum	e_minmax{
	min,
	max
};

enum	e_operations{
	sa = 1,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

t_stack			*create_stack(void);
t_node			*create_node(int num);
int				fill_stack(t_stack *s, int ac, char **av);

int				sorted(t_stack *s);
void			print_stack(t_stack *s);

void			call_op(int code, t_stack *a, t_stack *b, int print);

void			quick_sort(t_stack *a, t_stack *b, int len);
void			selection_sort(t_stack *a, t_stack *b, int len);
int				index_of_minmax(int code, t_stack *s, int i_exception);
void			move_nth_to_top(t_stack *s, char code, int nth, int len);
void			sort_two(t_stack *s, char code);
int				dist_to_top(int nth, int len);
void			sort_stack_of_three(t_stack *s, char code);
int				*get_median(t_stack *s, int len);

void			check_for_duplicates(t_stack *s);
void			check_is_integer(char *str);
void			error_and_exit(void);

#endif
