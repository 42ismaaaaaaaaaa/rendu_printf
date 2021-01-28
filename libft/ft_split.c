/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:14:39 by iouali            #+#    #+#             */
/*   Updated: 2020/11/22 17:29:12 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*dump_all(char **strstr)
{
	size_t	i;

	i = 0;
	while (strstr[i])
	{
		free(strstr[i]);
		i++;
	}
	free(strstr);
	return (NULL);
}

static char		*ft_copystr(const char *s, size_t size, size_t start)
{
	char	*str;
	size_t	i;

	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	count_letters(char const *s, size_t start, char c)
{
	size_t len;

	len = 0;
	while (s[start] != c && s[start])
	{
		len++;
		start++;
	}
	return (len);
}

static int		count_words(char const *s, char c)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	if (s[i] == '\0')
		return (0);
	i++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count + 1);
}

char			**ft_split(char const *s, char c)
{
	char	**strstr;
	size_t	i;
	size_t	j;
	size_t	word_len;

	if (!(strstr = malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while ((int)j < count_words(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c)
		{
			word_len = count_letters(s, i, c);
			if (!(strstr[j] = ft_copystr(s, word_len, i)))
				return (dump_all(strstr));
			i += word_len;
		}
		j++;
	}
	strstr[j] = NULL;
	return (strstr);
}
