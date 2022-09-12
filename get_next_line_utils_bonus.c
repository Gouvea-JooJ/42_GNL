/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro2 <jopedro2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:00:01 by jopedro2          #+#    #+#             */
/*   Updated: 2022/08/05 21:11:56 by jopedro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*new;

	if (!str || !c)
		return (NULL);
	i = 0;
	new = (char *)str;
	while (new[i])
	{
		if (new[i] == (char) c)
			return (&new[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	unsigned int	slen;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	if (((slen - start) > len) && (start < slen))
		p = malloc((len * sizeof(char) + 1));
	else if (start > slen)
		p = malloc(sizeof(char));
	else
		p = malloc(((slen - start) * sizeof(char) + 1));
	if (!p)
		return (NULL);
	if ((start < slen))
	{
		while ((i < len) && s[start])
			p[i++] = s[start++];
	}
	p[i] = '\0';
	return (p);
}

int	if_null(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (1);
	return (0);
}
