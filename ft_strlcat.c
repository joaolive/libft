/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:56:20 by joaolive          #+#    #+#             */
/*   Updated: 2026/06/04 12:43:11 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = ft_strlen(src);
	while (dst_len < dstsize && dst[dst_len])
		dst_len++;
	if (dstsize == dst_len)
		return (dstsize + src_len);
	i = -1;
	while (src[++i] && (dst_len + i + 1) < dstsize)
		dst[dst_len + i] = src[i];
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
