/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:45:14 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/19 17:50:18 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static int	put_file(t_net *server, t_file *file)
{
	int status;

	stat(file->name, &file->stat);
	file->size = (int)file->stat.st_size;
	if (send(server->sock, &file->size, sizeof(int), 0) == ERROR)
		return (ERROR);
	if (sendfile(file->fd, server->sock, 0, &file->stat.st_size, NULL, 0) == ERROR)
		return (ERROR);
	if (recv(server->sock, &status, sizeof(int), 0) == ERROR)
		return (ERROR);
	if (!status)
		return (ERROR);
	return (EXIT_SUCCESS);
}

int			cmd_put(t_net *server, char data[BUFF_SIZE])
{
	t_file	file;

	printf("Enter filename to put to server: ");
	scanf("%s", file.name);
	if ((file.fd = open(file.name, O_RDONLY)) == ERROR)
		return (ERROR);
	strcpy(data, "put ");
	strcat(data, file.name);
	if (send(server->sock, data, BUFF_SIZE, 0) == ERROR)
		return (ERROR);
	if (put_file(server, &file) != ERROR)
		printf("File stored successfully\n");
	else
		dprintf(STDERR_FILENO, "File failed to be stored to remote machine\n");
	close(file.fd);
	return (EXIT_SUCCESS);
}