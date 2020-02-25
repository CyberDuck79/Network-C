/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:59:26 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/24 12:38:50 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

/* User parsing function */
static t_user	*parse_line(const char **line)
{
	t_user	*user;

	if ((user = calloc(1, sizeof(t_user))) == NULL)
		return (NULL);
	if ((user->login = substr_chr(line, ' ')) == NULL)
		return (NULL);
	if ((user->password = substr_chr(line, ' ')) == NULL)
		return (NULL);
	if ((user->path = substr_chr(line, '\n')) == NULL)
		return (NULL);
	return (user);
}

/* Users parsing controller function */
static int		get_users(const char *database, t_user **user)
{
	if (*database == '\0')
		return (EXIT_SUCCESS);
	if ((*user = parse_line(&database)) == NULL)
		return (ERROR);
	return (get_users(database, &(*user)->next));
}

/* User database reading function */
static char		*read_database(int fd, off_t offset)
{
	char		buf[BUFF_SIZE];
	char		*data;
	ssize_t		read_len;

	if (!(read_len = read(fd, buf, BUFF_SIZE)))
	{
		close(fd);
		return ((char*)calloc(offset + 1, sizeof(char)));
	}
	else if (read_len == ERROR)
	{
		close(fd);
		return (NULL);
	}
	if (!(data = read_database(fd, offset + read_len)))
		return (NULL);
	memcpy(data + offset, buf, read_len);
	return (data);
}

/* User database loading function */
int				userbase_loading(t_user **users, const char *filename)
{
	int		fd;
	char	*database;
	int		error;

	if ((fd = open(filename, O_RDONLY)) == ERROR)
		return (ERROR);
	if ((database = read_database(fd, 0)) == NULL)
		return (ERROR);
	error = get_users(database, users);
	if (error)
		errno = EINVAL;
	free(database);
	return(error);
}
