/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:05:22 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/19 17:07:56 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int		cmd_cd(t_net *server, char data[BUFF_SIZE])
{
	int	status;

	strcpy(data, "cd ");
	printf("Enter the path to change the remote directory: ");
	scanf("%s", data + 3);
	if (send(server->sock, data, BUFF_SIZE, 0) == ERROR)
		return (ERROR);
	if (recv(server->sock, &status, sizeof(int), 0) == ERROR)
		return (ERROR);
	if (status)
		printf("Remote directory successfully changed\n");
	else
		dprintf(STDERR_FILENO, "Remote directory failed to change\n");
	return (EXIT_SUCCESS);
}
