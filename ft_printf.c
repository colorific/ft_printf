/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:31:33 by forange-          #+#    #+#             */
/*   Updated: 2019/08/02 01:13:59 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_dprintf(int fd, const char *restrict format, ...)
{
	t_printf	tprint;
	t_func		f_table[TYPE_NUM];

	ft_init_table(f_table);
	ft_bzero(&tprint, sizeof(t_printf));
	tprint.str = (char*)format;
	tprint.fd = fd;
	va_start(tprint.args, format);
	while (*tprint.str)
	{
		if (*tprint.str == '%')
		{
			tprint.str++;
			tprint.printed += parse_format(&tprint, f_table);
		}
		else
		{
			write(fd, &*tprint.str, 1);
			tprint.str++;
			tprint.printed++;
		}
	}
	va_end(tprint.args);
	return (tprint.printed);
}

int				ft_printf(const char *restrict format, ...)
{
	t_printf	tprint;
	t_func		f_table[TYPE_NUM];

	ft_init_table(f_table);
	tprint.printed = 0;
	tprint.str = (char*)format;
	tprint.fd = 1;
	va_start(tprint.args, format);
	while (*tprint.str)
	{
		if (*tprint.str == '%')
		{
			tprint.str++;
			tprint.printed += parse_format(&tprint, f_table);
		}
		else
		{
			write(tprint.fd, &*tprint.str, 1);
			tprint.str++;
			tprint.printed++;
		}
	}
	va_end(tprint.args);
	return (tprint.printed);
}
