/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:51:24 by iouali            #+#    #+#             */
/*   Updated: 2021/01/28 14:55:37 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handle_flags_int_ext(char *flags, int len, int after, long long nb)
{
	int width;
	int precision;
	int zeros;
	int print_after;
	int size;

	size = 0;
	precision = get_precision(flags);
	width = get_width(flags);
	zeros = get_zeros(flags, precision);
	print_after = get_print_after(flags, zeros, len, precision);
	if (precision > 0 && nb < 0)
		precision++;
	if (width > len || precision > len)
	{
		if (print_after == 0)
			size += print_spaces(width, precision, len, nb);
		size += print_zeros(len, nb, precision, flags);
	}
	if (print_after == 1 && after == 0)
		return (-1);
	return (size);
}

int		ft_handle_flags_int(char *flags, int len, int after, long long nb)
{
	int	precision;
	int	width;
	int zeros;
	int	print_after;
	int	size;

	size = 0;
	precision = get_precision(flags);
	width = get_width(flags);
	zeros = get_zeros(flags, precision);
	print_after = get_print_after(flags, zeros, len, precision);
	if (precision > 0 && nb < 0)
		precision++;
	if (width <= len && precision <= len)
		return (-2);
	if (precision == -1 && zeros > 0)
		return (print_zeros(len, nb, precision, flags));
	if (after == 1)
		return (print_spaces(width, precision, len, nb));
	return (ft_handle_flags_int_ext(flags, len, after, nb));
}

int		print_spaces(int width, int precision, int len, long long nb)
{
	int i;
	int max;
	int negative;

	i = 0;
	max = 0;
	negative = 0;
	if (nb == 0 && precision == 0)
		len--;
	if (width > len && precision >= width)
		max = 0;
	else if (precision > len && width > precision)
		max = width - precision - negative;
	else if (width > len && precision <= len)
		max = width - len;
	while (i < max)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		print_zeros(int len, long long nb, int precision, char *flags)
{
	int i;
	int max;
	int width;
	int zeros;

	width = get_width(flags);
	zeros = get_zeros(flags, precision);
	i = 0;
	max = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (zeros == 1)
		max = width - len;
	if (precision > len)
		max = precision - len;
	while (i < max)
	{
		write(1, "0", 1);
		i++;
	}
	print_zeros_int_ext(nb, precision);
	return (i);
}

void	print_zeros_int_ext(long long nb, int precision)
{
	if (!(nb == 0 && precision == 0))
		ft_putnbr(nb, precision);
	if (nb == '%')
		write(1, &nb, 1);
}
