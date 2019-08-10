/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:35:04 by forange-          #+#    #+#             */
/*   Updated: 2019/08/10 16:08:35 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*ft_uitoal_base(unsigned long long dgt, int base)
{
	unsigned long long	temp;
	int					i;
	char				*out;

	i = 0;
	if (base < 2 && base > 16)
		return (NULL);
	temp = dgt;
	while (temp)
	{
		temp /= base;
		i++;
	}
	out = (char*)malloc(i + 1);
	out[i] = '\0';
	while (dgt)
	{
		temp = dgt % base;
		out[--i] = (temp > 9) ? (temp - 10) + 'a' : temp + '0';
		dgt /= base;
	}
	return (out);
}

static int				ft_gen_hex(unsigned long long in, t_printf *tprint)
{
	char				*filler;
	char				*digit;
	int					len;

	digit = ft_strjoin(tprint->flag & F_HASH ? "0x" : "", ft_uitoal_base(in, 16));
	if (tprint->flag & F_UP)
		ft_strupr(digit);
	len = ft_strlen(digit);
	len = (tprint->flag & F_PREC && len < tprint->prec) ? tprint->prec : len;
	filler = ft_strnew(len > tprint->width ? len : tprint->width);

	ft_strdel(&digit);
	ft_strdel(&filler);
	return (len);
}

int						ft_hex_type(t_printf *tprint)
{
	unsigned long long	out;

	tprint->str++;
	tprint->flag & (F_PREC | F_ZERO) ? tprint->flag &= ~F_ZERO : 0;
	if (tprint->flag & F_PREC && !tprint->prec && !tprint->width)
		return (0);
	if (tprint->flag & L_HH)
		out = (unsigned char)va_arg(tprint->args, int);
	else if (tprint->flag & L_H)
		out = (unsigned short)va_arg(tprint->args, int);
	else if (tprint->flag & L_L)
		out = va_arg(tprint->args, unsigned long);
	else if (tprint->flag & L_LL)
		out = va_arg(tprint->args, unsigned long long);
	else
		out = va_arg(tprint->args, unsigned int);
	return (ft_gen_hex(out, tprint));
}

int						ft_bhex_type(t_printf *tprint)
{
	tprint->flag |= F_UP;
	return (ft_hex_type(tprint));
}
