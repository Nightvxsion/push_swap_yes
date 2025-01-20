/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:39:15 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/20 18:39:15 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*real_a; //Aqui guardamos el puntero directo al nodo 'a' e iteramos apartir de ahi
	t_stack_node	*target_a; //Guardamos el puntero al nodo 'a' (intercambiar, target)
	long			best_match;

	while (b) //Siempre que tengamos nodos en 'b'
	{
		best_match = LONG_MAX; //Asignamos el numnero mas grande/maximo para tener de base un numero maximo
		real_a = a;
		while (real_a)
		{
			if(real_a->nbr < b->nbr && real_a->nbr > best_match) //Si el nodo 'a' actual es menor que los nodos de b && el nodo a mayor que mas maximo
			{
				best_match = real_a->nbr; //Si es asi, actualizamos ese nodo como el minimo de los maximos
				target_a = real_a; // Entonces el nodo actual pasa a ser el nuevo target simultaneamente
			}
			real_a = real_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_a;
		b = b->next;
	}
}

void	init_node_b(t_stack_node *a, t_stack_node* b)
{
	current_index(a);
	current_index(b);
	target_b(a, b);
}
