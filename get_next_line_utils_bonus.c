/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danzamor <danzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:37:10 by danz              #+#    #+#             */
/*   Updated: 2025/10/05 15:29:54 by danzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src [i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (c == *s)
			return ((char *)s);
		s++;
	}
	if (c == *s)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*new;

	i = 0;
	if (!src)
		return (NULL);
	new = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin2(char *str1, char *str2)
{
	char	*ret;
	size_t	totallen;
	int		i;

	i = 0;
	if (!str1)
		return (ft_strdup(str2));
	totallen = ft_strlen(str1) + ft_strlen(str2);
	ret = malloc(totallen + 1);
	if (!ret)
	{
		free(str1);
		return (NULL);
	}
	i = ft_strlcpy(ret, str1, totallen - i + 1);
	ft_strlcpy(ret + i, str2, totallen - i + 1);
	free(str1);
	return (ret);
}
