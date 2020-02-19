/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:24:25 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/19 17:32:34 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static int	get_file(t_net *server, t_file *file)
{
	if ((file->data = malloc(file->size)) == NULL)
		return (ERROR);
	if (recv(server->sock, file->data, file->size, 0) == ERROR)
		return (ERROR);
	if ((file->fd = open(file->name, O_CREAT | O_WRONLY, 0644)) == ERROR)
		return (ERROR);
	if (write(file->fd, file->data, file->size) == ERROR)
		return (ERROR);
	printf("file %s downloaded\n", file->name);
	close(file->fd);
	free(file->data);
	return (EXIT_SUCCESS);
}

int			cmd_get(t_net *server, char data[BUFF_SIZE])
{
	t_file	file;

	printf("Enter filename to get: ");
	scanf("%s", file.name);
	strcpy(data, "get ");
	strcat(data, file.name);
	if (send(server->sock, data, BUFF_SIZE, 0) == ERROR)
		return (ERROR);
	if (recv(server->sock, &file.size, sizeof(int), 0) == ERROR)
		return (ERROR);
	if (!file.size)
		dprintf(STDERR_FILENO, "No such file on the remote directory\n");
	else if (get_file(server, &file) == ERROR)
		return (ERROR);
	return (EXIT_SUCCESS);
}