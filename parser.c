/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:35:35 by forange-          #+#    #+#             */
/*   Updated: 2019/07/23 13:33:28 by kirill           ###   ########.fr       */
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
	char *flag;
	char *haystack;

	haystack = ft_strdup("-+ 0#");
	while (*tprint->str && (flag = ft_strchr(haystack, *tprint->str)) > 0)
	{
		tprint->flag |= (1 << (flag - haystack));
		tprint->str++;
	}
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
