/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:57:13 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/13 18:08:50 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

char	*get_char(int value, int base);

int		ft_put_float(float f, t_settings *settings)
{
	char *str;
	int i = 0;

	unsigned long long n;
	n = f * 1000000;
	str = get_char(n, 10);
	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == '0')
		i--;
	str[i + 1] = '\0';
	i = 0;
	while (n > 1000000)
	{
		n /= 10;
		write(1 , &str[i], 1);
		i++;
	}
	int printed = 0;
	if (i == 0)
	{
		int n2 = n * 10;
		write(1 , "0.", 2);
		while (n2 < 1000000)
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



	return (1);
}
