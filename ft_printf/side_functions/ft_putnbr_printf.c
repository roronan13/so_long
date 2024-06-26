/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:41:30 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/26 18:26:04 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_printf(int n)
{
	char	a;
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		i++;
	}
	if (n <= 9)
	{
		a = 48 + n;
		write(1, &a, 1);
		i++;
	}
	else
	{
		i += ft_putnbr_printf(n / 10);
		i += ft_putnbr_printf(n % 10);
	}
	return (i);
}
