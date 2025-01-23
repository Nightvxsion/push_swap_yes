/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:55:16 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/20 18:55:16 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_both_stacks(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*b != cheap->target_node && *a != cheap) //Mientras que b no apunte al mas barato de a && a no sea el barato
		rr(a, b, false); //Rotar ambos stacks hacia abajo
	current_index(*a); //Actualizar posiciones
	current_index(*b);
}

static void	rev_rotate_both_stacks(t_stack_node **a, t_stack_node **b, t_stack_node *cheap_again)
{
	while (*b != cheap_again->target_node && *a != cheap_again) //Mientras que b no apunte al mas barato de a && a no sea el barato
		rrr(a, b, false); //Rotar ambos stacks hacia arriba
	current_index(*a); //Actualizar posiciones
	current_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node; //Puntero directo al nodo "barato"

	cheapest_node = get_cheap_item(*a);
	if (cheapest_node->average && cheapest_node->target_node->average) //Si a y b estan por encima de la media
		rotate_both_stacks(a, b, cheapest_node);
	else if (!(cheapest_node->average) && !(cheapest_node->target_node->average)) //Si no lo estan
		rev_rotate_both_stacks(a, b, cheapest_node);
	ready_to_push(a, cheapest_node, 'a'); //Aseguramos a
	ready_to_push(b, cheapest_node->target_node, 'b'); //Apuntamos y luego pusheamos de a a 'b';
	pb(b, a, false);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	ready_to_push(a, (*b)->target_node, 'b'); //Aseguramos que 'b' sea objetivo de 'a'
	pa(a, b, false); //Pusheamos
}

static void min_to_the_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr) //Mientras que el numero mas pequeño no este arriba
	{
		if(find_min(*a)->average) //Si el numero mas pequeño esta por encima de la media
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	leng_a;

	leng_a = stack_len(*a);
	if (leng_a-- > 3 && !is_sorted(*a)) //Si a tiene mas de 3 elementos y no esta ordenado
		pb(b, a, false);
	if (leng_a-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	while (leng_a-- > 3 && !is_sorted(*a)) //Si aun asi sigue sin estar ordenado
	{
		init_node_a(*a, *b); //Inicializamos todos los nodos
		move_a_to_b(a, b); //Los movemos hacia 'b' hasta que hayan 3 sin ordenar
	}
	sort_three_elem(a);
	while(*b)
	{
		init_node_b(*a, *b); //Inicializamos todos los nodos
		move_b_to_a(a, b); //Pasamos de 'b' a 'a' hasta que hayan 3 elementos sin ordenar
	}
	current_index(*a); //Actualizamos la posicion
	min_to_the_top(a); //Aseguramos el nodo minimo arriba del todo
}