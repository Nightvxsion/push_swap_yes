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
		best_match = LONG_MIN; //Asignamos el numnero mas grande/negativo para tener de base un numero negativo
		real_b = b;
		while (real_b)
		{
			if (real_b->nbr < a->nbr && real_b->nbr > best_match) //Si el nodo 'b' actual es menor que los nodos de a && el nodo b mayor que mas negativo
			{
				best_match = real_b->nbr; //Si es asi, actualizamos ese nodo como el maximo de los minimos
				target_b = real_b; // Entonces el nodo actual pasa a ser el nuevo target simultaneamente
			}
			real_b = real_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_b;
		a = a->next;
	}
}

static void	cost_a(t_stack_node *a, t_stack_node *b)
{
	int	leng_a; //Guardar la longitud del nodo a
	int	leng_b; //Guardar la longitud del nodo a

	leng_a = stack_len(a);
	leng_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index; //A cada indice le aplicamos un "costo"
		if (!(a->average)) //Si a (apuntando a b) es "caro"
			a->push_cost = leng_a - (a->index); //Si lo es, hacemos la resta del indice actual menos todo el arreglo y ese sera el costo
		if (a->target_node->average) //Si esta por encima de la media del "costo"
			a->push_cost += a->target_node->index; //Si encuentra uno mas barato va a apuntar a ese
		else //Si a esta por encima de la media del "costo" pero b no
			a->push_cost += leng_b - (a->target_node->index); //Hacemos una mezcla de lo anterior
		a = a->next;
	}
}

void	cheapest(t_stack_node *list)
{
	long			actual_cheapest; //Guardamos el valor del mas barato hasta ahora
	t_stack_node	*cheapest_node; //Guardamos un puntero al nodo mas barato

	if (!list)
		return ;
	actual_cheapest = LONG_MAX;
	while (list)
	{
		if (list->push_cost < actual_cheapest) //Si el valor detectado es mayor que el anterior barato
		{
			actual_cheapest = list->push_cost; //Actualizamos el "costo" de movimiento
			cheapest_node = list; //Y actualizamos su nodo para que acceda directamente al mas barato en tiempo real
		}
		list = list->next;
	}
	cheapest_node->cheap = true; //Si al pasar por todo el stack no hay ninguno mas barato que el que ya etsa entonces true
}

void	init_node_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	target_a(a, b);
	cost_a(a, b);
	cheapest(a);
}

