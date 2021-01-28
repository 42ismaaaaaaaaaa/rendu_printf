/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:38:19 by iouali            #+#    #+#             */
/*   Updated: 2020/11/22 17:17:28 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int		count_charset(char const *s1, char const *set)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (is_charset(s1[i], set))
	{
		count++;
		i++;
	}
	if (count == ft_strlen(s1))
		return (count);
	i = ft_strlen(s1) - 1;
	while (is_charset(s1[i], set))
	{
		count++;
		i--;
	}
	return (count);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s1) - count_charset(s1, set)) + 1);
	if (!str)
		return (NULL);
	len = ft_strlen(s1) - count_charset(s1, set);
	i = 0;
	j = 0;
	while (is_charset(s1[i], set))
		i++;
	while (j < len)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
