/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknown.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:45:26 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/24 12:33:29 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

/* unknown command function */
int		cmd_unknown(t_net *client, char data[BUFF_SIZE], t_log *log)
{
	(void)client;
	errno = ENOSYS;
	log_error(log, data, CMD);
	return (log->error ? ERROR : EXIT_SUCCESS);
}
