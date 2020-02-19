/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:47:38 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/19 01:29:54 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "cmd_ini.h"
#include "cmd_parsing.h"
#include "log.h"

/* Serveur initialization function */
static int		server_ini(t_net *server, int port)
{
	printf("Server initialization...\n");
	if ((server->sock = socket(AF_INET, SOCK_STREAM, 0)) == ERROR)
		return (ERROR);
	server->len = sizeof(server->addr);
	server->addr.sin_port = port;
	server->addr.sin_addr.s_addr = 0;
	return (bind(server->sock, (t_addr*)&server->addr, server->len));
}

// TODO : Commande de login, refaire le client
/* Connections manager function */
static int		wait_for_client(t_net *server, t_net *client)
{
	pid_t	pid = 1;

	client->len = sizeof(client->addr);
	while (pid)
	{
		printf("Waiting for connection on port %d...\n", server->addr.sin_port);
		if (listen(server->sock, 1) == ERROR)
			return (ERROR);
		client->sock = accept(server->sock, (t_addr*)&client->addr, &client->len);
		if ((pid = fork()) == 0)
			client->ip = inet_ntoa(client->addr.sin_addr);
	}
	return (0);
}

/* Client request handling function */
static void		launch_server(t_net *client)
{
	char			data[BUFF_SIZE] = {0};
	t_log			log = {0};
	t_cmd			cmd;
	t_exec_cmd		execute[CMD_TAB_LEN];

	printf("Client connected from %s:%i\n", client->ip, client->addr.sin_port);
	cmd_ini(execute);
	while ((cmd = parse_cmd(client, data)) != QUIT)
	{
		printf("%s:%i - cmd : %s\n", client->ip, client->addr.sin_port, data);
		if (execute[cmd](client, data, &log) == ERROR)
			write_log(client, &log);
		bzero(data, sizeof(data));
		bzero(&log, sizeof(t_log));
	}
	printf("%s:%i - cmd : %s\n", client->ip, client->addr.sin_port, data);
	if (execute[cmd](client, data, &log) == ERROR)
		write_log(client, &log);
	printf("Connection closed with %s:%i\n", client->ip, client->addr.sin_port);
	bzero(client, sizeof(t_net));
}

/* Main Controller function */
int				main(int argc, char *argv[])
{
	t_net	server;
	t_net	client;

	if (argc == 1)
	{
		printf("Enter a port number to launch the server\n");
		return (0);
	}
	if (server_ini(&server, atoi(argv[1])) == ERROR)
		exit(errno);
	if (wait_for_client(&server, &client) == ERROR)
		exit(errno);
	launch_server(&client);
	close(server.sock);
	bzero(&server, sizeof(t_net));
	return (0);
}