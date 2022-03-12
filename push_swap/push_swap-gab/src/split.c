/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:20:19 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/10/14 11:00:08 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	**ft_shift(int argc, char **argv)
{
	char	**dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char *) * argc);
	while (argv[i])
	{
		dest[i + 1] = argv[i];
		i++;
	}
	dest[0] = "test";
	free(argv);
	return (dest);
}

int	ft_count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

char	**ft_size_words(const char *s, char c, char **dest)
{
	int	i;
	int	j;
	int	size_word;

	i = 0;
	j = 0;
	while (s[i])
	{
		size_word = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				++size_word;
				++i;
			}
			dest[j] = malloc(sizeof(char) * (size_word + 1));
			j++;
			if (!dest)
				return (NULL);
		}
		else
			i++;
	}
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	int		arr[3];
	char	**dest;

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	dest = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!(ft_size_words(s, c, dest)))
		return (NULL);
	while (s[arr[0]] && !(arr[2]))
	{
		if (s[arr[0]] != c)
		{
			while (s[arr[0]] != c && s[arr[0]])
				dest[arr[1]][arr[2]++] = s[arr[0]++];
			dest[arr[1]][arr[2]] = '\0';
			arr[1]++;
		}
		else
			arr[0]++;
		arr[2] = 0;
	}
	dest[arr[1]] = NULL;
	return (dest);
}
