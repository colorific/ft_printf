/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:35:35 by forange-          #+#    #+#             */
/*   Updated: 2019/07/19 19:12:12 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_lenght(t_printf *tprint)
{
	(void)tprint;
}

void	parse_prec(t_printf *tprint)
{
	(void)tprint;
}

void	parse_width(t_printf *tprint)
{
	(void)tprint;
}

void	parse_flags(t_printf *tprint)
{
	(void)tprint;
}

void	parse_format(t_printf *tprint)
{
	parse_flags(tprint);
	parse_width(tprint);
	parse_prec(tprint);
	parse_lenght(tprint);
	/*	дальше начинается обработка типов */
	if (*tprint->str == 'd')
		tprint->type = *tprint->str;
	else if (*tprint->str == 'f')
		tprint->type = *tprint->str;
	else if (*tprint->str == 'c' || *tprint->str == 's')
		tprint->type = *tprint->str;
	else
		;
}
