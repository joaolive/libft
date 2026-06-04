/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:05:06 by joaolive          #+#    #+#             */
/*   Updated: 2026/06/04 12:30:26 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				x;

	p = (const unsigned char *)s;
	while (n && ((size_t)p & (sizeof(size_t) - 1)) != 0 && n--)
		if (*p++ == (unsigned char)c)
			return ((void *)(p - 1));
	while (n >= sizeof(size_t))
	{
		x = *(size_t *)p ^ ((size_t) - 1 / 0xFF * (unsigned char)c);
		if (((x - (size_t) - 1 / 0xFF) & ~x & ((size_t) - 1 / 0xFF << 7)) != 0)
			break ;
		p += sizeof(size_t);
		n -= sizeof(size_t);
	}
	while (n--)
		if (*p++ == (unsigned char)c)
			return ((void *)(p - 1));
	return (NULL);
}
