/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:44:32 by anktiri           #+#    #+#             */
/*   Updated: 2024/11/24 22:44:32 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

int	ft_strchr(const char *s, char c)
{
	int	a;

	a = 0;
	if (!s)
		return (0);
	while (s[a])
	{
		if (s[a] == c)
			return (1);
		a++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_calloc(size_t size)
{
	char	*p;
	size_t	a;

	a = 0;
	p = malloc(size);
	if (!p)
		return (NULL);
	while (a < size)
		p[a++] = '\0';
	return (p);
}

char	*join(char *s1, char *s2)
{
	char	*buffer;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (ft_free(&s1));
	buffer = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!buffer)
		return (ft_free(&s1));
	while (s1[a])
		buffer[b++] = s1[a++];
	a = 0;
	while (s2[a])
		buffer[b++] = s2[a++];
	return (ft_free(&s1), buffer);
}
