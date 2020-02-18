/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:46:52 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 17:07:41 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

/* Libc headers */
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

/* Globals macros */
# define ERROR			-1
# define BUFF_SIZE		256

/* Implemented commands enum */
typedef enum			e_cmd
{
	LS,
	GET,
	PUT,
	PWD,
	CD,
	BYE,
	QUIT,
	UNKNOWN
}						t_cmd;

/* Shortcut typedef */
typedef struct stat		t_stat;
typedef struct sockaddr	t_addr;

/* Networking struct */
typedef struct			s_connection
{
	struct sockaddr_in	addr;
	int					sock;
	socklen_t			len;
	char				*ip;
}						t_net;

/* File handling struct */
typedef struct			s_file
{
	char				*name;
	t_stat				stat;
	off_t				size;
	int					fd;
}						t_file;

#endif
