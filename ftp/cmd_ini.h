/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ini.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 08:48:17 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 10:46:10 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_INI_H
# define CMD_INI_H

#include "server.h"

/*Typedef commands array*/
typedef	void (*t_exec_cmd)(t_connection *client, char data[BUFF_SIZE]);

/*Commands array initialization array*/
void	cmd_ini(t_exec_cmd cmd_tab[CMD_TAB_LEN]);

#endif
