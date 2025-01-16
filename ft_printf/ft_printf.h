/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:20:55 by marcgar2          #+#    #+#             */
/*   Updated: 2024/11/07 09:14:43 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include "libft.h"

char	ft_printchar(char c);
int		ft_hexalen(unsigned int nbr);
void	ft_calchex(unsigned int num, char const format);
int		ft_totalhex(unsigned int num, char const format);
int		ft_printunsign(unsigned int n);
int		ft_printprcnt(void);
int		ft_formats(va_list elem, const char format);
int		ft_printf(char const *str, ...);

void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printnbr(int a);
int		ft_ptrlen(uintptr_t nbr);
void	ft_ptrcalc(uintptr_t nbr);
int		ft_printptr(unsigned long long nbr);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

#endif
