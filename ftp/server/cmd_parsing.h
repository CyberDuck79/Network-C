/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:47:27 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/26 15:12:01 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_PARSING_H
# define CMD_PARSING_H

#include "server.h"

/* Command parsing array macros */
# define CMD_TAB_LEN 9
# define CMD_STR_TAB {"login ", "ls", "get ", "put ", "pwd", "cd ", "bye", "quit", ""}
# define CMD_LEN_TAB {6, 2, 4, 4, 3, 3, 3, 4, 0}
# define CMD_TAB	 {LOGIN, LS, GET, PUT, PWD, CD, BYE, QUIT, UNKNOWN}

/* Command parsing function */
t_cmd		parse_cmd(t_net *client, char data[BUFF_SIZE]);

#endif
