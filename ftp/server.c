/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:47:38 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 08:43:57 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int		server_ini(t_connection *server, int port)
{
	if ((server->sock = socket(AF_INET, SOCK_STREAM, 0)) == ERROR)
		return (ERROR);
	server->len = sizeof(server->addr);
	server->addr.sin_port = port;
	server->addr.sin_addr.s_addr = 0;
	return (bind(server->sock, (t_addr*)&server->addr, server->len));
}

static int		wait_for_client(t_connection *server, t_connection *client)
{
	if (listen(server->sock, 1) == ERROR)
		return (ERROR);
	// ajouter gestion de plusieurs connections
	client->len = sizeof(client->addr);
	client->sock = accept(server->sock, (t_addr*)&client->addr, &client->len);
	return (0);
}

static t_cmd	parse_cmd(t_connection *client, char data[BUFF_SIZE])
{
	static const char	*cmd_str[CMD_TAB_LEN] = CMD_STR_TAB;
	static const size_t	*cmd_len[CMD_TAB_LEN] = CMD_LEN_TAB;
	static const t_cmd	*cmd[CMD_TAB_LEN] = CMD_TAB;
	size_t				index = 0;

	while (recv(client->sock, data, sizeof(data), 0) == 0)
		sleep(1);
	while (index < CMD_TAB_LEN)
	{
		if (!strncmp(data, *cmd_str[index], cmd_len[index]))
			return (cmd[index]);
		index++;
	}
	return (UNKNOWN);
}

static void		launch_server(t_connection *client)
{
	char			data[BUFF_SIZE];
	t_cmd			cmd;
	t_exec_cmd		execute[CMD_TAB_LEN];

	cmd_ini(execute);
	while ((cmd = parse_command(&client, data)) != QUIT)
	{
		execute[cmd](&client, data);
		bzero(data, sizeof(data));
	}
	execute[cmd](&client, data);
}

int				main(int argc, char *argv[])
{
	t_connection	server;
	t_connection	client;
	
	if (server_ini(&server, atoi(argv[1])) == ERROR)
		exit(errno);
	if (wait_for_client(&server, &client) == ERROR)
		exit(errno);
	launch_server(&client);
	return (0);
}