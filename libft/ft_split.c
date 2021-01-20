/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:53:02 by asalvemi          #+#    #+#             */
/*   Updated: 2021/01/18 15:53:04 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = (char *)s;
	if (!(arr = (char **)malloc(sizeof(char **) * (get_words(str, c) + 1))))
		return (NULL);
	while (*str != '\0')
	{
		j = 0;
		while (str[j] == c)
			str++;
		if (!(arr[i] = (char *)malloc(1 * (ft_strlen_word(str, c) + 1))))
			return (NULL);
		j = -1;
		while (str[++j] != c && str[j] != '\0')
			arr[i][j] = str[j];
		arr[i++][j] = '\0';
		while (*str != c && *str != '\0')
			str++;
	}
	arr[i] = NULL;
	return (arr);
}

int		get_words(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c || s[i + 1] == '\0')
		{
			while (s[i + 1] && s[i + 1] == c)
				i++;
			words++;
		}
		i++;
	}
	return (words);
}

int		ft_strlen_word(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}
