/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:49:57 by forange-          #+#    #+#             */
/*   Updated: 2019/07/23 13:33:22 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
 	char				ch_min = CHAR_MIN;
	char				ch_max = CHAR_MAX;
	unsigned char		u_ch_max = UCHAR_MAX;
	short				shrt_min = SHRT_MIN;
	short				shrt_max = SHRT_MAX;
	unsigned short		u_shrt_max = USHRT_MAX;
	int					i_min = INT_MIN;
	int					i_max = INT_MAX;
	unsigned int		u_i_max = UINT_MAX;
	long				l_i_min = LONG_MIN;
	long				l_i_max = LONG_MAX;
	unsigned long		u_l_i_max = ULONG_MAX;
	long long			ll_i_min = LLONG_MIN;
	long long			ll_i_max = LLONG_MAX;
	unsigned long long	u_ll_i_max = ULLONG_MAX;
	float				f = 0.0;
	double				d = 0.0;
	long double			l_d = 1.1;

/* 	t_printf			print;

	ft_bzero(&print, sizeof(t_printf));
	print.flag |= L_BIGL;

	if (!(print.flag ^ L_HH))
		printf ("YES!!!!\n");
 *//*
	printf("%c\n", ch_min - 1);
	printf("%c\n", ch_max);
	printf("%c\n", u_ch_max);
	printf("%8i\n", shrt_min);
	printf("%8i\n", shrt_max);
	printf("%10hu\n",u_shrt_max);
	printf("%i\n", i_min);
	printf("%i\n", i_max);
	printf("%u\n", u_i_max);
	printf("%li\n", l_i_min);
	printf("%li\n", l_i_max);
	printf("%lu\n", u_l_i_max);
	printf("%lli\n", ll_i_min);
	printf("%lli\n", ll_i_max);
	printf("%llu\n", u_ll_i_max);
	printf("%f\n", f);
	printf("%f\n", d);
	printf("%Lf\n", l_d);
	printf("%hhd\n", (char)i_max);
*/
//	printf("%f\n", 0.1/1);
//	printf("%X !destiny\n", -6, 5);

	/*
	* принтф читает последовательность только пока она валидная.
	* C первым неавлидным знаком он прекращает обрабатывать текст,
	* как формат и начинает его выводить, как строку.
	*
	* Надо как-то обойти сегу при попытке обращения к невалидному указателю. Пример:
	* printf ("%s", -5);
	*/

	int x = 246;

	while (x)
		x = x&(x-1);
	printf("%7ud\n", -1);
	ft_printf("% #+s", 6);
/*
	ft_printf("avbcx\n", "str");
	ft_dprintf(2, "abc\n");
 */
	return (0);
}
