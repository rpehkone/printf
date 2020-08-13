/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:19:05 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/13 18:11:21 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
*/

void	manage_long(char *str, va_list ap, int *i, int precision)
{
	(void)precision;
	(void)str;
	(void)ap;
		if (str[*i] == 'h')
			i++;
		//mita jos vaan h
	
}

void	manage_short(char *str, va_list ap, int *i, int precision)
{
	(void)precision;
	(void)str;
	(void)ap;
		if (str[*i] == 'h')
			i++;
		//mita jos vaan h
	
}

/*
		 Modifier          d, i           o, u, x, X
         hh                signed char    unsigned char
         h                 short          unsigned short
         l (ell)           long           unsigned long
         ll (ell ell)      long long      unsigned long long
*/
	//h on short
	//hh short short eli char
	//l = long
	//ll long long
	//else

void	set_precision(int *precision, char *str, int *i)
{
	(*i)++;
	(*precision) = ft_atoi(&str[*i]);	
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		(*i)++;
	}
}

void	make_settings(t_settings *settings, char *str, int *i)
{
	settings->precision = 0;
	settings->form = 0;
	settings->padding = 0;
	settings->negative = 0;
	settings->positive = 0;
	settings->space = 0;
	if (str[*i] == '.')
	{
		(*i)++;
		settings->precision = ft_atoi(&str[*i]);	
		while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
	}
//		set_precision(, str, i);
	if (str[*i] == '#')
		settings->form = 1;
	if (str[*i] == '0')
		settings->padding = 1;//toinen pois
	if (str[*i] == '-')
		settings->negative = 1;
	if (str[*i] == '+')
		settings->positive = 1;
	if (str[*i] == ' ')
		settings->space = 1;
}

void	read_flag(char *str, va_list ap, int *i)
{
	t_settings settings;

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
	else if (str[*i] == 'x' || str[*i] == 'X')
		itoa_base(va_arg(ap, long long), 16, &settings);//unisigned hexadecimal
	else if (str[*i] == 'f')
		ft_put_float(va_arg(ap, double), &settings);
	else if (str[*i] == '%')
		write(1, "%", 1);
	/*
	else if (str[*i] == 'h')
		manage_short(str, ap, i, settings);//bitshift tassa
	else if (str[*i] == 'l')
		manage_long(str, ap, i, settings);
		*/
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
