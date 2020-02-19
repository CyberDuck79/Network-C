/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:12:20 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/19 17:15:31 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int		cmd_quit(t_net *server, char data[BUFF_SIZE])
{
	int	status;

	strcpy(data, "quit");
	if (send(server->sock, data, BUFF_SIZE, 0) == ERROR)
		return (ERROR);
	if (recv(server->sock, &status, sizeof(int), 0) == ERROR)
		return (ERROR);
	if (status)
		printf("Server closed\nQuitting..\n");
	else
		dprintf(STDERR_FILENO, "Server failed to close connection\n");
	return (EXIT_SUCCESS);
}
