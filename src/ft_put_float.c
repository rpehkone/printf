/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:57:13 by rpehkone          #+#    #+#             */
/*   Updated: 2020/01/20 18:48:21 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*get_char(int value, int base);

int		ft_put_float(float f)
{
	char *str;

	unsigned long long n;
	n = f * 1000000;
	str = get_char(f, 10);
	int i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == '0')
		i--;
	//int a = (int)2341.123;
	//printf("%d\n", a);
	str[i + 1] = '\0';
	printf("%s", str);
	return (1);
}
