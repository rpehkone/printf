/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:04:54 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/13 20:59:09 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define WHITE " \033[0m"
# define RED " \033[1;31m"
# define GREEN " \033[1;32m"

typedef struct	s_settings {
	int			hash;
	int			zero;
	int			negative;
	int			positive;
	int			space;
	int			is_short;
	int			is_long;
	int			precision;
}				t_settings;

int				ft_printf(const char *str, ...);
char			*itoa_base(long long value, long long base);
void			print_integer(long long value, long long base,
						t_settings *settings, int is_signed);
void			print_float(float f, t_settings *settings);

#endif
