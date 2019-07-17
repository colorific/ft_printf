/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:35:35 by forange-          #+#    #+#             */
/*   Updated: 2019/07/17 19:23:49 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(t_printf *tprint)
{
	(void)tprint;
}

void	parse_format(t_printf *tprint)
{
	if (*tprint->str == '%')
		tprint->type = '%';
	else if ((tprint->type = *ft_strnstr(tprint->str, "-+ 0#", 5)))
		parse_flags(tprint);
}
