/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:37:55 by joaolive          #+#    #+#             */
/*   Updated: 2026/05/30 18:56:52 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			*word_ptr;
	unsigned char	*byte_ptr;

	byte_ptr = (unsigned char *)s;
	while (n && ((size_t)byte_ptr & (sizeof(size_t) - 1)) != 0)
	{
		*byte_ptr++ = 0;
		n--;
	}
	word_ptr = (size_t *)byte_ptr;
	while (n >= sizeof(size_t) && (n -= sizeof(size_t), 1))
		*word_ptr++ = 0;
	byte_ptr = (unsigned char *)word_ptr;
	while (n--)
		*byte_ptr++ = 0;
}
