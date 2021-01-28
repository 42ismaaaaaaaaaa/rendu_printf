/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:49:42 by iouali            #+#    #+#             */
/*   Updated: 2021/01/28 13:57:15 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handle_hexa(long long nb, char *flags, char op)
{
	int			len;
	long long	n;
	int			tab[2];

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
	return (ft_handle_hexa_extension(nb, flags, len, tab));
}

int		ft_handle_hexa_extension(long long nb, char *flags, int len, int *tab)
{
	int decision;

	decision = ft_handle_flags_hexa(flags, tab, 0, nb);
	if (decision == -2)
		write_to_hexa(nb, tab[1]);
	else if (decision == -1)
	{
		decision = ft_check_if_zeros(flags, len, nb);
		len += ft_handle_flags_hexa(flags, tab, 1, nb);
		len += decision;
	}
	else
		len += decision;
	return (len);
}
