/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:31:33 by forange-          #+#    #+#             */
/*   Updated: 2019/07/30 22:37:18 by forange-         ###   ########.fr       */
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
			print_arg(parse_format(&tprint, f_table), &tprint);
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
	ft_bzero(&tprint, sizeof(t_printf));
	tprint.str = (char*)format;
	tprint.fd = 1;
	va_start(tprint.args, format);
	while (*tprint.str)
	{
		if (*tprint.str == '%')
		{
			tprint.str++;
			print_arg(parse_format(&tprint, f_table), &tprint);
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
