/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:46:52 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 10:44:11 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

/*FTP server*/
# include <sys/socket.h>
# include <netinet/in.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
/*for getting file size using stat()*/
# include <sys/stat.h>
/*for sendfile()*/
# include <sys/types.h>
# include <sys/uio.h>
/*for O_RDONLY*/
# include <fcntl.h>
#include "cmd_ini.h"

/*Global Define*/
# define ERROR			-1
# define BUFF_SIZE		256

/*Implemented commands list*/
typedef enum			e_cmd
{
	LS,
	GET,
	PUT,
	PWD,
	BYE,
	QUIT,
	UNKNOWN
}						t_cmd;

/*Command parsing array*/
# define CMD_TAB_LEN	7
# define CMD_STR_TAB	{"ls", "get", "put", "pwd", "bye", "quit", ""}
# define CMD_LEN_TAB 	{2, 3, 3, 3, 3, 4, 0}
# define CMD_TAB		{LS, GET, PUT, PWD, BYE, QUIT, UNKNOWN}

/*Shortcut typedef*/
typedef struct stat		t_stat;
typedef struct sockaddr	t_addr;

/*Networking struct*/
typedef struct			s_connection
{
	struct sockaddr_in	addr;
	int					sock;
	socklen_t			len;
}						t_connection;

#endif