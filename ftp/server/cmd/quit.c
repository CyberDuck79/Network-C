/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:36:05 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/19 01:35:49 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

/* quit command function */
int		cmd_quit(t_net *client, char data[BUFF_SIZE], t_log *log)
{
	int		ret = 1;
	time_t	log_time = time(NULL);

	(void)data;
	if (send(client->sock, &ret, sizeof(int), 0) == ERROR)
		log_error(&log_time, log, "quit cmd return", SEND);
	if (shutdown(client->sock, SHUT_RDWR) == ERROR)
		log_error(&log_time, log, "client", CLOSE);
	else if (close(client->sock) == ERROR)
		log_error(&log_time, log, "client", CLOSE);
	return (log->ret);
}
