/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:57:13 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/14 13:22:27 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>







int	ft_ulonglen(unsigned long n)
{
	int i;

	i = 0;
	while (n || !i)
	{
		n /= 10;
		i++;
	}
	return (i);
}

//*
int	power_10(int power)
{
	int i;

	i = 10;
	while (power-- > 1)
		i *= 10;
	return (i);
}

void	handle_rounding(int *n, long double *d, int precision)
{
	int i;
	int len;

	i = 0;
	while (i++ < precision)
		*d *= 10;
	if (((unsigned long)(*d * 10) % 10) > 4)
	{
		len = ft_ulonglen((unsigned long)*d);
		(*d)++;
		if ((ft_ulonglen((unsigned long)*d) != len &&
			(unsigned long)*d % power_10(precision) == 0) || !precision)
		{
			//(*n)++;
			*d = 0;
		}
	}
(void)n;
}

//*/
void	print_float(long double f, t_settings *settings)
{
	int	n;

	int precision = 6;
	if (f < 0)
	{
		write(1, "-", 1);
		f *= -1;
	}
	n = (int)f;
	f -= (unsigned long)f;
	handle_rounding(&n, &f, precision);
	unsigned_itoa_base(n, 10);
	if (precision > 0)
	{
		write(1, ".", 1);
		precision -= ft_ulonglen((unsigned long)f);
		while (precision-- > 0)
			write(1, "0", 1);
		unsigned_itoa_base((unsigned long)f, 10);
	}
	(void)settings;
}
