/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:29:32 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/16 17:29:32 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int					nbr; //Numeros a ordenar
	int					index; //Posicion en el stack
	int					push_cost; //Comandos en total
	bool				average; //se usa para calcular "push_cost" TURK ALGORITHM
	bool				cheap; //El nodo mas barato en operaciones TURK ALGORITHM
	struct s_stack_node	*target_node; //El objetivo del nodo del otro stack
	struct s_stack_node	*next; //Puntero al siguiente nodo
	struct s_stack_node	*prev; //Puntero al nodo previo
}	t_stack_node;

//MOVES
void			sa(t_stack_node **stack, bool print);
void			sb(t_stack_node **stackb, bool print);
void			ss(t_stack_node **stack, t_stack_node **stackb, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool manifest);
void			pb(t_stack_node **b, t_stack_node **a, bool manifest);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

//UTILS
t_stack_node	*find_last_item(t_stack_node *stack);

//ERRORS
int				err_syntax(char	*str);
int				err_duplicate(t_stack_node *a, int i);
void			free_stack(t_stack_node **stack);
void			free_err(t_stack_node **a);

//NODES INIT
void			init_stack_a(t_stack_node **a, char **argv);
t_stack_node	*get_cheap_item(t_stack_node *stack);
void			ready_to_push(t_stack_node **s, t_stack_node *top, char name);

#endif