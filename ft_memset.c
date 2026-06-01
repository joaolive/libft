/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:47:31 by joaolive          #+#    #+#             */
/*   Updated: 2026/05/30 22:53:04 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			*word_ptr;
	unsigned char	*byte_ptr;
	size_t			broadcast;
	
	byte_ptr = (unsigned char *)s;
	while (n && ((size_t)byte_ptr & (sizeof(size_t) - 1)) != 0)
	{
		*byte_ptr++ = (unsigned char)c;
		n--;
	}
	broadcast = ~(size_t)0 / 0xFF;
	word_ptr = (size_t *)byte_ptr;
	while (n >= sizeof(size_t) && (n -= sizeof(size_t), 1))
		*word_ptr++ = broadcast;
	byte_ptr = (unsigned char *)word_ptr;
	while (n--)
		*byte_ptr++ = (unsigned char)c;
	return (s);
}
