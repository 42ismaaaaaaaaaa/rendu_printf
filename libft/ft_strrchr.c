/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:04:48 by iouali            #+#    #+#             */
/*   Updated: 2020/11/22 17:18:37 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*tmp_s;

	tmp_s = (char *)s;
	i = ft_strlen(tmp_s);
	while ((int)i >= 0)
	{
		if (tmp_s[i] == c)
			return (tmp_s + i);
		i--;
	}
	return (NULL);
}
