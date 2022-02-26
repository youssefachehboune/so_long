/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:33:53 by yachehbo          #+#    #+#             */
/*   Updated: 2021/11/25 22:42:31 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_putnbr_unsigned(unsigned int n, int *cp)
{
	if (n < 10)
		ft_putchar(n + '0', cp);
	else
	{
		ft_putnbr(n / 10, cp);
		ft_putchar((n % 10) + '0', cp);
	}
}
