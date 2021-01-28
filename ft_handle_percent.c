/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:46:44 by iouali            #+#    #+#             */
/*   Updated: 2021/01/28 14:07:32 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handle_percent(char *flags)
{
	int	width;
	int	print_after;
	int	zeros;
	int	len;

	zeros = get_zeros(flags, -1);
	width = get_width(flags);
	print_after = get_print_after(flags, zeros, 0, 0);
	len = 1;
	if (zeros == 1 && print_after == 0)
		len += print_zeros_percent(width);
	if (print_after == 1)
		write(1, "\%", 1);
	if (width >= 0 && zeros == 0)
		len += print_spaces_percent(width);
	if (print_after == 0)
		write(1, "\%", 1);
	return (len);
}

int		print_spaces_percent(int width)
{
	int i;

	i = 0;
	while (i < width - 1)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		print_zeros_percent(int width)
{
	int i;

	i = 0;
	while (i < width - 1)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}
