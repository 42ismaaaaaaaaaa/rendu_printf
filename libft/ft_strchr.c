/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:35:18 by iouali            #+#    #+#             */
/*   Updated: 2020/11/22 17:28:20 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*tmp_s;

	tmp_s = (char *)s;
	i = 0;
	while (i < ft_strlen(tmp_s) + 1)
	{
		if (tmp_s[i] == (unsigned char)c)
			return (tmp_s + i);
		i++;
	}
	return (NULL);
}
