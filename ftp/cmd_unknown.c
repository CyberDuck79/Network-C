/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unknown.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:45:26 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 16:15:33 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int		cmd_unknown(t_net *client, char data[BUFF_SIZE], t_log *log)
{
	time_t	log_time = time(NULL);

	(void)client;
	log_error(&log_time, log, data, CMD);
	return (log->error);
}
