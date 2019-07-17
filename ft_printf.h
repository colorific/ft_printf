/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:32:31 by forange-          #+#    #+#             */
/*   Updated: 2019/07/17 18:45:49 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>						//debug
# include "./denis_printf/libft/libft.h"	//debug

# define F_MINUS	(1 << 0)
# define F_PLUS		(1 << 1)
# define F_SPACE	(1 << 2)
# define F_ZERO		(1 << 3)
# define F_HASH		(1 << 4)
# define L_HH		(1 << 5)
# define L_H		(1 << 6)
# define L_LL		(1 << 7)
# define L_L		(1 << 8)
# define L_BIGL		(1 << 9)


typedef struct		s_printf
{
	int				printed;
	unsigned short	flag;
	int				width;
	int				prec;
	char			type;
	int				fd;
	va_list			args;
	char			*str;
}					t_printf;

int					ft_printf(const char *restrict format, ...);
int					ft_dprintf(int fd, const char *restrict format, ...);
void				print_arg(t_printf *tprint);
void				parse_format(t_printf *tprint);

#endif
