/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:47:06 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/26 15:09:18 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_parsing.h"

/* Commands parsing informations arrays */
static const char	*cmd_str[CMD_TAB_LEN] = CMD_STR_TAB;
static const size_t	cmd_len[CMD_TAB_LEN] = CMD_LEN_TAB;
static const t_cmd	cmd[CMD_TAB_LEN] = CMD_TAB;

/* Command parsing to index function */
t_cmd		parse_cmd(t_net *client, char data[BUFF_SIZE])
{
	size_t				index = 0;

	recv(client->sock, data, BUFF_SIZE, 0);
	while (index < CMD_TAB_LEN)
	{
		if (!strncmp(data, cmd_str[index], cmd_len[index]))
			return (cmd[index]);
		index++;
	}
	return (UNKNOWN);
}
