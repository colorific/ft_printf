/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:31:33 by forange-          #+#    #+#             */
/*   Updated: 2019/07/18 19:58:54 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_dprintf(int fd, const char *restrict format, ...)
{
	t_printf	tprint;

	ft_bzero(&tprint, sizeof(t_printf));
	tprint.str = (char*)format;
	tprint.fd = fd;
	va_start(tprint.args, format);
	while (*tprint.str)
	{
		if (*tprint.str == '%')
		{
			tprint.str++;
			parse_format(&tprint);
			print_arg(&tprint);
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

	ft_bzero(&tprint, sizeof(t_printf));
	tprint.str = (char*)format;
	va_start(tprint.args, format);
	while (*tprint.str)
	{
		if (*tprint.str == '%')
		{
			tprint.str++;
			parse_format(&tprint);
			print_arg(&tprint);
		}
		else
		{
			write(1, &*tprint.str, 1);
			tprint.str++;
			tprint.printed++;
		}
	}
	va_end(tprint.args);
	return (tprint.printed);
}
