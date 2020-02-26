/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:46:52 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/26 15:19:59 by fhenrion         ###   ########.fr       */
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
# define BUFF_SIZE		1024

/* Implemented commands enum */
typedef enum			e_cmd
{
	LOGIN,
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

/* User struct */
typedef struct		s_user
{
	char			*login;
	char			*password;
	char			*path;
	struct s_user	*next;
}					t_user;

/* Networking struct */
typedef struct			s_net
{
	struct sockaddr_in	addr;
	int					sock;
	socklen_t			len;
	char				*ip;
	t_user				*user;
}						t_net;

/* Loaded user database */
t_user	*g_users;

/* User database loading function */
int						userbase_loading(t_user **users, const char *filename);

/* Parsing util function */
char					*substr_chr(const char **line, char end);

#endif
