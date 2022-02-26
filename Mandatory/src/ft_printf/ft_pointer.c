/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:28:36 by yachehbo          #+#    #+#             */
/*   Updated: 2021/11/25 22:37:57 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_pointer(unsigned long n, const char *base, int *cp)
{
	if (n >= 16)
		ft_pointer(n / 16, base, cp);
	ft_putchar(base[n % 16], cp);
}
