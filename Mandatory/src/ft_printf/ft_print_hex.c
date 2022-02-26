/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:35:47 by yachehbo          #+#    #+#             */
/*   Updated: 2021/11/25 22:41:33 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_print_hex(unsigned int n, const char *base, int *cp)
{
	if (n < 16)
		ft_putchar(base[n], cp);
	else
	{
		ft_print_hex(n / 16, base, cp);
		ft_putchar(base[n % 16], cp);
	}
}
