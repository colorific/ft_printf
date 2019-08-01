/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 20:54:26 by forange-          #+#    #+#             */
/*   Updated: 2019/08/01 12:59:06 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_str_gen(char *str, t_printf *tprint)
{
	int		len;
	char	*filler;

	len = ft_strlen(str);
	len = (tprint->flag & F_PREC && len > tprint->prec) ? tprint->prec : len;
	if (len >= tprint->width)
		write(tprint->fd, str, len);
	else
	{
		filler = ft_strnew(tprint->width);
		filler = (char*)ft_memset(filler, ' ', tprint->width);
		if (tprint->flag & F_MINUS)
			ft_strncpy(filler, str, len);
		else
			ft_strncpy(filler + tprint->width - len, str, len);
		write(tprint->fd, filler, tprint->width);
		ft_memdel((void**)&filler);
	}
	return (len > tprint->width ? len : tprint->width);
}

int			ft_str_type(t_printf *tprint)
{
	char	*out;

	tprint->type = *tprint->str++;
	out = va_arg(tprint->args, char *);
	if (tprint->flag & F_PREC && !tprint->prec && !tprint->width)
		return (0);
	if (!out)
		return(ft_str_gen("(null)", tprint));
	return (ft_str_gen(out, tprint));
}
