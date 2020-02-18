/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:49:53 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 14:42:01 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "network.h"

int main(void)
{
	t_net	server;
	char			data[1024];

	/* Création de la socket */
	if (connection_ini(&server, TCP_IP) != INVALID_SOCKET)
	{
		/* Si le client arrive à se connecter */
		if (connect_to_ip(&server, "127.0.0.1", 23) != SOCKET_ERROR)
		{
			printf("Connexion à %s sur le port %d\n", server.ip, server.port);
			if (receive_from(&server, data, sizeof(data)) != SOCKET_ERROR)
				printf("Recu : %s", data);
		}
		else
			perror("connect");
		/* On ferme la socket précédemment ouverte */
		close_connection(&server);
		connection_ini(&server, TCP_IP);
		if (connect_to_host(&server, "google.com", HTTP) != SOCKET_ERROR)
		{
			printf("connected to google\n");
			send_to(&server, data, strlen(data));
			while (receive_from(&server, data, sizeof(data)))
				printf("data : %s\n", data);
		}
		else
			printf("google do not like us\n");
		close_connection(&server);
	}
	else
		perror("socket");
	return (0);
}
