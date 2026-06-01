/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:05:06 by joaolive          #+#    #+#             */
/*   Updated: 2026/05/31 15:35:28 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	const size_t		*w;
	size_t				x;

	p = (const unsigned char *)s;
	while (n && ((size_t)p & (sizeof(size_t) - 1)) != 0 && n--)
			if (*p++ == (unsigned char)c)
				return ((void *)(p - 1));
	w = (const size_t *)p;
	while (n >= sizeof(size_t))
	{
		x = *w ^ ((size_t)-1 / 0xFF * (unsigned char)c);
		if (((x - (size_t)-1 / 0xFF) & ~x & ((size_t)-1 / 0xFF << 7)) != 0)
			break ;
		w++;
		n -= sizeof(size_t);
	}
	p = (const unsigned char *)w;
	while (n--)
		if (*p == (unsigned char)c)
			return ((void *)(p - 1));
	return (NULL);
}
