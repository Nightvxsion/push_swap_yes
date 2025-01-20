/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:50:46 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/16 18:50:46 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_item(*stack);
	last_node->next = *stack; //Asigna el 'next' como top de la lista, haciendolo top y ultimo nodo a la vez
	*stack = (*stack)->next; //Asigna a la siguiente posicion para saber que 2 nodos tiene que rotar
	(*stack)->prev = NULL; //Nos aseguramos de lo anterior
	last_node->prev->next = last_node; //Reconectamos el segundo puntero que estaba en la posicion de prev a la actual
	last_node->next->next = NULL; //Nos aseguramos de que la rotacion este terminado en NULL
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}