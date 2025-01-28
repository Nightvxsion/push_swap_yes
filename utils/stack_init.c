/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:44:33 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/28 07:52:22 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static long	ft_atol(const char *a) //Convierte de un ascii a un long
{
	long	output;
	int		flag;

	output = 0;
	flag = 1;
	while (*a == ' ' || *a == '\t' || *a == '\n' ||
			*a == '\r' || *a == '\f' || *a == '\v')
			a++;
	if (*a == '-' || *a == '+')
	{
		if (*a == '-')
			flag = -1;
		a++;
	}
	while (ft_isdigit(*a))
		output = output * 10 + (*a++ - '0');
	return (output * flag);
}

static void	append_nodes(t_stack_node **stack, int n)
{
	t_stack_node	*node; //Guardar un puntero al nuevo nodo creado con el valor n
	t_stack_node	*last; //Puntero directo al ultimo nodo

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;  //Va a ser un unico nodo que vamos a crear
	node->nbr = n; //Aqui asignamos el contenido del nuevo nodo con el valor 'n'
	node->cheap = 0; //Inicializacion en caso de error de valgrind
	if (!(*stack))
	{
		*stack = node; //Enlazar el npdo creado con la lista en general
		node->prev = NULL; //Recordemos que el nodo tiene que ser unico entonces esta desconectado por atras y adelante
	}
	else
	{
		last = find_last_item(*stack);
		last->next = node; //Enlazar el nuevo nodo con el ultimo
		node->prev = last; //Actualizar el antiguo nodo con el nuevo creado
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (err_syntax(argv[i]))
			free_err(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN) //Comprobar overflow de numeros
			free_err(a);
		if (err_duplicate(*a, (int)n))
			free_err(a);
		append_nodes(a, (int)n); //Si pasa los filtros, anexarlos (append)
		i++;
	}
}

t_stack_node	*get_cheap_item(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheap)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ready_to_push(t_stack_node **s, t_stack_node *top, char name)
{
	while(*s != top) //Mientras que el nodo no este en la primera posicion
	{
		if (name == 'a')
		{
			if (top->average)
				ra(s, false);
			else
				rra(s, false);
		}
		else if (name == 'b')
		{
			if (top->average)
				rb(s, false);
			else
				rrb(s, false);
		}
	}
}