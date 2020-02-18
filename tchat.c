/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tchat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:52:28 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 14:42:01 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "network.h"

static int	print_presentation(void)
{
	int	answer;

	printf("Bienvenue dans tchatTERM\n");
	printf("Dans quel mode souhaitez-vous démarrer ?\n");
	printf("1) Attendre la connexion d'un invité\n");
	printf("2) Lancer une demande de connexion à un hôte distant\n");
	printf("autre nombre) Quitter le programme\n");
	if (scanf("%i", answer) == EOF)
		return (-1);
	return (answer);
}

static int	print_net(void)
{
	int	answer;

	printf("\nQuel type d'adresse souhaitez-vous utiliser ?\n");
	printf("1) Nom d'hôte\n");
	printf("2) Adresse IP\n");
	printf("autre nombre) Quitter le programme\n");
	if (scanf("%i", answer) == EOF)
		return (-1);
	return (answer);
}

static int	wait_for_connection(void)
{
	t_net	host;
	t_net	guest;

	if (connection_ini(&host, TCP_IP) != INVALID_SOCKET)
	{
		if (bind_to_mask(&host, INADDR_ANY, TERMCHAT) != SOCKET_ERROR)
		{
			printf("En attente d'un hote sur le port %d...\n", TERMCHAT); // mettre le hostname et l'ip
			accept_net(&host, &guest);
			printf("Un invité se connecte depuis %s\n", guest.ip); // mettre le hostname
			launch_tchat(&host, &guest);
		}
		else
		{
			perror("bind");
			return (-1);
		}
	}
	else
	{
		perror("connect");
		return (-1);
	}
	return (0);
}

int			main(void)
{
	int answer;

	if ((answer = print_presentation()) == -1)
	{
		perror("input");
		exit(errno);
	}
	if (answer == 1)
		if (wait_for_connection() == -1)
			exit(errno);
	if (answer == 2)
	{
		if ((answer = print_net()) == -1)
		{
			perror("input");
			exit(errno);
		}
		if (answer == 1)
			request_distant_host();
		else if (answer == 2)
			request_distant_ip();
	}
	return (0);
}