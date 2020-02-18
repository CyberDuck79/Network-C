/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:47:06 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 14:42:01 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_parsing.h"

static const char	*cmd_str[CMD_TAB_LEN] = CMD_STR_TAB;
static const size_t	cmd_len[CMD_TAB_LEN] = CMD_LEN_TAB;
static const t_cmd	cmd[CMD_TAB_LEN] = CMD_TAB;

t_cmd		parse_cmd(t_net *client, char data[BUFF_SIZE])
{
	size_t				index = 0;

	while (recv(client->sock, data, BUFF_SIZE, 0) == 0)
		sleep(1);
	while (index < CMD_TAB_LEN)
	{
		if (!strncmp(data, cmd_str[index], cmd_len[index]))
			return (cmd[index]);
		index++;
	}
	return (UNKNOWN);
}
