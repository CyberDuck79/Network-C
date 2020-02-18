/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ini.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 08:48:17 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 16:54:36 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_INI_H
# define CMD_INI_H

#include "server.h"
#include "cmd_parsing.h"
#include "log.h"

/* Typedef commands array */
typedef int		(*t_exec_cmd)(t_net *client, char data[BUFF_SIZE], t_log *log);

/* Commands array initialization function */
void			cmd_ini(t_exec_cmd cmd_tab[CMD_TAB_LEN]);

#endif
