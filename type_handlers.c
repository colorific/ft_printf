/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:25:32 by forange-          #+#    #+#             */
/*   Updated: 2019/07/30 22:48:17 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_str_type(t_printf *tprint)
{
	char	*out;
	int		len;

	out = va_arg(tprint->args, char *);
	if (tprint->flag & F_PREC && !tprint->prec)
		return (NULL);
	len = ft_strlen(out);
	if (tprint->flag & F_MINUS)
	{
		write(tprint->fd, tprint->str, 1);
	}
	else
	{
		;
	}




}

char *ft_char_type(t_printf *tprint)
{
	char *res = NULL;
	(void)tprint;
	return(res);
}

char *ft_ptr_type(t_printf *tprint)
{
	char *res = NULL;
	(void)tprint;
	return(res);
}

char *ft_int_type(t_printf *tprint)
{
	char *res = NULL;
	(void)tprint;
	return(res);
}

char *ft_oct_type(t_printf *tprint)
{
	char *res = NULL;
	(void)tprint;
	return(res);
}

char *ft_unsgn_type(t_printf *tprint)
{
	char *res = NULL;
	(void)tprint;
	return(res);
}

char *ft_hex_type(t_printf *tprint)
{
	char *res = NULL;
	(void)tprint;
	return(res);
}

char *ft_bhex_type(t_printf *tprint)
{
	char *res = NULL;
	(void)tprint;
	return(res);
}

char *ft_float_type(t_printf *tprint)
{
	char *res = NULL;
	(void)tprint;
	return(res);
}

char *ft_perc_type(t_printf *tprint)
{
	tprint->printed++;
	return(ft_strdup("%"));
}
