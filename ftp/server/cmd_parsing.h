/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:47:27 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 16:55:48 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_PARSING_H
# define CMD_PARSING_H

#include "server.h"

/* Command parsing array macros */
# define CMD_TAB_LEN 8
# define CMD_STR_TAB {"ls", "get ", "put ", "pwd", "cd ", "bye", "quit", ""}
# define CMD_LEN_TAB {2, 4, 4, 3, 3, 3, 4, 0}
# define CMD_TAB	 {LS, GET, PUT, PWD, CD, BYE, QUIT, UNKNOWN}

/* Command parsing function */
t_cmd		parse_cmd(t_net *client, char data[BUFF_SIZE]);

#endif