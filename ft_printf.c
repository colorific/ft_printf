/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:31:33 by forange-          #+#    #+#             */
/*   Updated: 2019/07/13 19:01:06 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format(char **str, int *printed, va_list *args)
{
	++(*str);
	(void)args;
	if (**str == 'd')
		;
	++(*printed);
}

int	ft_printf(const char *restrict format, ...)
{
	int		printed;
	va_list	args;
	char	*str;

	printed = 0;
	str = (char*)format;
	va_start(args, format);
	while (*str)
	{
		if (*str == '%')
			parse_format(&str, &printed, &args);
		else
		{
			write(1, &*str, 1);
			str++;
			printed++;
		}
	}
	va_end(args);
	return (printed);
}
