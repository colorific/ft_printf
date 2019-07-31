/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:07:46 by forange-          #+#    #+#             */
/*   Updated: 2019/07/31 21:13:40 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_chr_gen(char c, t_printf *tprint)
{
	char	*filler;

	filler = ft_strnew(tprint->width);
	filler = (char*)ft_memset(filler, ' ', tprint->width);
	if (tprint->flag & F_MINUS)
		filler[0] = c;
	else
		filler[tprint->width - 1] = c;
	write(tprint->fd, filler, tprint->width);
	ft_memdel((void**)&filler);
	return (tprint->width);
}

int			ft_char_type(t_printf *tprint)
{
	char	out;

	if (*tprint->str != '%')
		out = (char)va_arg(tprint->args, int);
	else
		out = '%';
	tprint->type = *tprint->str++;
	if (tprint->width <= 1)
		write(tprint->fd, &out, 1);
	return (tprint->width <= 1 ? 1 : ft_chr_gen(out, tprint));
}
