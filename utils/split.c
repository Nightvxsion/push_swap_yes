/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:50:04 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/20 18:50:04 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_on_str(char const *s1, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			j = 0;
		else if (j == 0)
		{
			j = 1;
			i++;
		}
		s1++;
	}
	return (i);
}

static int	total_length(char const *s1, char c, int n)
{
	int	len;

	len = 0;
	while (s1[n] != c && s1[n] != '\0')
	{
		len++;
		n++;
	}
	return (len);
}

static void	*rm_arr(char **s1, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)s1[j]);
	}
	free(s1);
	return (NULL);
}

static char	**body(char *s1, char **s, char c, int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && j < n)
	{
		while (s1[i] == c)
			i++;
		s[j] = (char *)malloc(sizeof(char) * (total_length(s1, c, i) + 1));
		if (s[j] == NULL)
			return (rm_arr(s, j));
		k = 0;
		while (s1[i] != '\0' && s1[i] != c)
			s[j][k++] = s1[i++];
		s[j][k] = '\0';
		j++;
	}
	s[j] = NULL;
	return (s);
}

char	**split(char const *s, char c)
{
	char	**dest;
	int		n;

	if (s == NULL)
		return (NULL);
	n = is_on_str(s, c);
	dest = (char **)malloc(sizeof(char *) * (n + 1));
	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}
	dest = body((char *)s, dest, c, n);
	return (dest);
}
