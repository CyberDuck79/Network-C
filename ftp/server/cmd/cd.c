/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:32:41 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/24 12:32:03 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

/* cd command function */
int		cmd_cd(t_net *client, char data[BUFF_SIZE], t_log *log)
{
	int		ret = chdir(data + 3) ? 0 : 1;

	if (send(client->sock, &ret, sizeof(int), 0) == ERROR)
		log_error(log, "cd cmd return", SEND);
	return (log->error ? ERROR : EXIT_SUCCESS);
}
