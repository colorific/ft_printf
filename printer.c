/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:41:22 by forange-          #+#    #+#             */
/*   Updated: 2019/07/31 18:04:16 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(char *str, t_printf *tprint)
{
	if (!str)
		return ;
	if (tprint->type == 's')
		write(tprint->fd, str, ft_strlen(str));
}
