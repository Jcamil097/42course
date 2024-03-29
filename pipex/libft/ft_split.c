/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:38:05 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:37:10 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cont_words(char const *s, char c)
{
	int	pos;
	int	cont;

	pos = 0;
	cont = 0;
	while (s[pos])
	{
		if (s[pos] != c)
		{
			cont++;
			while (s[pos] != c && s[pos])
				pos++;
		}
		else
			pos++;
	}
	return (cont);
}

int	len_word(char const *s, char c, int pos)
{
	int	len;

	len = 0;
	while (s[pos] != c && s[pos] != '\0')
	{
		len++;
		pos++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		cont;
	int		word;
	int		len;
	int		pos;
	char	**str;

	cont = 0;
	pos = 0;
	word = cont_words(s, c);
	str = (char **)malloc(sizeof(char *) * (word + 1));
	if (!str)
		return (NULL);
	while (pos < word)
	{
		while (s[cont] == c)
			cont++;
		len = len_word(s, c, cont);
		str[pos] = ft_substr(s, cont, len);
		cont = cont + len;
		pos++;
	}
	str[pos] = 0;
	return (str);
}
