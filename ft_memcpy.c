/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:27:20 by joaolive          #+#    #+#             */
/*   Updated: 2026/06/04 01:47:37 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (((size_t)d & (sizeof(size_t) - 1)) != ((size_t)s & (sizeof(size_t) - 1)))
	{
		while (n--)
			*d++ = *s++;
		return (dst);
	}
	while (n && ((size_t)d & (sizeof(size_t) -1)) != 0 && n--)
		*d++ = *s++;
	while (n >= sizeof(size_t))
	{
		*(size_t *)d = *(const size_t *)s;
		d += sizeof(size_t);
		s += sizeof(size_t);
		n -= sizeof(size_t);
	}
	while (n--)
		*d++ = *s++;
	return (dst);
}
