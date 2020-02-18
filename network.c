/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:23:23 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/17 20:28:55 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "network.h"

int			connection_ini(t_connection *this, t_protocol protocol)
{
	bzero(this, sizeof(t_connection));
	this->addr_len = sizeof(this->addr);
	if (protocol < 3)
		this->network = AF_INET;
	else
		this->network = AF_INET6;
	if (protocol == 0 || protocol == 3)
		this->transport = SOCK_STREAM;
	else if (protocol == 1 || protocol == 4)
		this->transport = SOCK_DGRAM;
	else
		this->transport = SOCK_RAW;
	this->socket = socket(this->network, this->transport, 0);
	return (this->socket);
}

int			connect_to_ip(t_connection *this, char *ip, t_port port)
{
	this->ip = ip;
 	this->addr.sin_addr.s_addr = inet_addr(ip);
	this->addr.sin_family = this->network;
	this->addr.sin_port = htons(port);
	this->port = port;
	return (connect(this->socket, (t_addr*)&this->addr, this->addr_len));
}

int			bind_to_ip(t_connection *this, char *ip, t_port port)
{
	this->ip = ip;
 	this->addr.sin_addr.s_addr = inet_addr(ip);
	this->addr.sin_family = this->network;
	this->addr.sin_port = htons(port);
	this->port = port;
	return(bind(this->socket, (t_addr*)&this->addr, this->addr_len));
}

int			bind_to_mask(t_connection *this, u_int32_t ip, t_port port)
{
	this->addr.sin_addr.s_addr = htonl(ip);
	this->addr.sin_family = this->network;
	this->addr.sin_port = htons(port);
	this->mask = inet_ntoa(this->addr.sin_addr);
	//this->ip = get_local_ip(); TODO : get local ip
	this->port = port;
	return(bind(this->socket, (t_addr*)&this->addr, this->addr_len));
}

int			connect_to_host(t_connection *this, char *hostname, t_port port)
{
	this->host = gethostbyname(hostname);
	this->addr.sin_addr = *(t_in_addr*)this->host->h_addr;
	this->addr.sin_family = this->network;
	this->addr.sin_port = htons(port);
	this->port = port;
	return(connect(this->socket, (t_addr*)&this->addr, this->addr_len));
}

int			bind_to_host(t_connection *this, char *hostname, t_port port)
{
	this->host = gethostbyname(hostname);
	this->addr.sin_addr = *(t_in_addr*)this->host->h_addr;
	this->addr.sin_family = this->network;
	this->addr.sin_port = htons(port);
	this->port = port;
	return(bind(this->socket, (t_addr*)&this->addr, this->addr_len));
}

int			listen_connection(t_connection *this, int queue)
{
	return (listen(this->socket, queue));
}

int			accept_connection(t_connection *from, t_connection *to)
{
	bzero(to, sizeof(t_connection));
	to->addr_len = sizeof(to->addr);
	to->socket = accept(from->socket, (t_addr*)&to->addr, &to->addr_len);
	to->ip = inet_ntoa(to->addr.sin_addr);
	to->port = htons(to->addr.sin_port);
	to->network = from->network;
	to->transport = from->transport;
	return (to->socket);
}

int			send_to(t_connection *to, void *buffer, size_t len)
{
	return(send(to->socket, buffer, len, 0));
}

int			receive_from(t_connection *from, void *buffer, size_t len)
{
	return (recv(from->socket, buffer, len, 0));
}

void		close_connection(t_connection *this)
{
	this->host = NULL;
	this->ip = NULL;
	close(this->socket);
}

int			shutdown_connection(t_connection *this, t_direction flag)
{
	return (shutdown(this->socket, flag));
}
