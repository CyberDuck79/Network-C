/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ini.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 08:48:17 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/19 11:29:33 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_INI_H
# define CMD_INI_H

# include "client.h"

# define CMD_TAB_LEN 6

/* Typedef commands array */
typedef int		(*t_exec_cmd)(t_net *server, char data[BUFF_SIZE]);

/* Commands array initialization function */
void			cmd_ini(t_exec_cmd cmd_tab[CMD_TAB_LEN]);

#endif
