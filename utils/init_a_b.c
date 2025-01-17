/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:40:31 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/17 10:08:52 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i; //Iterador para guardar el valor del indice actual
	int	median; //Iterador para calcular la mitad de los 'n' elementos

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2; //Calcula la media hacia arriba o abajo
	while (stack)
	{
		stack->index = i; //Guarda la posicion actual del nodo
		if (i <= median)
			stack->average = true; //Detecta que el nodo actual esta por encima de la mitad del stack
		else
			stack->average = false; //Esta de mitad para abajo
		stack = stack->next; //Pasamos al siguiente valor
		++i;
	}
}

static void	target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*real_b; //Aqui guardamos el puntero directo al nodo 'b' e iteramos apartir de ahi
	t_stack_node	*target_b; //Guardamos el puntero al nodo 'b' (intercambiar, target)
	long			best_match;

	while (a) //Siempre que tengamos nodos en 'a'
	{
		best_match = LONG_MIN; //Asignamos el numnero mas grande/negativo para tener de base un numero maximo
		real_b = b;
		while (real_b)
		{
			if(real_b->nbr < a->nbr && real_b->nbr > best_match) //Si el nodo 'b' actual es menor que los nodos de a && el nodo b mayor que mas negativo
			{
				best_match = real_b->nbr; //Si es asi, actualizamos ese nodo como el maximo de los minimos
				target_b = real_b; // Entonces el nodo actual pasa a ser el nuevo target simultaneamente
			}
			real_b = real_b->next;
			if (best_match == LONG_MIN)
				a->target_node = find_max(b);
			else
				a->target_node = target_b;
			a = a->next;
		}
	}
}

