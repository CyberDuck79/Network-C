/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:32:50 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 21:20:11 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int		cmd_ls(t_net *client, char data[BUFF_SIZE], t_log *log)
{
	t_file	file = {0};
	time_t	log_time = time(NULL);

	(void)data;
	system("ls > ls.send");
	stat("ls.send", &file.stat);
	file.size = (int)file.stat.st_size;
	file.fd = open("ls.send", O_RDONLY);
	if (send(client->sock, &file.size, sizeof(int), 0) == ERROR)
		log_error(&log_time, log, "ls cmd", SIZE);
	else if (file.fd == ERROR)
		log_error(&log_time, log, "ls.send", READ);
	else if (sendfile(file.fd, client->sock, 0, &file.size, NULL, 0) == ERROR)
		log_error(&log_time, log, "ls cmd", SEND);
	close(file.fd);
	system("rm ls.send");
	return (log->error);
}
