/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:04:49 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 16:52:16 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int		cmd_put(t_net *client, char data[BUFF_SIZE], t_log *log)
{
	char	buffer[FILE_BUFF];
	int		writed = 0;
	t_file	file = {0};
	time_t	log_time = time(NULL);

	file.name = &data[4];
	if (recv(client->sock, &file.size, sizeof(int), 0) == ERROR)
		log_error(&log_time, log, file.name, RECV);
	else if (file.size)
	{
		file.fd = open(file.name, O_CREAT | O_EXCL | O_WRONLY, 0666);
		if (file.fd == ERROR)
			log_error(&log_time, log, file.name, READ);
		else
			while ((file.size = recv(client->sock, buffer, FILE_BUFF, 0)) > 0)
				writed += write(file.fd, buffer, file.size);
	}
	if (file.size == ERROR)
		log_error(&log_time, log, file.name, RECV);
	close(file.fd);
	send(client->sock, &writed, sizeof(int), 0);
	return (log->error);
}
