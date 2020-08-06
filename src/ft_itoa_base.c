/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:07:11 by rpehkone          #+#    #+#             */
/*   Updated: 2020/01/18 15:36:15 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*get_char(int value, int base)
{
	int		val_cpy;
	int		size;
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

void	itoa_base(int value, int base)
{
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
