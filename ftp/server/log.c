/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:32:57 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/19 00:50:11 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

void	log_error(time_t *log_time, t_log *log, char *name, t_error i)
{
	static const char	*log_msg[6] = LOG_MSG_TAB;

	log->error = -1;
	log->message = log_msg[i];
	log->name = name;
	log->time = ctime(log_time);
}

void	write_log(t_net *client, t_log *log)
{
	int	log_fd;

	dprintf(2, "%s:%i ", client->ip, client->addr.sin_port);
	perror("client");
	log_fd = open("error.log", O_CREAT | O_WRONLY, 0644);
	if (log_fd != ERROR)
	{
		lseek(log_fd, 0, SEEK_END);
		dprintf(log_fd, "%s:%i - ", client->ip, client->addr.sin_port);
		dprintf(log_fd, "%s:", log->message);
		dprintf(log_fd, " %s |", strerror(errno));
		dprintf(log_fd, " %s - %s", log->name, log->time);
	}
	else
		write(2, "error: impossible to open log file\n", 35);
	close(log_fd);
}
