/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:32:31 by forange-          #+#    #+#             */
/*   Updated: 2019/08/01 18:17:41 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define TYPE_NUM	11
# define F_MINUS	(1 << 0)
# define F_PLUS		(1 << 1)
# define F_SPACE	(1 << 2)
# define F_ZERO		(1 << 3)
# define F_HASH		(1 << 4)
# define L_HH		(1 << 5)
# define L_H		(1 << 6)
# define L_L		(1 << 7)
# define L_LL		(1 << 8)
# define L_BIGL		(1 << 9)
# define F_PREC		(1 << 10)

typedef struct		s_printf
{
	int				printed;
	unsigned short	flag;
	int				width;
	int				prec;
	int				fd;
	va_list			args;
	char			*str;
}					t_printf;

typedef int			(*t_handler)(t_printf *tprint);

typedef struct		s_func
{
	t_handler		func;
	char			ch;
}					t_func;

int					ft_printf(const char *restrict format, ...);
int					ft_dprintf(int fd, const char *restrict format, ...);

void				print_arg(char *str, t_printf *tprint);
int					parse_format(t_printf *tprint, t_func f_table[]);

int					ft_str_type(t_printf *tprint);
int					ft_char_type(t_printf *tprint);
int					ft_ptr_type(t_printf *tprint);
int					ft_int_type(t_printf *tprint);
int					ft_oct_type(t_printf *tprint);
int					ft_unsgn_type(t_printf *tprint);
int					ft_hex_type(t_printf *tprint);
int					ft_bhex_type(t_printf *tprint);
int					ft_float_type(t_printf *tprint);

void				ft_init_table(t_func *table);

#endif
