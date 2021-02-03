/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:29:52 by iouali            #+#    #+#             */
/*   Updated: 2021/02/03 13:22:01 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handle_pointers(unsigned long long nb, char *flags)
{
	unsigned long long	n;
	int					zeros;
	int					precision;
	int					print_after;
	int					width;

	precision = get_precision(flags);
	zeros = get_zeros(flags, precision);
	width = get_width(flags);
	print_after = get_print_after(flags, zeros, 0, precision);
	n = nb;
	if ((print_after == 1 || zeros == 1 ||
		ft_strlen(flags) == 0 || width <= size_of_hex(n) + 2) || (nb == 0 && precision <= size_of_hex(n) + 3 && width <= size_of_hex(n) + 3 && precision != 0))
		ft_putstr("0x");
	return (ft_handle_pointers_bis(nb, flags, 'p'));
}

int		ft_handle_pointers_bis(unsigned long long nb, char *flags,
										char op)
{
	int					len;
	unsigned long long	n;
	int					tab[2];

	len = 0;
	n = nb;
	tab[1] = op;
	if (op == 'p')
		len += 2;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	if (nb <= 0 && !(get_precision(flags) == 0 && nb == 0))
		len++;
	tab[0] = len;
	return (ft_handle_pointers_extension(nb, flags, len, tab));
}

int		ft_handle_pointers_extension(unsigned long long nb, char *flags,
									int len, int *tab)
{
	int decision;

	decision = ft_handle_flags_pointers(flags, tab, 0, nb);
	if (decision == -2)
		write_to_hexa_pointers(nb, tab[1]);
	else if (decision == -1)
	{
		decision = ft_check_if_zeros(flags, len, nb);
		len += ft_handle_flags_pointers(flags, tab, 1, nb);
		len += decision;
	}
	else
		len += decision;
	return (len);
}

int		size_of_hex(unsigned long long nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}
