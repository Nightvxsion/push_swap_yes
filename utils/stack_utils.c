/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:58:26 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/16 18:58:26 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack_node	*find_last_item(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next; //Loopea hasta encontrar el ultimo nodo de la lista
	return (stack);
}

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr) //Indica si esta fuera de nuestro rango de orden
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *stack) //Consigue el numero mas pequeño de todos los dados
{
	long			min;
	t_stack_node	*abs_min;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min) //Comprueba si el numero dado es menor que todos los que tenemos con nbr
		{
			min = stack->nbr; //Actualiza el numero como numero mas pequeño
			abs_min = stack; //Y lo enlaza con un puntero al numero mas pequeño
		}
		stack = stack->next;
	}
	return (abs_min);
}

t_stack_node	*find_max(t_stack_node *stack) //Consigue el numero mas grande de todos los dados
{
	long			max;
	t_stack_node	*abs_max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max) //Comprueba si el numero dado es mayor que todos los que tenemos con nbr
		{
			max = stack->nbr; //Actualiza el numero como numero mas grande
			abs_max = stack; //Y lo enlaza con un puntero al numero mas grande
		}
		stack = stack->next;
	}
	return (abs_max);
}
