/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:07:11 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/13 21:59:59 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*unsigned_itoa_base(unsigned long long value, unsigned long long base)
{
	unsigned long long		val_cpy;
	unsigned long long		size;
	char	*str;
	char	*res;

	size = 0;
	str = "0123456789abcdef";
	if (value < 0)
	{
		value *= -1;
		size++;
	}
	val_cpy = value;
	while (val_cpy != 0)
	{
		val_cpy /= base;
		size++;
	}
	if (value < base)
		size++;
	res = (char*)malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	while (size--)
	{
		res[size] = str[value % base];
		value /= base;
	}
	return (res);
}

char	*itoa_base(long long value, long long base)
{
	long long		val_cpy;
	long long		size;
	char	*str;
	char	*res;

	size = 0;
	str = "0123456789abcdef";
	if (value < 0)
	{
		value *= -1;
		size++;
	}
	val_cpy = value;
	while (val_cpy != 0)
	{
		val_cpy /= base;
		size++;
	}
	if (value < base)
		size++;
	res = (char*)malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	while (size--)
	{
		res[size] = str[value % base];
		value /= base;
	}
	return (res);
}

void	print_integer(long long value, long long base, int is_signed, t_settings *settings)
{
	char *num;
	char *to_free;

	if (is_signed)
		num = itoa_base(value, base);
	else
		num = unsigned_itoa_base(value, base);
	to_free = num;
	if (base == 16 && !is_signed)
		write(1, "0x", 2);
	else if (settings->hash && base == 16 && is_signed == 1)
		write(1, "0x", 2);
	else if (settings->hash && base == 16 && is_signed == 2)
		write(1, "0X", 2);
	while (*num)
	{
		write(1, &(*num), 1);
		num++;
	}
	free(to_free);
}
