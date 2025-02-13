#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

size_t	ft_strlcpy(char	*dst, char *src, size_t dstsize)
{
	size_t	a;

	a = 0;
	if (dstsize != 0)
	{
		while ((a < dstsize - 1) && src[a])
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	return (ft_strlen(src));
}

int	ft_atoi(char *str, int *error)
{
	long	rt;
	int		s;
	int		a;

	rt = 0;
	a = 0;
	s = 1;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			s *= -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		rt = rt * 10 + (str[a] - '0');
		if (rt * s > INT_MAX || rt * s < INT_MIN)
			return (*error = 1, 0);
		a++;
	}
	return (rt * s);
}
