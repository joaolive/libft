/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:05:53 by joaolive          #+#    #+#             */
/*   Updated: 2026/05/31 00:12:06 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const size_t	*w;
	const char		*p;

	p = s;
	while (((size_t)p & (sizeof(size_t) - 1)) != 0)
	{
		if (*p == '\0')
			return ((size_t)(p - s));
		p++;
	}
	w = (const size_t *)p;
	while (((*w - ~(size_t)0 / 0xFF) & ~*w & (~(size_t)0 / 0xFF << 7)) == 0)
		w++;
	p = (const char *)w;
	while (*p)
		p++;
	return ((size_t)(p - s));
}
