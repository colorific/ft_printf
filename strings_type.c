/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 20:54:26 by forange-          #+#    #+#             */
/*   Updated: 2019/08/04 14:28:59 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_wstr_gen(wchar_t *str, t_printf *tprint)
{
	int		char_len;
	char	*filler;

	char_len = ft_wstrlen(str);
	char_len = (tprint->flag & F_PREC && char_len > tprint->prec) ? \
				tprint->prec : char_len;
	if (char_len >= tprint->width)
		ft_putwstrn_fd(str, char_len, tprint->fd);
	else
	{
		filler = ft_strnew(tprint->width - char_len);
		filler = (char*)ft_memset(filler, ' ', tprint->width - char_len);
		if (tprint->flag & F_MINUS)
		{
			ft_putwstrn_fd(str, char_len, tprint->fd);
			write(tprint->fd, filler, tprint->width - char_len);
		}
		else
		{
			write(tprint->fd, filler, tprint->width - char_len);
			ft_putwstrn_fd(str, char_len, tprint->fd);
		}
		ft_memdel((void**)&filler);
	}
	return (char_len > tprint->width ? char_len : tprint->width);
}

static int	ft_str_gen(char *str, t_printf *tprint)
{
	int		len;
	char	*filler;

	len = ft_strlen(str);
	len = (tprint->flag & F_PREC && len > tprint->prec) ? tprint->prec : len;
	if (len >= tprint->width)
		write(tprint->fd, str, len);
	else
	{
		filler = ft_strnew(tprint->width);
		filler = (char*)ft_memset(filler, ' ', tprint->width);
		if (tprint->flag & F_MINUS)
			ft_strncpy(filler, str, len);
		else
			ft_strncpy(filler + tprint->width - len, str, len);
		write(tprint->fd, filler, tprint->width);
		ft_memdel((void**)&filler);
	}
	return (len > tprint->width ? len : tprint->width);
}

int			ft_str_type(t_printf *tprint)
{
	void	*out;

	tprint->str++;
	out = va_arg(tprint->args, void *);
	if (tprint->flag & F_PREC && !tprint->prec && !tprint->width)
		return (0);
	if (!out)
		return(ft_str_gen("(null)", tprint));
	if (tprint->flag & L_L)
		return(ft_wstr_gen(out, tprint));
	else
		return (ft_str_gen(out, tprint));
}
