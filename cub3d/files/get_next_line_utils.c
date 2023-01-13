/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:36:07 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/31 18:11:02 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	t_joinp	data;

	data.count = 0;
	data.count2 = 0;
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	data.tot_len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	data.pt = (char *)malloc(sizeof(char *) * (data.tot_len + 1));
	if (!data.pt)
		return (0);
	while (s1[data.count] != '\0')
	{
		data.pt[data.count] = s1[data.count];
		data.count++;
	}
	while (s2[data.count2] != '\0')
	{
		data.pt[data.count] = s2[data.count2];
		data.count2++;
		data.count++;
	}
	data.pt[data.count] = '\0';
	return (data.pt);
}

int	ft_strlen(char *str)
{
	int		leng;
	char	*temp;

	temp = str;
	leng = 0;
	if (temp == 0)
		return (0);
	while (*temp != '\0')
	{
		temp++;
		leng++;
	}
	return (leng);
}

char	*ft_strchr(const char *str, int c)
{
	char	car;
	int		i;

	i = 0;
	car = (unsigned char)c;
	while (str[i] != '\0')
	{
		if (str[i] == car)
		{
			return ((char *)str + i);
		}
		i++;
	}
	if (str[i] == car)
		return ((char *)str + i);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_strdup(const char *s)
{
	int		count;
	int		len;
	char	*ns;
	char	*sn;

	sn = (char *)s;
	count = 0;
	len = ft_strlen(sn);
	ns = malloc(sizeof(char) * len + 1);
	if (!ns)
		return (NULL);
	while (count < len)
	{
		ns[count] = s[count];
		count++;
	}
	ns[count] = '\0';
	return (ns);
}
