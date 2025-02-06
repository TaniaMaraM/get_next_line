/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:17:00 by tmarcos           #+#    #+#             */
/*   Updated: 2025/01/24 13:43:04 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!str || start >= ft_strlen(str))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;
	size_t	total_len;

	i = 0;
	while (s1 && s1[i])
		i++;
	j = 0;
	while (s2 && s2[j])
		j++;
	total_len = i + j;
	joined = (char *)malloc((total_len + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	j = 0;
	total_len = 0;
	while (s1 && s1[j])
		joined[total_len++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		joined[total_len++] = s2[j++];
	joined[total_len] = '\0';
	free(s1);
	return (joined);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_bytes;
	size_t	i;
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	total_bytes = nmemb * size;
	if (total_bytes / nmemb != size)
		return (NULL);
	ptr = malloc(total_bytes);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_bytes)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
