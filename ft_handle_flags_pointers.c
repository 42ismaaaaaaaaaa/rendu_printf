/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags_pointers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:31:52 by iouali            #+#    #+#             */
/*   Updated: 2021/02/03 13:21:01 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handle_flags_pointers_extension(char *flags, int *tab, int after,
								unsigned long long nb)
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
	print_after = get_print_after(flags, zeros, 0, precision);
	if (width > tab[0] || precision > tab[0])
	{
		if (print_after == 0)
		{
			size += print_spaces_pointers(width, precision, tab[0], nb);
			if (precision < tab[0] && width > tab[0])
				ft_putstr("0x");
		}
		size += print_zeros_pointers(flags, tab, nb, zeros);
	}
	if (print_after == 1 && after == 0)
		return (-1);
	return (size);
}

int		ft_handle_flags_pointers(char *flags, int *tab, int after,
									unsigned long long nb)
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
	print_after = get_print_after(flags, zeros, 0, precision);
	if (width <= tab[0] && precision <= tab[0] && !(precision == 0 && nb == 0))
		return (-2);
	if (precision == -1 && zeros > 0)
		return (print_zeros_pointers(flags, tab, nb, zeros));
	if (after == 1)
		return (print_spaces_pointers(width, precision, tab[0], nb));
	return (ft_handle_flags_pointers_extension(flags, tab, after, nb));
}

int		print_spaces_pointers(int width, int precision, int len,
								unsigned long long nb)
{
	int i;
	int max;
	int negative;

	i = 0;
	max = 0;
	negative = 0;
	if (nb < 0)
		negative = 1;
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

int		print_zeros_pointers(char *flags, int *tab, unsigned long long nb,
								int zeros)
{
	int max;
	int width;
	int precision;
	int i;

	width = get_width(flags);
	precision = get_precision(flags);
	max = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		if (zeros == 0)
			tab[0]--;
	}
	if (zeros == 1)
		max = width - tab[0];
	if (precision > tab[0])
		max = precision - tab[0] + 2;
	i = max;
	while (max-- > 0)
		write(1, "0", 1);
	print_zeros_pointers_extension(nb, precision, tab[1]);
	return (i);
}

void	print_zeros_pointers_extension(unsigned long long nb, int precision,
										char op)
{
	if (!(nb == 0 && precision == 0))
		write_to_hexa_pointers(nb, op);
}
