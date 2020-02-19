/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:59:37 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/19 17:48:41 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int		cmd_ls(t_net *server, char data[BUFF_SIZE])
{
	t_file file;

	strcpy(data, "ls");
	if (send(server->sock, data, BUFF_SIZE, 0) == ERROR)
		return (ERROR);
	if (recv(server->sock, &file.size, sizeof(int), 0) == ERROR)
		return (ERROR);
	printf("%i\n", file.size);
	if ((file.data = malloc(file.size)) == NULL)
		return (ERROR);
	if (recv(server->sock, file.data, file.size, 0) == ERROR)
		return (ERROR);
	printf("The remote directory listing is as follows:\n");
	printf("%s", file.data);
	free(file.data);
	return (EXIT_SUCCESS);
}
