/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:42:42 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 16:59:07 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include "server.h"

/* Error log messages macros */
# define LOG_READ "Impossible to read file"
# define LOG_SIZE "Impossible to send size"
# define LOG_SEND "Impossible to send file"
# define LOG_RECV "Impossible to receive file"
# define LOG_CLOSE "Error while closing connection"
# define LOG_CMD "Error command unknown"
# define LOG_MSG_TAB {LOG_READ,LOG_SIZE,LOG_SEND,LOG_RECV,LOG_CLOSE,LOG_CMD}

/* Error type enum */
typedef enum	e_error
{
	READ,
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
	const char	*message;
	char		*name;
	char		*time;
}				t_log;

/* Errors logging function */
void			log_error(time_t *log_time, t_log *log, char *name, t_error i);
/* Error logs writing function */
void			write_log(t_log *log);

#endif
