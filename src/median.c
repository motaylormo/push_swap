/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 10:38:41 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/02 10:38:42 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** Yes, I use a bubble sort here so I can do a more efficient sort later.
** And yes, I did specifically chose a bubble sort out of spite.
*/

static void	bubble_sort_array(int *array, int len)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 1;
		while (j < len)
		{
			if (ORDERED(array[j - 1], array[j]))
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int			*get_median(t_stack *s, int len)
{
	int		*array;
	int		i;
	t_node	*node;

	array = (int*)malloc(sizeof(int) * len);
	node = s->top;
	i = 0;
	while (i < len)
	{
		array[i++] = node->n;
		node = node->next;
	}
	bubble_sort_array(array, len);
	return (array);
}
