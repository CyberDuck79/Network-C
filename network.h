/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 09:42:40 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 14:42:01 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_H
# define NETWORK_H

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <unistd.h>

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# define INVALID_SOCKET -1
# define SOCKET_ERROR -1

typedef			int t_socket;
typedef struct	hostent	t_host;
typedef struct	sockaddr_in t_sock_in;
typedef struct	sockaddr t_addr;
typedef struct	in_addr t_in_addr;

typedef enum	e_protocol
{
	TCP_IP,
	UDP_IP,
	RAW_IP,
	TCP_IP6,
	UDP_IP6,
	RAW_IP6
}				t_protocol;

typedef enum	e_port
{
	DNS = 53,
	HTTP = 80,
	HTTPS = 443,
	TERMCHAT = 5669
}				t_port;

typedef enum	e_direction
{
	READ,
	WRITE,
	READ_WRITE
}				t_direction;

typedef struct	s_connection
{
	t_socket	socket;
	int			network;
	int			transport;
	t_host		*host;
	char		*ip;
	char		*mask;
	int			port;
	socklen_t	addr_len;
	t_sock_in	addr;
}				t_net;

int				connection_ini(t_net *this, t_protocol protocol);
int				connect_to_ip(t_net *this, char *ip, t_port port);
int				bind_to_ip(t_net *this, char *ip, t_port port);
int				bind_to_mask(t_net *this, u_int32_t ip, t_port port);
int				connect_to_host(t_net *this, char *hostname, t_port port);
int				bind_to_host(t_net *this, char *hostname, t_port port);
int				listen_connection(t_net *this, int queue);
int				accept_net(t_net *from, t_net *to);
int				send_to(t_net *to, void *buffer, size_t len);
int				receive_from(t_net *from, void *buffer, size_t len);
void			close_connection(t_net *this);
int				shutdown_connection(t_net *this, t_direction flag);

#endif
