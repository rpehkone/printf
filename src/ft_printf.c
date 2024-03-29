/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:19:05 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/14 13:09:06 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modifiers(char *str, int *i, t_settings *settings)
{
	int	did_change;

	did_change = 1;
	while (str[*i] && did_change)
	{
		did_change = 0;
		if (str[*i] == '#' && (did_change++ + 1))
			settings->hash = 1;
		if (str[*i] == '0' && (did_change++ + 1))
			settings->zero = 1;
		if (str[*i] == '-' && (did_change++ + 1))
			settings->negative = 1;
		if (str[*i] == '+' && (did_change++ + 1))
			settings->positive = 1;
		if (str[*i] == ' ' && (did_change++ + 1))
			settings->space = 1;
		if (did_change)
			(*i)++;
	}
}

void	precision(char *str, int *i, t_settings *settings)
{
	if (str[*i] == '.' && ++(*i))
	{
		settings->precision = ft_atoi(&str[*i]);
		while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
	}
	if (str[*i] == 'h' && ++(*i))
		settings->is_short = 1;
	if (str[*i] == 'h' && ++(*i))
		settings->is_short = 2;
	if (str[*i] == 'l' && ++(*i))
		settings->is_long = 1;
	if ((str[*i] == 'l' || str[*i] == 'L') && ++(*i))
		settings->is_long = 2;
}

void	read_flag(char *str, va_list *ap, int *i)
{
	t_settings settings;

	ft_memset((void*)&settings, 0, sizeof(t_settings));
	modifiers(str, i, &settings);
	precision(str, i, &settings);
	if (str[*i] == 'c')
		ft_putchar(va_arg(*ap, int));
	else if (str[*i] == 's')
		ft_putstr(va_arg(*ap, char *));
	else if (str[*i] == 'p')
		print_integer(va_arg(*ap, long long), 16, 0, &settings);
	else if (str[*i] == 'u')
		print_integer(va_arg(*ap, long long), 10, 0, &settings);
	else if (str[*i] == 'd' || str[*i] == 'i')
		print_integer(va_arg(*ap, int), 10, 1, &settings);
	else if (str[*i] == 'o')
		print_integer(va_arg(*ap, long long), 8, 1, &settings);
	else if (str[*i] == 'x')
		print_integer(va_arg(*ap, long long), 16, 1, &settings);
	else if (str[*i] == 'X')
		print_integer(va_arg(*ap, long long), 16, 2, &settings);
	else if (settings.is_long == 2 && str[*i] == 'f')
		print_float(va_arg(*ap, long double), &settings);
	else if (str[*i] == 'f')
		print_float(va_arg(*ap, double), &settings);
	else if (str[*i] == '%')
		write(1, "%", 1);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			read_flag((char*)format, &ap, &i);
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	//va_end(ap);
	return (0);
}
