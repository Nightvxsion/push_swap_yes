/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:59:22 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/16 17:59:22 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node**src)
{
	t_stack_node	*push_node;

	if (!*src) //Comprobacion basica
		return ;
	push_node = *src; //Asignamos la lista de origen a la referencia de la lista original "t_stack_node"
	*src = (*src)->next; //Pasamos a la siguiente posicion para tenerlo de cabecera a posteriori
	if (*src)
		(*src)->prev = NULL; //SI existe la lista de origen, asignamos el nodo anterior (primera posicion) a NULL para hacer la verdadera cabecera
	push_node->prev = NULL; //Separar el nodo anterior para pushearlo
	if (!*dst) //Si el otro stack esta vacio
	{
		*dst = push_node; //Si lo es, asignamos el nodo de ese stack para pushearlo
		push_node->next = NULL; //Asegurarnos de que estamos en el nodo a pushear
	}
	else //Si el otro stack a pushear no esta vacio
	{
		push_node->next = *dst; //Asiganr el nodo a pushear arriba de todo lo que tenemos
		push_node->next->prev = push_node; //Asiganr el nodo que tenemos a pushear el "previo" como el primero
		*dst = push_node; //Ahora el nodo de arriba del todo está apuntando al del otro stack completando el push
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool manifest)
{
	push(a, b);
	if (!manifest)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool manifest)
{
	push(b, a);
	if (!manifest)
		ft_printf("pb\n");
}