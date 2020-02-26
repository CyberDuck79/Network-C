/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   login.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:22:30 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/26 15:07:08 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static t_user	*get_user(const char *login, const char *password)
{
	t_user	*user = g_users;

	while (user)
	{
		if (!strcmp(login, user->login))
		{
			if (!strcmp(password, user->password))
				return (user);
			else
				break;
		}
		user = user->next;
	}
	return (NULL);
}

static void		send_status(t_net *client, t_log *log, const char *login, int ret)
{
	if (!ret)
	{
		errno = EBADMSG;
		log_error(log, login, LOG);
	}
	if (send(client->sock, &ret, sizeof(int), 0) == ERROR)
		log_error(log, "login status return", SEND);
}

// DO a list of connected users to refuse already connected client
int				cmd_login(t_net *client, char data[BUFF_SIZE], t_log *log)
{
	const char	*parse_head = &data[6];
	const char	*login;

	if ((login = substr_chr(&parse_head, ' ')) == NULL)
		send_status(client, log, "unknown", 0);
	else if (!strcmp(parse_head, ""))
		send_status(client, log, login, 0);
	else if ((client->user = get_user(login, parse_head)) == NULL)
		send_status(client, log, login, 0);
	else if (chdir(client->user->path) == ERROR)
		send_status(client, log, login, 0);
	send_status(client, log, login, 1);
	free((void*)login);
	return (log->error ? ERROR : EXIT_SUCCESS);
}
