/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:12:13 by joaolive          #+#    #+#             */
/*   Updated: 2026/06/04 13:42:18 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_get_next_word(const char **s_aux, char c)
{
	const char	*start;
	const char	*end;

	while (**s_aux && **s_aux == c)
		(*s_aux)++;
	start = *s_aux;
	end = start;
	while (*end && *end != c)
		end++;
	if (start == end)
		return (NULL);
	*s_aux = end;
	return (ft_substr(start, 0, end - start));
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	const char	*s_aux;
	size_t		total_words;
	size_t		i;

	if (!s)
		return (NULL);
	total_words = ft_count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (total_words + 1));
	if (!arr)
		return (NULL);
	i = 0;
	s_aux = s;
	while (i < total_words)
	{
		arr[i] = ft_get_next_word(&s_aux, c);
		if (!arr[i])
			return (ft_free_arr(arr));
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
