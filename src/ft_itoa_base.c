/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:07:11 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/13 16:01:01 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*uns_get_char(unsigned long long value, unsigned long long base)
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

void	uns_itoa_base(unsigned long long value, unsigned long long base, int precision)
{
	(void)precision;
	char *num;
	char *to_free;

	num = uns_get_char(value, base);
	to_free = num;
	if (base == 16)
		write(1, "0x", 2);
	while (*num)
	{
		write(1, &(*num), 1);
		num++;
	}
	free(to_free);
}

char	*get_char(long long value, long long base)
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

void	itoa_base(long long value, long long base, int precision)
{
	(void)precision;
	char *num;
	char *to_free;

	num = get_char(value, base);
	to_free = num;
	while (*num)
	{
		write(1, &(*num), 1);
		num++;
	}
	free(to_free);
}
