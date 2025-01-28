/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:46:16 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/20 18:46:16 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL; //Inicializamos ambos a NULL
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0])) //Sintaxis incorrecta en posiciones 0 y 1 del argumento introducido
		return (1);
	else if (argc == 2)
		argv = split(argv[1], ' '); //Si hay 2 argumentos, el siguiente de despues tiene que llevar un espacio
	init_stack_a(&stack_a, argv + 1);
	if (!is_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a, false); //Si hay dos elementos, solo swapea
		else if (stack_len(stack_b) == 3)
			sort_three_elem(&stack_a); //Si hay solo 3 elementos, hace el algoritmo para 3
		else
			sort_stacks(&stack_a, &stack_b); // Y si hay mas entonces hace turk
	}
	free_stack(&stack_a);
	return (0);
}
