/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:32:57 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 16:33:58 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

static const char	*log_msg[6] = LOG_MSG_TAB;

void	log_error(time_t *log_time, t_log *log, char *name, t_error i)
{
	log->error = -1;
	log->message = log_msg[i];
	log->name = name;
	log->time = ctime(log_time);
}

void	write_log(t_log *log)
{
	int	log_fd;

	log_fd = open("error.log", O_CREAT | O_EXCL | O_WRONLY, 0666);
	if (log_fd != ERROR)
	{
		lseek(log_fd, 0, SEEK_END);
		dprintf(log_fd, "%s: %s - %s", log->message, log->name, log->time);
	}
	else
		write(2, "error: impossible to open log file\n", 35);
}