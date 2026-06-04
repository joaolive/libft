/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:08:02 by joaolive          #+#    #+#             */
/*   Updated: 2026/06/04 14:12:28 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*p;
	size_t				x;
	size_t				mask;
	size_t				lo;

	p = (const unsigned char *)s;
	while (((size_t)p & (sizeof(size_t) - 1)) && *p && *p != (unsigned char)c)
		p++;
	lo = (size_t)-1 / 0xFF;
	mask = lo * (unsigned char)c;
	while (1)
	{
		x = *(const size_t *)p;
		if ((((x - lo) & ~x) | (((x ^ mask) - lo) & ~(x ^ mask))) & (lo << 7))
			break ;
		p += sizeof(size_t);
	}
	while (*p && *p != (unsigned char)c)
		p++;
	if (*p == (unsigned char)c)
		return ((char *)p);
	return (NULL);
}
