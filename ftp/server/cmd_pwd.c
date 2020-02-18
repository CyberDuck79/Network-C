/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:22:15 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 21:08:12 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int		cmd_pwd(t_net *client, char data[BUFF_SIZE], t_log *log)
{
	t_file	file = {0};
	time_t	log_time = time(NULL);

	(void)data;
	system("pwd > pwd.send");
	stat("pwd.send", &file.stat);
	file.size = file.stat.st_size;
	file.fd = open("pwd.send", O_RDONLY);
	if (send(client->sock, &file.size, sizeof(int), 0) == ERROR)
		log_error(&log_time, log, "pwd size", SIZE);
	if (file.fd == ERROR)
		log_error(&log_time, log, "pwd cmd", READ);
	else if (sendfile(file.fd, client->sock, 0, &file.size, NULL, 0) == ERROR)
		log_error(&log_time, log, "pwd cmd", SEND);
	close(file.fd);
	system("rm pwd.send");
	return (log->error);
}
