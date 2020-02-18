/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 00:27:00 by fhenrion          #+#    #+#             */
/*   Updated: 2020/02/18 11:41:48 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "cmd_ini.h"

void			cmd_ini(t_exec_cmd cmd_tab[CMD_TAB_LEN])
{
	cmd_tab[LS] = cmd_ls;
	cmd_tab[GET] = cmd_get;
	cmd_tab[PUT] = cmd_put;
	cmd_tab[PWD] = cmd_pwd;
	cmd_tab[CD] = cmd_cd;
	cmd_tab[BYE] = cmd_quit;
	cmd_tab[QUIT] = cmd_quit;
	cmd_tab[UNKNOWN] = cmd_unknown;
}
