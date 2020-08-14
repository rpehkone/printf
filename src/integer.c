/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:07:11 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/14 14:58:08 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_itoa_base(unsigned long long value, unsigned long long base)
{
	unsigned long long		val_cpy;
	unsigned long long		size;
	char			*str;

	size = 1;
	str = "0123456789abcdef";
	val_cpy = value;
	while (val_cpy != 0)
	{
		val_cpy /= base;
		size *= base;
	}
	while (size > 1)
	{
		value %= size;
		size /= base;
		write(1, &str[value / size], 1);
	}
}

void	itoa_base(long long value, long long base)
{
	long long		val_cpy;
	long long		size;
	char			*str;

	size = 1;
	str = "0123456789abcdef";
	if (value < 0)
	{
		value *= -1;
		write(1, "-", 1);
	}
	val_cpy = value;
	while (val_cpy != 0)
	{
		val_cpy /= base;
		size *= base;
	}
	while (size > 1)
	{
		value %= size;
		size /= base;
		write(1, &str[value / size], 1);
	}
}

void	print_integer(long long value, long long base, int is_signed, t_settings *settings)
{
	//write(1, "\n\n", 2);
	//itoa_base(123, 10);
	//exit(0);
	if (base == 16 && !is_signed)
		write(1, "0x", 2);
	else if (settings->hash && base == 16 && is_signed == 1)
		write(1, "0x", 2);
	else if (settings->hash && base == 16 && is_signed == 2)
		write(1, "0X", 2);
	if (is_signed)
		itoa_base(value, base);
	else
		unsigned_itoa_base(value, base);
}
