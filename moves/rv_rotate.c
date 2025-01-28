/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rv_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:10:10 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/16 19:10:10 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last_item(*stack);
	last->prev->next = NULL; //Asignamos el atributo 'next' y lo igualamos a NULL para que se convierta en el ultimo nodo
	last->next = *stack; //Asignamos el atributo 'next' en la misma posicion para hacer el nuevo top
	last->prev = NULL; //Lo desenganchamos antes de hacer nada
	*stack = last; //Apuntamos hacia la posicion inicial desde el ultimo nodo asegurado
	last->next->prev = last; //Actualizamos la posicion del ultimo nodo
}

void	rra(t_stack_node **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}