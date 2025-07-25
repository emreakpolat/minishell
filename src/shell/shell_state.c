/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 00:11:56 by ysumeral          #+#    #+#             */
/*   Updated: 2025/07/21 13:57:15 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int error_handler(char *message)
{
    if (message)
        write(2, message, ft_strlen(message));
    return (FAILURE);
}

int shell_exit_with_error(char *message, t_command *command)
{
    if (message)
        write(2, message, ft_strlen(message));
    memory_free(command);
    exit(FAILURE);
    return (FAILURE);
}

int shell_exit(t_command *command, int exit_code)
{
    memory_free(command);
    // Environment'ı burada free etme - shell_loop'ta yapılıyor
    exit(exit_code);
    return (exit_code);
}
