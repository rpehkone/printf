/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:19:05 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/13 18:49:02 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_settings(t_settings *settings, char *str, int *i)
{
	if (str[*i] == '#' && (*i)++)
		settings->form = 1;
	if (str[*i] == '0' && ++(*i))
		settings->padding = 1;//toinen pois
	if (str[*i] == '-' && ++(*i))
		settings->negative = 1;
	if (str[*i] == '+' && ++(*i))
		settings->positive = 1;
	if (str[*i] == ' ' && ++(*i))
		settings->space = 1;
	if (str[*i] == 'h' && ++(*i))
		settings->is_short = 1;
	if (str[*i] == 'h' && ++(*i))
		settings->is_short = 2;
	if (str[*i] == 'l' && ++(*i))
		settings->is_long = 1;
	if ((str[*i] == 'l' || str[*i] == 'L')&& ++(*i))
		settings->is_long = 2;
	if (str[*i] == '.' && ++(*i))
	{
		settings->precision = ft_atoi(&str[*i]);	
		while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
	}
}

void	read_flag(char *str, va_list ap, int *i)
{
	t_settings settings;

	ft_memset((void*)&settings, 0, 8 * sizeof(int));
	make_settings(&settings, str, i);
	if (str[*i] == 'c')
		ft_putchar(va_arg(ap, int));
	else if (str[*i] == 's')
		ft_putstr(va_arg(ap, char *));
	else if (str[*i] == 'p')
		uns_itoa_base(va_arg(ap, unsigned long long), 16, &settings);
	else if (str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'u')
		itoa_base(va_arg(ap, long long), 10, &settings);
	else if (str[*i] == 'o')
		itoa_base(va_arg(ap, long long), 8, &settings);//unnsigned octal
	else if (str[*i] == 'x' || str[*i] == 'X')//0x tai 0X
		itoa_base(va_arg(ap, long long), 16, &settings);//unisigned hexadecimal
	else if (str[*i] == 'f')
		ft_put_float(va_arg(ap, double), &settings);
	else if (str[*i] == '%')
		write(1, "%", 1);
}

int		ft_printf(char *str, ...)
{
	int i;
	va_list ap;

	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			read_flag(str, ap, &i);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (0);
}
