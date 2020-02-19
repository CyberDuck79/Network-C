/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:37:30 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/19 17:48:27 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

/* Libc headers */
# include <sys/socket.h>
# include <netinet/in.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>

/* Globals macros */
# define ERROR			-1
# define BUFF_SIZE		1024

/* Implemented commands enum */
typedef enum			e_cmd
{
	LS,
	GET,
	PUT,
	PWD,
	CD,
	QUIT,
}						t_cmd;

/* Shortcut typedef */
typedef struct stat		t_stat;
typedef struct sockaddr	t_addr;

/* Networking struct */
typedef struct			s_net
{
	struct sockaddr_in	addr;
	int					sock;
	socklen_t			len;
	char				*ip;
}						t_net;

/* File handling struct */
typedef struct			s_file
{
	char				name[256];
	t_stat				stat;
	int					size;
	char				*data;
	int					fd;
}						t_file;

#endif
