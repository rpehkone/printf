/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:57:13 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/14 13:08:21 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
void	print_fraction(long long f)
{
	char	*str;
	int		i;

	printf("\nf = %llu\n", f);
	f = f << 11;
	//f *= 1000000;
	printf("\nf = %llu\n", f);
	//f = f >> 11;
	printf("\nf = %llu\n", f);
	str = itoa_base(f, 10);
	i = 0;
	while (str[i])
	{
		write(1 , &str[i], 1);
		i++;
	}
	free(str);
}

void	print_integer_part(int f)
{
	char	*str;
	int		i;

	str = itoa_base(f, 10);
	i = 0;
	while (str[i])
	{
		write(1 , &str[i], 1);
		i++;
	}
	free(str);
}

void	print_float(long double f, t_settings *settings)
{
	print_integer_part(f);
	if (f < 0)
		f *= -1;
	write(1 , ".", 1);
	print_fraction(f);
	(void)settings;
}
