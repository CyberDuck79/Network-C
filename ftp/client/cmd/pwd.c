/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:08:07 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/19 18:21:37 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int		cmd_pwd(t_net *server, char data[BUFF_SIZE])
{
	t_file file;

	strcpy(data, "pwd");
	if (send(server->sock, data, BUFF_SIZE, 0) == ERROR)
		return (ERROR);
	if (recv(server->sock, &file.size, sizeof(int), 0) == ERROR)
		return (ERROR);
	if ((file.data = malloc(file.size)) == NULL)
		return (ERROR);
	if (recv(server->sock, file.data, file.size, 0) == ERROR)
		return (ERROR);
	printf("The remote directory listing is as follows:\n");
	printf("%s", file.data);
	return (EXIT_SUCCESS);
}
