/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:24:35 by marcgar2          #+#    #+#             */
/*   Updated: 2024/10/31 19:30:27 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}
/*int main(void)
{
	char a = 'a';
	char total;
	total = ft_printchar(a);
	printf("%c\n", total);
	return 0;
}*/
