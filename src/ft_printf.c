/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:19:05 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/13 20:10:04 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modifiers(t_settings *settings, char *str, int *i)
{
	int	did_change;

	did_change = 1;
	while (str[*i] && did_change)
	{
		did_change = 0;
		if (str[*i] == '#' && (did_change++ + 1))
			settings->form = 1;
		if (str[*i] == '0' && (did_change++ + 1))
			settings->padding = 1;
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

void	precision(t_settings *settings, char *str, int *i)
{
	if (str[*i] == 'h' && ++(*i))
		settings->is_short = 1;
	if (str[*i] == 'h' && ++(*i))
		settings->is_short = 2;
	if (str[*i] == 'l' && ++(*i))
		settings->is_long = 1;
	if ((str[*i] == 'l' || str[*i] == 'L') && ++(*i))
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
	modifiers(&settings, str, i);
	precision(&settings, str, i);
	if (str[*i] == 'c')
		ft_putchar(va_arg(ap, int));
	else if (str[*i] == 's')
		ft_putstr(va_arg(ap, char *));
	else if (str[*i] == 'p')
		print_integer(va_arg(ap, long long), 16, &settings, 0);
	else if (str[*i] == 'u')
		print_integer(va_arg(ap, long long), 10, &settings, 0);
	else if (str[*i] == 'd' || str[*i] == 'i')
		print_integer(va_arg(ap, long long), 10, &settings, 1);
	else if (str[*i] == 'o')
		print_integer(va_arg(ap, long long), 8, &settings, 1);
	else if (str[*i] == 'x')
		print_integer(va_arg(ap, long long), 16, &settings, 1);
	else if (str[*i] == 'X')
		print_integer(va_arg(ap, long long), 16, &settings, 2);
	else if (str[*i] == 'f')
		print_float(va_arg(ap, double), &settings);
	else if (str[*i] == '%')
		write(1, "%", 1);
}

int		ft_printf(char *str, ...)
{
	int		i;
	va_list	ap;

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
