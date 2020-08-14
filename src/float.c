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
void	print_fraction(long long f)
{
	printf("\nf = %llu\n", f);
	f = f << 11;
	//f *= 1000000;
	printf("\nf = %llu\n", f);
	//f = f >> 11;
	printf("\nf = %llu\n", f);
	
}

void	print_float(long double f, t_settings *settings)
{
	itoa_base((int)f, 10);
	if (f < 0)
		f *= -1;
	write(1 , ".", 1);
	print_fraction(f);
	(void)settings;
}
