/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:37:41 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 22:25:03 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

// TODO -> ajouter log erreur dans commande + ecriture log
int		cmd_get(t_net *client, char data[BUFF_SIZE], t_log *log)
{
	t_file	file = {0};
	time_t	log_time = time(NULL);

	file.name = &data[4];
	stat(file.name, &file.stat);
	file.size = file.stat.st_size;
	file.fd = open(file.name, O_RDONLY);
	if (send(client->sock, &file.size, sizeof(int), 0) == ERROR)
		log_error(&log_time, log, file.name, SIZE);
	else if (file.fd == ERROR)
		log_error(&log_time, log, file.name, READ);
	else if (file.size)
		if (sendfile(file.fd, client->sock, 0, &file.size, NULL, 0) == ERROR)
			log_error(&log_time, log, file.name, SEND);
	printf("%i\n", errno);
	close(file.fd);
	return (log->error);
}
