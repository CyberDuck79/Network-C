/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:38:51 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/26 12:30:04 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "cmd_ini.h"

static int		client_ini(t_net *server, int port)
{
	if ((server->sock = socket(AF_INET, SOCK_STREAM, 0)) == ERROR)
		return (ERROR);
	server->len = sizeof (server->addr);
	server->addr.sin_family = AF_INET;
	server->addr.sin_port = port;
	server->addr.sin_addr.s_addr = 0;
	return (connect(server->sock, (t_addr*)&server->addr, server->len));
}

static t_cmd	get_cmd(void)
{
	char	input[256];
	t_cmd	cmd = 0;

	while (cmd < 1 || cmd > 6)
	{
		printf("Enter a choice:\n1- ls\n2- get\n3- put\n4- pwd\n5- cd\n6- quit\n");
		scanf("%s", input);
		cmd = atoi(input);
		if (cmd < 1 || cmd > 6)
			printf("Invalid choice %i\n", cmd);
	}
	return (cmd - 1);
}

static int		login_prompt(t_net *server)
{
	char	data[BUFF_SIZE];
	size_t	len;
	int		ret;

	bzero(data, BUFF_SIZE);
	strlcpy(data, "login ", 7);
	printf("Please enter your login :\n");
	scanf("%s", &data[6]);
	len = strlen(data);
	data[len] = ' ';
	printf("Please enter your password :\n");
	scanf("%s", &data[len + 1]);
	if (send(server->sock, data, strlen(data), 0) == ERROR)
		return (ERROR);
	if (recv(server->sock, &ret, sizeof(int), 0) == ERROR)
		return (ERROR);
	if (!ret)
		printf("Login or password incorrect, exit.\n"); // -> close connection client side ?
	else
		printf("Login successful, continue.\n");
	return (ret ? EXIT_SUCCESS : ERROR);
}

static void		launch_client(t_net *server)
{
	char		data[BUFF_SIZE];
	t_cmd		cmd;
	t_exec_cmd	execute[6];

	cmd_ini(execute);
	bzero(data, BUFF_SIZE);
	while ((cmd = get_cmd()) != QUIT)
	{
		if (execute[cmd](server, data) == ERROR)
			perror("server");
		bzero(data, BUFF_SIZE);
	}
	if (execute[cmd](server, data) == ERROR) // -> close connection client side ?
		perror("server");
}

int				main(int argc,char *argv[])
{
	t_net		server;
	

	if (argc == 1)
	{
		printf("Enter a port number to launch the client\n");
		return (0);
	}
	if (client_ini(&server, atoi(argv[1])) == ERROR)
	{
		perror("server");
		exit(errno);
	}
	if (login_prompt(&server) == ERROR)
	{
		perror("server");
		exit(errno);
	}
	launch_client(&server);
	return (0);
}