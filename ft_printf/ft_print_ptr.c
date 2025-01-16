/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:04:19 by marcgar2          #+#    #+#             */
/*   Updated: 2024/10/31 20:08:45 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_ptrlen(uintptr_t nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (write(1, "(nil)", 5));
	while (nbr != 0)
	{
		i++;
		nbr /= 16;
	}
	return (i);
}

void	ft_ptrcalc(uintptr_t nbr)
{
	if (nbr >= 16)
	{
		ft_ptrcalc(nbr / 16);
		ft_ptrcalc(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
			ft_putchar_fd((nbr - 10 + 'a'), 1);
	}
}

int	ft_printptr(unsigned long long nbr)
{
	int	ptr_output;

	ptr_output = 0;
	if (!nbr)
		return ((write(1, "(nil)", 5)));
	ptr_output += write(1, "0x", 2);
	ft_ptrcalc(nbr);
	ptr_output += ft_ptrlen(nbr);
	return (ptr_output);
}
