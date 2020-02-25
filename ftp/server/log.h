/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:42:42 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/24 12:48:17 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include "server.h"

/* Error log messages macros */
# define LOG_MSG_TAB_LEN 8
# define LOG_LOGIN "Login error"
# define LOG_READ "Read file error"
# define LOG_WRITE "Write file error"
# define LOG_SIZE "Send size error"
# define LOG_SEND "Send file error"
# define LOG_RECV "Receive file error"
# define LOG_CLOSE "Closing connection error"
# define LOG_CMD "Error command unknown"
# define LOG_MSG_TAB {LOG_LOGIN,LOG_READ,LOG_WRITE,LOG_SIZE,LOG_SEND,LOG_RECV,LOG_CLOSE,LOG_CMD}

/* Error type enum */
typedef enum	e_error
{
	LOG,
	READ,
	WRITE,
	SIZE,
	SEND,
	RECV,
	CLOSE,
	CMD
}				t_error;

/* Log struct */
typedef struct	s_log
{
	int			error;
	t_error		msg_i;
	const char	*name;
	char		*time;
}				t_log;

/* Errors logging function */
void			log_error(t_log *log, const char *name, t_error i);
/* Error logs writing function */
void			write_log(t_net *client, t_log *log, const char *filename);
/* Exit program with error output */
void			error_exit(void);
#endif
