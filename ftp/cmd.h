/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:29:06 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 08:44:02 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "server.h"

void	cmd_ls(t_connection *client, char data[BUFF_SIZE]);
void	cmd_get(t_connection *client, char data[BUFF_SIZE]);
void	cmd_put(t_connection *client, char data[BUFF_SIZE]);
void	cmd_pwd(t_connection *client, char data[BUFF_SIZE]);
void	cmd_quit(t_connection *client, char data[BUFF_SIZE]);
void	cmd_unknown(t_connection *client, char data[BUFF_SIZE]);

#endif
