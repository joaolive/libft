/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:26:29 by joaolive          #+#    #+#             */
/*   Updated: 2026/06/04 12:28:56 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *) s1;
	p2 = (const unsigned char *) s2;
	if (((size_t)p1 == (size_t)p2) | (n == 0))
		return (0);
	if (((size_t)p1 & (sizeof(size_t) - 1)) == ((size_t)p2
			& (sizeof(size_t) - 1)))
	{
		while (n && ((size_t)p1 & (sizeof(size_t) - 1)) != 0 && n--)
			if (*p1++ != *p2++)
				return (p1[-1] - p2[-1]);
		while (n >= sizeof(size_t)
			&& *(const size_t *)p1 == *(const size_t *)p2)
		{
			p1 += sizeof(size_t);
			p2 += sizeof(size_t);
			n -= sizeof(size_t);
		}
	}
	while (n--)
		if (*p1++ != *p2++)
			return (p1[-1] - p2[-1]);
	return (0);
}
