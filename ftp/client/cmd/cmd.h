/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:29:06 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/19 12:08:22 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <dirent.h>

# include "../client.h"

/* Buffer size macro for file reception */
# define FILE_BUFF 4096

/* Command functions */
int		cmd_ls(t_net *server, char data[BUFF_SIZE]);
int		cmd_get(t_net *server, char data[BUFF_SIZE]);
int		cmd_put(t_net *server, char data[BUFF_SIZE]);
int		cmd_pwd(t_net *server, char data[BUFF_SIZE]);
int		cmd_cd(t_net *server, char data[BUFF_SIZE]);
int		cmd_quit(t_net *server, char data[BUFF_SIZE]);

#endif
