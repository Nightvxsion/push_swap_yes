/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:26:37 by marcgar2          #+#    #+#             */
/*   Updated: 2024/11/07 09:14:26 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
int	ft_printunsign(unsigned int n)
{
	char	str[12];
	int		leng;
	int		i;

	leng = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		str[leng++] = (n % 10) + '0';
		n /= 10;
	}
	i = leng;
	while (leng > 0)
		write(1, &str[--leng], 1);
	return (i);
}

/*int	main(void)
{
	unsigned int	n;
	int				a;

	n = 0;
	a = ft_printunsign(n);
	printf("Resultado de unsigned -> %u\n", n);
	return (0);
}*/