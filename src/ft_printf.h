/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:04:54 by rpehkone          #+#    #+#             */
/*   Updated: 2020/08/13 16:36:51 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

//remove
typedef struct	st_flag {
	int		integer;
	int		character;
	int		floating;
}				s_flag;

int		ft_printf(char *str, ...);
void	itoa_base(long long value, long long base, int precision);
void	uns_itoa_base(unsigned long long value, unsigned long long base, int precision);
int		ft_put_float(float f, int precision);

#endif
