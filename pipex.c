/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:16:45 by hugo-mar          #+#    #+#             */
/*   Updated: 2024/09/23 16:41:58 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex_data	data;

	if (argc != 5)
		return (1);
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	data.nbr_pipes = argc - 2;
	data.labor_type = 0;
	data.pipes = pipemaker(data.nbr_pipes);
	child_labor(&data);
	parent_pipe_setup(&data);
	wait_for_children(&data);
	freepipes(data.pipes, data.nbr_pipes);
	free(data.p_ids);
	return (data.exit_status);
}
