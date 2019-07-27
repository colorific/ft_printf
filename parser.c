/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:35:35 by forange-          #+#    #+#             */
/*   Updated: 2019/07/27 18:44:19 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(t_printf *tprint)
{
	char *flag;
	char *haystack;

	haystack = ft_strdup("-+ 0#");
	while (*tprint->str && (flag = ft_strchr(haystack, *tprint->str)) > 0)
	{
		tprint->flag |= (1 << (flag - haystack));
		tprint->str++;
	}
	tprint->flag & F_ZERO && tprint->flag & F_MINUS ? \
		tprint->flag &= ~F_ZERO : 0;
	tprint->flag & F_PLUS && tprint->flag & F_SPACE ? \
		tprint->flag &= ~F_SPACE : 0;
}

static void	parse_width(t_printf *tprint)
{
	if (*tprint->str == '*')
	{
		tprint->width = va_arg(tprint->args, int);
		tprint->str++;
		return ;
	}
	if (ft_isdigit(*tprint->str))
		tprint->width = ft_atoi(tprint->str);
	while (ft_isdigit(*tprint->str))
		tprint->str++;
}

static void	parse_prec(t_printf *tprint)
{
	if (*tprint->str != '.')
		return ;
	else
	{
		tprint->str++;
		if (*tprint->str == '*')
		{
			tprint->prec = va_arg(tprint->args, int);
			tprint->str++;
			return ;
		}
		if (ft_isdigit(*tprint->str))
			tprint->prec = ft_atoi(tprint->str);
		while (ft_isdigit(*tprint->str))
			tprint->str++;
	}
}

static void	parse_lenght(t_printf *tprint)
{
	(void)(tprint);
}

char	*parse_format(t_printf *tprint)
{
	t_func	f_table[TYPE_NUM];
	int		i;

	i = 0;
	parse_flags(tprint);
	parse_width(tprint);
	parse_prec(tprint);
	parse_lenght(tprint);
	/*	дальше начинается обработка типов */
	ft_init_table(f_table);
	while (i < TYPE_NUM)
	{
		if (*tprint->str == f_table[i].ch)
			return (f_table[i].func(tprint));
		i++;
	}
	return (NULL);
}
