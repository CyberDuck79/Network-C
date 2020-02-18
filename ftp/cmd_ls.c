/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:32:50 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 08:44:23 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	cmd_ls(t_connection *client, char data[BUFF_SIZE])
{
	t_stat	file;
	off_t	size;
	int		fd;

	(void)data;
	system("ls >temps.txt");
	stat("temps.txt", &file);
	size = file.st_size;
	send(client->sock, &size, sizeof(off_t), 0);
	fd = open("temps.txt", O_RDONLY);
	sendfile(client->sock, fd, 0, &size, NULL, 0);
}
