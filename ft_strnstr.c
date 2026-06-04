/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:23:01 by joaolive          #+#    #+#             */
/*   Updated: 2026/06/04 13:07:11 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*h;
	const char	*n;
	size_t		rem;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		h = haystack;
		n = needle;
		rem = len;
		while (*n && *h == *n && rem > 0)
		{
			h++;
			n++;
			rem--;
		}
		if (*n == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
