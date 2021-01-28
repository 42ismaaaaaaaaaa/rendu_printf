/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:33:17 by iouali            #+#    #+#             */
/*   Updated: 2021/01/28 14:39:08 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_nb_len(long long nb)
{
	int len;

	len = 0;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int		ft_handle_int(long long nb, char *flags)
{
	int			len;
	int			decision;
	long long	n;

	len = 0;
	n = nb;
	len += check_nb_len(nb);
	if (nb <= 0 && !(get_precision(flags) == 0 && nb == 0))
		len++;
	decision = ft_handle_flags_int(flags, len, 0, nb);
	if (decision == -2 || decision == 0)
		ft_putnbr(nb, get_precision(flags));
	else if (decision == -1)
	{
		decision = ft_check_if_zeros(flags, len, nb);
		len += ft_handle_flags_int(flags, len, 1, nb);
		len += decision;
	}
	else
		len += decision;
	return (len);
}

int		ft_check_if_zeros(char *flags, int len, long long nb)
{
	int	precision;
	int	width;
	int zeros;
	int	size;
	int max;

	size = 0;
	max = 0;
	precision = get_precision(flags);
	if (nb < 0)
		precision++;
	width = get_width(flags);
	zeros = get_zeros(flags, precision);
	if (zeros)
		return (0);
	max = precision - len;
	while (size < max)
		size++;
	return (size);
}
