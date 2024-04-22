/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:20:32 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/03 09:20:33 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static unsigned int	ft_start(char const *s1, char const *set)
{
	int	start;
	int	i;
	int	found;

	start = 0;
	while (s1[start])
	{
		i = 0;
		while (set[i])
		{
			found = 1;
			if (s1[start] == set[i])
			{
				found = 0;
				break ;
			}
			i++;
		}
		if (found == 1)
			break ;
		start++;
	}
	return (start);
}

static unsigned int	ft_end(char const *s1, char const *set)
{
	int	end;
	int	i;
	int	found;

	end = ft_strlen(s1);
	while (end > 0)
	{
		i = 0;
		while (set[i])
		{
			found = 1;
			if (s1[end - 1] == set[i])
			{
				found = 0;
				break ;
			}
			i++;
		}
		if (found == 1)
			break ;
		end--;
	}	
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*str;

	if (s1 == NULL)
		return (NULL);
	if (ft_strlen(set) == 0 && ft_strlen(s1) != 0)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	if (start == ft_strlen(s1) || ft_strlen(s1) == 0)
	{
		str = malloc(sizeof (char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	end = ft_end(s1, set);
	str = malloc((end - start + 1) * sizeof (char));
	if (str == NULL)
		return (NULL);
	s1 = s1 + start;
	ft_strlcpy(str, s1, end - start + 1);
	return (str);
}
