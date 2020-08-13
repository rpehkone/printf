/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:04:54 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/13 18:09:11 by rpehkone         ###   ########.fr       */
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
	int			form : 1;
	int			padding : 1;
	int			negative : 1;
	int			positive : 1;
	int			space : 1;
}				t_settings;

int		ft_printf(char *str, ...);
void	itoa_base(long long value, long long base, t_settings *settings);
void	uns_itoa_base(unsigned long long value, unsigned long long base, t_settings *settings);
int		ft_put_float(float f, t_settings *settings);

#endif
