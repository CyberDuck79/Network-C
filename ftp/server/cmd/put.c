/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:04:49 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/19 11:56:59 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

/* put command function */
int		cmd_put(t_net *client, char data[BUFF_SIZE], t_log *log)
{
	t_file	file;
	time_t	log_time = time(NULL);

	file.name = &data[4];
	if (recv(client->sock, &file.size, sizeof(int), 0) == ERROR)
		log_error(&log_time, log, file.name, RECV);
	else if (file.size)
	{
		file.data = malloc(file.size);
		file.size = recv(client->sock, file.data, file.size, 0);
		file.fd = open(file.name, O_CREAT | O_WRONLY, 0666);
		if (file.fd == ERROR)
			log_error(&log_time, log, file.name, WRITE);
		else
			write(file.fd, file.data, file.size);
	}
	if (file.size == ERROR)
		log_error(&log_time, log, file.name, RECV);
	free(file.data);
	close(file.fd);
	send(client->sock, &file.size, sizeof(int), 0);
	return (log->error ? ERROR : EXIT_SUCCESS);
}
