/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:29:03 by joaolive          #+#    #+#             */
/*   Updated: 2026/05/30 20:14:03 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void cpy_forward(unsigned char *d, const unsigned char *s, size_t n);
static void cpy_backward(unsigned char *d, const unsigned char *s, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst || !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (((size_t)d & (sizeof(size_t) - 1)) != ((size_t)s & (sizeof(size_t) - 1)))
	{
		if (d < s)
			while (n--)
				*d++ = *s++;
		else
			while (n--)
				d[n] = s[n];
		return (dst);
	}
	if (d < s)
		cpy_forward(d, s, n);
	else
		cpy_backward(d, s, n);
	return (dst);
}

static void cpy_forward(unsigned char *d, const unsigned char *s, size_t n)
{
	size_t			*wd;
	const size_t	*ws;

	while (n && ((size_t)d & (sizeof(size_t) -1)) != 0)
	{
		*d++ = *s++;
		n--;
	}
	wd = (size_t *)d;
	ws = (const size_t *)s;
	while (n >= sizeof(size_t) && (n -= sizeof(size_t), 1))
		*wd++ = *ws++;
	d = (unsigned char *)wd;
	s = (const unsigned char *)ws;
	while (n--)
		*d++ = *s++;
}

static void cpy_backward(unsigned char *d, const unsigned char *s, size_t n)
{
	size_t			*wd;
	const size_t	*ws;

	d += n;
	s += n;
	while (n && ((size_t)d & (sizeof(size_t) -1)) != 0)
	{
		*(--d) = *(--s);
		n--;
	}
	wd = (size_t *)d;
	ws = (const size_t *)s;
	while (n >= sizeof(size_t) && (n -= sizeof(size_t), 1))
		*(--wd) = *(--ws);
	d = (unsigned char *)wd;
	s = (const unsigned char *)ws;
	while (n--)
		*(--wd) = *(--ws);
}
