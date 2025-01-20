/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:21:03 by marcgar2          #+#    #+#             */
/*   Updated: 2024/11/06 21:27:17 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
int	ft_formats(va_list elem, const char format)
{
	int	format_espec;

	format_espec = 0;
	if (format == 'c')
		format_espec += ft_printchar(va_arg(elem, int));
	else if (format == 's')
		format_espec += ft_printstr(va_arg(elem, char *));
	else if (format == 'p')
		format_espec += ft_printptr(va_arg(elem, unsigned long long));
	else if (format == 'd' || format == 'i')
		format_espec += ft_printnbr(va_arg(elem, int));
	else if (format == 'u')
		format_espec += ft_printunsign(va_arg(elem, unsigned int));
	else if (format == 'x' || format == 'X')
		format_espec += ft_totalhex(va_arg(elem, unsigned int), format);
	else if (format == '%')
		format_espec += ft_printprcnt();
	else
		return (-1);
	return (format_espec);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		leng;
	int		res;
	va_list	elem;

	i = 0;
	leng = 0;
	res = 0;
	va_start(elem, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			res = ft_formats(elem, str[i + 1]);
			if (res == -1)
				return (-1);
			leng += res;
			i++;
		}
		else
			leng += ft_printchar(str[i]);
		i++;
	}
	va_end(elem);
	return (leng);
}

/*int	main(void)
{
	ft_printf(" %u ", 0);
	ft_printf(" %u ", LONG_MIN);

	//char	character = 'A';
	//char	*string = "HELLO WORLD";
	//void	*void_ptr = NULL;
	//int	number = 420;
	//unsigned int	unsigned_number = 420;
	//int	number_i = 420;
	//int	hex_number_lowercase = 420;
	//int	hex_number_uppercase = 420;
	//int	n;
	////%Character%
	//n = printf("CHAR printf()            = %c", character);
	//printf(" (%d)\n", n);
	//n = ft_printf("CHAR ft_printf()         = %c", character);
	//printf(" (%d)\n\n", n);
	
	////%String%
	//n = printf("STRING printf()          = %s", string);
	//printf(" (%d)\n", n);
	//n = ft_printf("STRING ft_printf()       = %s", string);
	//printf(" (%d)\n\n", n);
	
	////%Pointer%
	//n = printf("PTR ADDRESS printf()     = %p", &void_ptr);
	//printf(" (%d)\n", n);
	//n = ft_printf("PTR ADDRESS ft_printf()  = %p", &void_ptr);
	//printf(" (%d)\n\n", n);
	
	////%Pointer (nil)%
	//n = printf("PTR (NIL) printf()       = %p", void_ptr);
	//printf(" (%d)\n", n);
	//n = ft_printf("PTR (NIL) ft_printf()    = %p", void_ptr);
	//printf(" (%d)\n\n", n);
	
	////%Signed Decimal%
	//n = printf("SIGNED DEC printf()      = %d", number);
	//printf(" (%d)\n", n);
	//n = ft_printf("SIGNED DEC ft_printf()   = %d", number);
	//printf(" (%d)\n\n", n);
	
	////%Unsigned Integer%
	//n = printf("UNSIGNED INT printf()    = %i", number_i);
	//printf(" (%d)\n", n);
	//n = ft_printf("UNSIGNED INT ft_printf() = %i", number_i);
	//printf(" (%d)\n\n", n);
	
	////%unsigned decimal%
	//n = printf("UNSIGNED DEC printf()    = %u", unsigned_number);
	//printf(" (%d)\n", n);
	//n = ft_printf("UNSIGNED DEC ft_printf() = %u", unsigned_number);
	//printf(" (%d)\n\n", n);
	
	////%Hexadecimal Lowercase%
	//n = printf("HEX LOW printf()         = %x", hex_number_lowercase);
	//printf(" (%d)\n", n);
	//n = ft_printf("HEX LOW ft_printf()      = %x", hex_number_lowercase);
	//printf(" (%d)\n\n", n);
	
	////%Hexadecimal Uppercase%
	//n = printf("HEX UP printf()          = %X", hex_number_uppercase);
	//printf(" (%d)\n", n);
	//n = ft_printf("HEX UP ft_printf()       = %X", hex_number_uppercase);
	//printf(" (%d)\n\n", n);
	
	////%Percentage%
	//n = printf("PERCENTAGE printf()      = %% ");
	//printf(" (%d)\n", n);
	//n = ft_printf("PERCENTAGE ft_printf()   = %% ");
	//printf(" (%d)\n\n", n);
	
	////%ERROR HANDLING%
	//n = printf("NO MODIFIER printf()     = %");
	//printf(" (%d)\n", n);
	//n = ft_printf("NO MODIFIER ft_printf()  = %");
	//printf(" (%d)\n\n", n);
	
	////%REMIX-1%
	//n = printf("printf()                 = %s %", string);
	//printf(" (%d)\n", n);
	//n = ft_printf("ft_printf()              = %s %", string);
	//printf(" (%d)\n\n", n);

}*/
