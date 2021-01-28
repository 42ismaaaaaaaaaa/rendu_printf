/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:02:26 by iouali            #+#    #+#             */
/*   Updated: 2021/01/14 15:37:32 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_nb(long long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char		*reverse_str(char *str)
{
	int		i;
	int		j;
	int		len;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	j = len - 1;
	if (str[0] == '-')
		i++;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	str[len] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char		*result;
	size_t		i;
	size_t		count_digit;
	long long	m;

	m = (long long)n;
	count_digit = count_nb(m);
	if (!(result = malloc(sizeof(char) * (count_digit + 1))))
		return (NULL);
	i = 0;
	if (m < 0)
	{
		result[0] = '-';
		m *= -1;
		i++;
	}
	while (i < count_digit)
	{
		result[i] = (m % 10) + 48;
		i++;
		m /= 10;
	}
	result[i] = '\0';
	reverse_str(result);
	return (result);
}
