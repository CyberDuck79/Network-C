/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:49:20 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/24 11:53:05 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

/* return substr of line from start to ending char */
char		*substr_chr(const char **line, char end)
{
	size_t	index;
	char	*str;

	index = 0;
	while ((*line)[index] && (*line)[index] != end)
		index++;
	if ((*line)[index] == '\0')
		return (NULL);
	index++;
	if ((str = calloc(index, sizeof(char))) == NULL)
		return (NULL);
	strlcpy(str, *line, index);
	*line += (index);
	return (str);
}
