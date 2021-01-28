/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 09:27:04 by iouali            #+#    #+#             */
/*   Updated: 2020/11/22 17:40:03 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*to_return;
	size_t			i;

	to_return = malloc(size * nmemb);
	if (!to_return)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		to_return[i] = 0;
		i++;
	}
	return (to_return);
}
