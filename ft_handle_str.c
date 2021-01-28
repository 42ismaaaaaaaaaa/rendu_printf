/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:22:25 by iouali            #+#    #+#             */
/*   Updated: 2021/01/28 14:07:46 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handle_str(char *str, char *flags)
{
	int	decision;
	int	len;
	int	precision;

	if (!str)
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	precision = get_precision(flags);
	if (precision < 0 || precision >= len)
		precision = 0;
	else
		len = precision;
	decision = ft_handle_flags_str(flags, len, 0);
	print_str_len(str, len);
	if (decision == -2)
		len += ft_handle_flags_str(flags, len, 1);
	else
		len += decision;
	return (len);
}

int		ft_handle_char(int c, char *flags)
{
	int decision;
	int	len;

	len = 1;
	decision = ft_handle_flags_char(flags, 0);
	write(1, &c, 1);
	if (decision == -2)
		decision = ft_handle_flags_char(flags, 1);
	len += decision;
	return (len);
}

int		ft_handle_flags_char(char *flags, int after)
{
	int width;
	int print_after;

	width = get_width(flags);
	print_after = get_print_after(flags, 0, 0, 0);
	if (print_after == 1 && after == 0)
		return (-2);
	if (width > 1)
		return (print_spaces_str(width, 1));
	return (0);
}

int		ft_handle_flags_str(char *flags, int len, int after)
{
	int	precision;
	int	width;
	int print_after;

	precision = get_precision(flags);
	width = get_width(flags);
	print_after = get_print_after(flags, 0, len, 0);
	if (print_after == 1 && after == 0)
		return (-2);
	if (width > len)
		return (print_spaces_str(width, len));
	return (0);
}

int		print_spaces_str(int width, int len)
{
	int i;
	int	max;

	max = width - len;
	i = 0;
	while (i < max)
	{
		write(1, " ", 1);
		i++;
	}
	return (max);
}
