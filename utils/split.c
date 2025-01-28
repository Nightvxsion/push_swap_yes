/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:50:04 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/23 09:02:33 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_on_str(char *s1, char c)
{
	int		i; //Iterador principal
	bool	j; //Flag para indicar que estamos dentro de una palabra

	i = 0;
	while (*s1)
	{
		j = false; //Inicializamos la flag en false
		while (*s1 == c) //Si llega al caracter deimitador, estamos en una palabra
			++s1; //Pasamos al siguiente char hasta llegar al final
		while (*s1 != c && *s1) //Si no estamos al final de la palabra pero no hemos llegado tdv al delim_char
		{
			if (!j) {
				++i;
				j = true;
			}
			++s1;
		}
	}
	return (i);
}

static char	*next_word(char *s, char c)
{
	static int	track = 0; //Si hacemos un cambio u otro subproceso, con el static mantenemos su estado donde se quedo
	char		*next_w; //Guardar puntero a la siguiente palabra
	int			len; //Longitud del substring
	int			i; //Iterador principal

	i = 0;
	len = 0;
	while (s[track] == c)
		++track;
	while ((s[track + len] != c) && s[track + len]) //Si al iterar llegamos al delim_char && si llegamos al final de la palabra
		++len; //En len guardamos char-to-char el substring
	next_w = malloc((size_t)len * sizeof(char) + 1);
	if (!next_w)
		return (NULL);
	while ((s[track] != c) && s[track])
		next_w[i++] = s[track++]; //Copìar de track al iterador principal
	next_w[i] = '\0';
	return (next_w);
}


char	**split(char *s, char c)
{
	char	**dest;
	int		i;
	int		word_count;

	i = 0;
	word_count = is_on_str(s, c);
	if (!word_count)
		exit(1);
	dest = malloc(sizeof(char *) * (size_t)(word_count + 2)); //Aloja para el \n y el \0
	if (!dest)
		return (NULL);
	while (word_count-- >= 0) //Mientras que haya mas de una letra itera hacia atras
	{
		if (i == 0)
		{ //Hacer un caso para la primera posicion del string
			dest[i] = malloc(sizeof(char));
			if(!dest[i])
				return (NULL);
			dest[i++][0] = '\0';
			continue ;
		}
		dest[i++] = next_word(s, c);
	}
	dest[i] = NULL;
	return (dest);
}
