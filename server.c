/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 09:41:59 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/17 20:25:42 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "network.h"

int main(void)
{
	t_connection	client;
	t_connection	server;
	char			text[] = "hello world\n";

	/* Création d'une socket */
	if (connection_ini(&server, TCP_IP) != INVALID_SOCKET)
	{
		printf("La socket %d est ouvert en mode TCP/IP\n", server.socket);
		/* Configuration */
		if (bind_to_mask(&server, INADDR_ANY, 23) != SOCKET_ERROR)
		{
			/* Démarrage du listage (mode server) */
			printf("Listage du port %d...\n", 23);
			printf("Serveur IP : %s\n", server.ip);
			if (listen_connection(&server, 5) != SOCKET_ERROR)
			{
				/* Attente pendant laquelle le client se connecte */
				printf("Patientez sur le port %d...\n", 23);
				accept_connection(&server, &client);
				printf("Un client se connecte avec la socket %d de %s:%d\n",\
				 client.socket, client.ip, client.port);
				if (send_to(&client, text, sizeof(text)) == SOCKET_ERROR)
					printf("Erreur de transmission");
				else
					printf("donnée transmise : %s", text);
			}
			else
				perror("listen");
		}
		else
			perror("bind");
		/* Fermeture de la socket client et de la socket serveur */
		printf("Fermeture de la socket client\n");
		shutdown_connection(&client, READ_WRITE);
		close_connection(&client);
		printf("Fermeture de la socket serveur\n");
		close_connection(&server);
		printf("Fermeture du serveur terminée\n");
	}
	else
		perror("socket");
	return (0);
}
