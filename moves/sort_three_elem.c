/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:22:06 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/20 19:22:06 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three_elem(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = find_max(*a);
	if (biggest == *a) //Una vez enocntrado el numero maximo, en la posicion en la que está justo es, entonces ra
		ra(a, false); 
	else if((*a)->next == biggest) //Si el siguiente nodo de 'a' es el mayor entonces rra
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false); //Si justo la posicion de despues es mayor que el anterior grande, entonces swapea
}