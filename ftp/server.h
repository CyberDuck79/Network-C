/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:46:52 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 00:50:39 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

/*FTP server*/
# include <sys/socket.h>
# include <netinet/in.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
/*for getting file size using stat()*/
# include <sys/stat.h>
/*for sendfile()*/
# include <sys/types.h>
# include <sys/uio.h>
/*for O_RDONLY*/
# include <fcntl.h>

# define ERROR -1
# define BUFF_SIZE 256

typedef struct stat		t_stat;
typedef struct sockaddr	t_addr;

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

# define CMD_TAB_LEN 7
# define CMD_STR_TAB {"ls", "get", "put", "pwd", "bye", "quit", ""}
# define CMD_LEN_TAB {2, 3, 3, 3, 3, 4, 1}
# define CMD_TAB {LS, GET, PUT, PWD, BYE, QUIT, UNKNOWN}

typedef struct			s_connection
{
	struct sockaddr_in	addr;
	int					sock;
	socklen_t			len;
}						t_connection;

typedef void			(*t_exec_cmd)(t_connection *client, char data[BUFF_SIZE]);

void					cmd_ini(t_exec_cmd cmd_tab[CMD_TAB_LEN]);

#endif