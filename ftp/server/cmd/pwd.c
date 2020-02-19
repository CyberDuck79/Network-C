/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:22:15 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/19 11:56:13 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

/* pwd command function */
int		cmd_pwd(t_net *client, char data[BUFF_SIZE], t_log *log)
{
	t_file	file;
	time_t	log_time = time(NULL);

	getcwd(data, BUFF_SIZE);
	file.fd = open("pwd.send", O_CREAT | O_RDWR);
	dprintf(file.fd, "%s\n", data);
	lseek(file.fd, 0, SEEK_SET);
	stat("pwd.send", &file.stat);
	file.size = file.stat.st_size;
	if (send(client->sock, &file.size, sizeof(int), 0) == ERROR)
		log_error(&log_time, log, "pwd size", SIZE);
	if (file.fd == ERROR)
		log_error(&log_time, log, "pwd cmd", READ);
	else if (sendfile(file.fd, client->sock, 0, &file.size, NULL, 0) == ERROR)
		log_error(&log_time, log, "pwd cmd", SEND);
	close(file.fd);
	remove("pwd.send");
	return (log->error ? ERROR : EXIT_SUCCESS);
}
