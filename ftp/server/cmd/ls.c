/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:32:50 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/24 12:01:44 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

/* ls command function */
int		cmd_ls(t_net *client, char data[BUFF_SIZE], t_log *log)
{
	t_file	file;
	DIR		*dir = opendir(".");
	t_entry	*dir_entry;

	(void)data;
	file.fd = open("ls.send", O_CREAT | O_RDWR);
	while ((dir_entry = readdir(dir)))
		dprintf(file.fd, "%s\n", dir_entry->d_name);
	lseek(file.fd, 0, SEEK_SET);
	stat("ls.send", &file.stat);
	file.size = (int)file.stat.st_size;
	if (send(client->sock, &file.size, sizeof(int), 0) == ERROR)
		log_error(log, "ls cmd", SIZE);
	else if (file.fd == ERROR)
		log_error(log, "ls.send", READ);
	else if (sendfile(file.fd, client->sock, 0, &file.size, NULL, 0) == ERROR)
		log_error(log, "ls cmd", SEND);
	close(file.fd);
	closedir(dir);
	remove("ls.send");
	return (log->error ? ERROR : EXIT_SUCCESS);
}
