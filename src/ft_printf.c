/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:19:05 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/12 18:57:39 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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

void	manage_long(char *str, va_list ap, int *i)
{
	(void)str;
	(void)ap;
		if (str[*i] == 'h')
			i++;
		//mita jos vaan h
	
}

void	manage_short(char *str, va_list ap, int *i)
{
	(void)str;
	(void)ap;
		if (str[*i] == 'h')
			i++;
		//mita jos vaan h
	
}

void	parse_flag(char *str, va_list ap, int *i)
{
	//s_flag flags;
	//tee että putstr ja itoa palauttaa stringin, jota voi muokata flägeillä
	(*i)++;
	if (str[*i] == 'c')
		ft_putchar(va_arg(ap, int));
	else if (str[*i] == 's')
		ft_putstr(va_arg(ap, char *));
	else if (str[*i] == 'p')
		uns_itoa_base(va_arg(ap, unsigned long long), 16);
	else if (str[*i] == 'd' || str[*i] == 'i')
		itoa_base(va_arg(ap, long long), 10);
	else if (str[*i] == 'o')
		itoa_base(va_arg(ap, long long), 8);//unnsigned octal
	else if (str[*i] == 'u')
		itoa_base(va_arg(ap, long long), 10);//unnsigned decimal
	else if (str[*i] == 'x' || str[*i] == 'X')
		itoa_base(va_arg(ap, long long), 16);//unisigned hexadecimal
	else if (str[*i] == 'f')
		ft_put_float(va_arg(ap, double));
	else if (str[*i] == '%')
		write(1, "%", 1);
	else if (str[*i] == 'h')
		manage_short(str, ap, i);
	else if (str[*i] == 'l')
		manage_long(str, ap, i);
	//h on short
	//hh short short eli char
	//l = long
	//ll long long
	//if (str[i] != '.')
	//	return (i);
	//else
}

int		ft_printf(char *str, ...)
{
	int i;
	va_list ap;

	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			parse_flag(str, ap, &i);
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (0);
}
