/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:24:56 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/26 18:26:59 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_d_i(int n)
{
	int	nbr;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		nbr = 11;
	}
	else
		nbr = ft_putnbr_printf(n);
	return (nbr);
}