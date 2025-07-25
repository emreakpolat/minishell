/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:40:47 by makpolat          #+#    #+#             */
/*   Updated: 2025/07/19 11:54:02 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	handle_builtin(t_command *command)
{
	if (ft_strcmp(command->args[0], "pwd") == 0)
		return (builtin_pwd());
	else if (ft_strcmp(command->args[0], "echo") == 0)
		return (builtin_echo(command));
	else if (ft_strcmp(command->args[0], "cd") == 0)
		return (builtin_cd(command));
	else if (ft_strcmp(command->args[0], "export") == 0) //TODO export ile eklenenler gözükmeyecek
		return (builtin_export(command, command->args));
	else if (ft_strcmp(command->args[0], "unset") == 0)
		builtin_unset(command, command->args);
	else if (ft_strcmp(command->args[0], "env") == 0)
		return (builtin_env(command));
	else if (ft_strcmp(command->args[0], "exit") == 0) //TODO syntax error kontrolleri
		return (builtin_exit(command, command->args));
	return (FAILURE);
}
