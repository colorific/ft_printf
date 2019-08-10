/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:35:04 by forange-          #+#    #+#             */
/*   Updated: 2019/08/10 11:52:10 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_uitoal_base(unsigned long long dgt, int base)
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

static int	ft_gen_hex(unsigned long long in, t_printf *tprint)
{
	char	*filler;
	char	*digit;
	int		len;

	(void)filler;
	digit = ft_uitoal_base(in, 16);
	len = ft_strlen(digit);
	if (!in && !tprint->prec && tprint->flag & F_PREC)
	;
	return(0);
}

int			ft_hex_type(t_printf *tprint)
{
	unsigned long long int out;

	out = va_arg(tprint->args, unsigned long long int);
	if (tprint->flag & L_HH)
		return(ft_gen_hex((unsigned char)out, tprint));
	else if (tprint->flag & L_H)
		return(ft_gen_hex((unsigned short int)out, tprint));
	else if (tprint->flag & L_L)
		return(ft_gen_hex((unsigned long int)out, tprint));
	else if (tprint->flag & L_LL)
		return(ft_gen_hex(out, tprint));
	else
		return(ft_gen_hex((unsigned int)out, tprint));
}
