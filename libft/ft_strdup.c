/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:48:53 by iouali            #+#    #+#             */
/*   Updated: 2020/11/22 17:27:33 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*tmp_s;
	char	*result;

	result = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	tmp_s = (char *)s;
	i = 0;
	while (tmp_s[i])
	{
		result[i] = tmp_s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
