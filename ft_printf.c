/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:19:05 by rpehkone          #+#    #+#             */
/*   Updated: 2020/01/16 17:47:03 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		parse_flag(char *str)
{
	int i;

	i = 0;
	str++;
	while (str[i])
	{
		if (str[i] == '%')
			write(1, "x", 1);
		i++;
	}
	return (i);
}

int		ft_printf(char *str, ...)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i += parse_flag(&str[i]);
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}
