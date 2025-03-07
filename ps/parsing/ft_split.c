/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:31:47 by anktiri           #+#    #+#             */
/*   Updated: 2025/03/06 21:33:17 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_cw(const char *s, char c)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	while (s[a])
	{
		while (s[a] == c && s[a])
			a++;
		while (s[a] != c && s[a])
		{
			count += 1;
			while (s[a] != c && s[a])
				a++;
		}
	}
	return (count);
}

static char	*ft_strcpy(char const *s, int start, int end)
{
	char	*str;
	int		a;

	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	a = 0;
	while (start < end)
	{
		str[a] = s[start];
		a++;
		start++;
	}
	str[a] = '\0';
	return (str);
}

static char	**ft_alloc(char **strs, char const *s, char c, int count)
{
	int		start;
	int		end;
	int		b;

	end = 0;
	b = 0;
	while (b < count)
	{
		while (s[end] == c)
			end++;
		start = end;
		while (!(s[end] == c) && s[end])
			end++;
		strs[b] = ft_strcpy(s, start, end);
		if (!strs[b])
		{
			while (b-- > 0)
				free(strs[b]);
			free(strs);
			return (NULL);
		}
		b++;
	}
	strs[b] = NULL;
	return (strs);
}

char	**ft_split(char	const *s, char c)
{
	char	**strs;
	int		count;

	if (!s)
		return (NULL);
	count = ft_cw(s, c);
	strs = malloc((count + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	return (ft_alloc(strs, s, c, count));
}
