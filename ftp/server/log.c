/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:32:57 by fhenrion          #+#    #+#             */
/*   Updated: 2020/03/12 21:45:54 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

/* Log saving function */
void		log_error(t_log *log, const char *name, t_error i)
{
	time_t	log_time = time(NULL);

	log->error = errno;
	log->msg_i = i;
	log->name = name;
	log->time = ctime(&log_time);
}

/* Log formatting function */
static void	print_log(t_net *client, t_log *log, int fd)
{
	static const char	*log_msg[LOG_MSG_TAB_LEN] = LOG_MSG_TAB;
	
	dprintf(fd, "%s:%i - ", client->ip, client->addr.sin_port);
	dprintf(fd, "%s:", log_msg[log->msg_i]);
	dprintf(fd, " %s -", strerror(log->error));
	dprintf(fd, " %s | %s", log->name, log->time);
}

/* Log writing function */
void		write_log(t_net *client, t_log *log, const char *filename)
{
	int	log_fd;

	print_log(client, log, STDERR_FILENO);
	log_fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (log_fd != ERROR)
		print_log(client, log, log_fd);
	else
		write(STDERR_FILENO, "error: impossible to open log file\n", 35);
	close(log_fd);
}

