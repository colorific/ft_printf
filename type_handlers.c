/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:25:32 by forange-          #+#    #+#             */
/*   Updated: 2019/08/01 20:50:21 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_ptr_type(t_printf *tprint)
{
	uintptr_t	ptr;
	char		*out;

	ptr = va_arg(tprint->args, uintptr_t);
	out = ft_itoa((int)ptr);
	write(1, out, ft_strlen(out));
	return (0);
}

int			ft_int_type(t_printf *tprint)
{
	(void)tprint;
	return (0);
}

int			ft_oct_type(t_printf *tprint)
{
	(void)tprint;
	return (0);
}

int			ft_unsgn_type(t_printf *tprint)
{
	(void)tprint;
	return (0);
}

int			ft_hex_type(t_printf *tprint)
{
	(void)tprint;
	return (0);
}

int			ft_bhex_type(t_printf *tprint)
{
	(void)tprint;
	return (0);
}

int			ft_float_type(t_printf *tprint)
{
	(void)tprint;
	return (0);
}
