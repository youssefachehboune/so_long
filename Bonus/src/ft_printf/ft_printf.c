/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:47:36 by yachehbo          #+#    #+#             */
/*   Updated: 2021/11/25 23:09:49 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_helper(const char *str, va_list args, int i, int *cp)
{
	i++;
	if (str[i] == 'c')
		ft_putchar(va_arg(args, int), cp);
	if (str[i] == 's')
		ft_putstr(va_arg(args, char *), cp);
	if (str[i] == 'p')
	{
		ft_putstr("0x", cp);
		ft_pointer(va_arg(args, unsigned long), "0123456789abcdef", cp);
	}
	if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr(va_arg(args, int), cp);
	if (str[i] == 'u')
		ft_putnbr_unsigned(va_arg(args, int), cp);
	if (str[i] == 'x')
		ft_print_hex(va_arg(args, unsigned long), "0123456789abcdef", cp);
	if (str[i] == 'X')
		ft_print_hex(va_arg(args, unsigned long), "0123456789ABCDEF", cp);
	if (str[i] == '%')
		ft_putchar('%', cp);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			cp;
	va_list		args;

	i = 0;
	cp = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i], &cp);
		else
		{
			ft_helper(str, args, i, &cp);
			i++;
		}
		i++;
	}
	va_end(args);
	return (cp);
}
