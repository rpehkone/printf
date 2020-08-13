/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:04:54 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/13 19:17:44 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_settings {
	int			precision;
	int			form;
	int			padding;
	int			negative;
	int			positive;
	int			space;
	int			is_short;
	int			is_long;
}				t_settings;

int		ft_printf(char *str, ...);
void	print_integer(long long value, long long base, t_settings *settings, int is_signed);
int		ft_put_float(float f, t_settings *settings);

#endif
