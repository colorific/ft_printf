/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:32:31 by forange-          #+#    #+#             */
/*   Updated: 2019/07/28 22:11:49 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>						//debug
# include "./denis_printf/libft/libft.h"	//debug

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

typedef char		*(*t_handler)(t_printf *tprint);

typedef struct		s_func
{
	t_handler		func;
	char			ch;
}					t_func;

int					ft_printf(const char *restrict format, ...);
int					ft_dprintf(int fd, const char *restrict format, ...);

void				print_arg(char *str, t_printf *tprint);
char				*parse_format(t_printf *tprint);

char				*ft_str_type(t_printf *tprint);
char				*ft_char_type(t_printf *tprint);
char				*ft_ptr_type(t_printf *tprint);
char				*ft_int_type(t_printf *tprint);
char				*ft_oct_type(t_printf *tprint);
char				*ft_unsgn_type(t_printf *tprint);
char				*ft_hex_type(t_printf *tprint);
char				*ft_bhex_type(t_printf *tprint);
char				*ft_float_type(t_printf *tprint);
char				*ft_perc_type(t_printf *tprint);

void				ft_init_table(t_func *table);

#endif
