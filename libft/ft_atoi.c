/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:49:17 by iouali            #+#    #+#             */
/*   Updated: 2021/01/28 14:28:12 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f'
		|| c == '\n')
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	size_t			i;
	unsigned char	*tmp_nptr;
	int				sign;
	long long		result;

	tmp_nptr = (unsigned char *)nptr;
	sign = 1;
	result = 0;
	i = 0;
	while (is_space(tmp_nptr[i]))
		i++;
	if (tmp_nptr[i] == '-' || tmp_nptr[i] == '+')
	{
		if (tmp_nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (tmp_nptr[i] >= '0' && tmp_nptr[i] <= '9')
	{
		result = (result * 10) + (tmp_nptr[i] - 48);
		i++;
	}
	return (result * sign);
}
