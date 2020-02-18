/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:29:06 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 15:51:13 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "server.h"
# include "log.h"

# define FILE_BUFF 4096

int		cmd_ls(t_net *client, char data[BUFF_SIZE], t_log *log);
int		cmd_get(t_net *client, char data[BUFF_SIZE], t_log *log);
int		cmd_put(t_net *client, char data[BUFF_SIZE], t_log *log);
int		cmd_pwd(t_net *client, char data[BUFF_SIZE], t_log *log);
int		cmd_cd(t_net *client, char data[BUFF_SIZE], t_log *log);
int		cmd_quit(t_net *client, char data[BUFF_SIZE], t_log *log);
int		cmd_unknown(t_net *client, char data[BUFF_SIZE], t_log *log);

#endif
