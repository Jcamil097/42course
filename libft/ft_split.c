/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:42:35 by jumoncad          #+#    #+#             */
/*   Updated: 2023/09/25 12:48:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

char	**ft_str(char **str, int word, char const *s, char c)
{
	int	j;
	int	i;
	int	size;

	i = 0;
	j = -1;
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		str[j] = ft_substr(s, i, size);
		if (!str[j])
		{
			ft_free(str, j);
			return (NULL);
		}
		i += size;
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**str;

	word = ft_count_word(s, c);
	str = (char **)malloc((word + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = ft_str(str, word, s, c);
	return (str);
}
