/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:35:35 by forange-          #+#    #+#             */
/*   Updated: 2019/07/25 11:04:19 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_str_type(t_printf *tprint)
{
	char *res = NULL;
	(void)tprint;
	return(res);
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
	char *res = NULL;
	(void)tprint;
	return(res);
}

t_func	ft_add_table(char type, char *(*func)(t_printf *tprint))
{
	t_func out;

	out.ch = type;
	out.func = func;
	return (out);
}

void	ft_init_handlers(t_func *table)
{
	table[0] = ft_add_table('s', ft_str_type);
	table[1] = ft_add_table('c', ft_char_type);
	table[2] = ft_add_table('p', ft_ptr_type);
	table[3] = ft_add_table('d', ft_int_type);
	table[4] = ft_add_table('i', ft_int_type);
	table[5] = ft_add_table('o', ft_oct_type);
	table[6] = ft_add_table('u', ft_unsgn_type);
	table[7] = ft_add_table('x', ft_hex_type);
	table[8] = ft_add_table('X', ft_bhex_type);
	table[9] = ft_add_table('f', ft_float_type);
	table[10] = ft_add_table('%', ft_perc_type);
}

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
	ft_init_handlers(f_table);
	while (i < TYPE_NUM)
	{
		if (*tprint->str == f_table[i].ch)
			return (f_table[i].func(tprint));
		i++;
	}
	return (NULL);
}
