/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:04:49 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/24 12:01:58 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

/* put command function */
int		cmd_put(t_net *client, char data[BUFF_SIZE], t_log *log)
{
	t_file	file;

	file.name = &data[4];
	if (recv(client->sock, &file.size, sizeof(int), 0) == ERROR)
		log_error(log, file.name, RECV);
	else if (file.size)
	{
		file.data = malloc(file.size);
		if ((file.size = recv(client->sock, file.data, file.size, 0)) == ERROR)
			log_error(log, file.name, RECV);
		else if ((file.fd = open(file.name, O_CREAT | O_WRONLY, 0666)) == ERROR)
			log_error(log, file.name, WRITE);
		else
			write(file.fd, file.data, file.size);
	}
	free(file.data);
	close(file.fd);
	send(client->sock, &file.size, sizeof(int), 0);
	return (log->error ? ERROR : EXIT_SUCCESS);
}
