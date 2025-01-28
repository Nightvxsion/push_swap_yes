/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:47:06 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/16 17:47:06 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap(t_stack_node **top)
{
	if (!*top || !(*top)->next)
		return ;
	*top = (*top)->next; //Actualiza a la siguiente posicion
	(*top)->prev->prev = *top; //Actualiza 2 posiciones atras para apuntar a la posicion a swapear
	(*top)->prev->next = (*top)->next; //Actualiza a la siguiente posicion despues de la anterior y lo reemplaza por la hay que swapear
	if ((*top)->next) //Si hay un nodo a swapear despues de la posicion actual
		(*top)->next->prev = (*top)->prev; //Si es asi, lo ponemos a apunar el nodo prev al de atras del top
	(*top)->next = (*top)->prev; //Apuntamos al nodo prev y a su vez al nodo siguiente 
	(*top)->prev = NULL; //Ponemos el nodo prev en NULL por los leaks
}

void	sa(t_stack_node **stack, bool print)
{
	swap(stack);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **stackb, bool print)
{
	swap(stackb);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **stack, t_stack_node **stackb, bool print)
{
	swap(stack);
	swap(stackb);
	if (!print)
		ft_printf("ss\n");
}