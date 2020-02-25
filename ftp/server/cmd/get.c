/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:37:41 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/24 12:01:28 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

/* get command function */
int		cmd_get(t_net *client, char data[BUFF_SIZE], t_log *log)
{
	t_file	file;

	file.name = &data[4];
	file.size = 0;
	stat(file.name, &file.stat);
	if ((file.fd = open(file.name, O_RDONLY)) == ERROR)
		log_error(log, file.name, READ);
	else
		file.size = (int)file.stat.st_size;
	if (send(client->sock, &file.size, sizeof(int), 0) == ERROR)
		log_error(log, file.name, SIZE);
	else if (file.size)
		if (sendfile(file.fd, client->sock, 0, &file.stat.st_size, NULL, 0) == ERROR)
			log_error(log, file.name, SEND);
	close(file.fd);
	return (log->error ? ERROR : EXIT_SUCCESS);
}
