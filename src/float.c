/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:57:13 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/13 22:04:18 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_float(long double f, t_settings *settings)
{
	char *str;
	int i = 0;

	long long n;

	long long test = 100000000000000000;
	n = f * test;
	str = itoa_base(n, 10);
	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == '0')
		i--;
	str[i + 1] = '\0';
	i = 0;
	while (n > test)
	{
		n /= 10;
		write(1 , &str[i], 1);
		i++;
	}
	int printed = 0;
	//exit(0);
	if (i == 0)
	{
		int n2 = n * 10;
		write(1 , "0.", 2);
		while (n2 < test)
		{
			n2 *= 10;
			write(1 , "0", 1);
			printed++;
		}
	}
	else
		write(1 , ".", 1);
	if (settings->precision == 0)
		settings->precision = 6;//mita oikee printf("%.0f") tekee
	//(void)precision;
	//while (str[i])
	while (str[i] && i < settings->precision)
	{
		write(1 , &str[i], 1);
		i++;
		printed++;
	}
	//while (printed < 6)
	while (printed < settings->precision)
	{
			write(1 , "0", 1);
			printed++;
	}
	//printf("%s", str);
	free(str);
}
