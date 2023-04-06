/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:16:45 by jumoncad          #+#    #+#             */
/*   Updated: 2023/04/06 17:44:44 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void init_cmd(t_cmd *c, int f)
{
	c->f = f;
	c->path = 0;
	c->cmd = 0;
	c->args[0] = 0;
}

static char **get_path(char **ep)
{
	char **ret;
	char **env;
	int i;

	i = -1;
	while (ep[++i])
	{
		if (ft_substr(ep[i], "PATH=", PATH))
		{
			env = ft_substr(ep[i], START, ft_strlen(ep[i]));
			if (!env)
				return(NULL);
			ret = ft_splitpath(env,":");
			if(!ret)
			{
				free(ret);
				return(NULL);
			}
			free(env);
			return (ret);
		}
	}
	return (NULL);
}

static int get_cmd(char **enp, t_cmd *c, char *cmd)
{
	int i;
	char **tmp;

	i = -1;
	c->path = get_path(enp);
	if(!tmp)
		return (0);
	c->cmd = ft_substr(tmp[i + 1], 0, ft_strlen(cmd));
	
}

void pipex(int f1, int f2, char **ag, char **envp)
{
	t_cmd cmd1;
	t_cmd cmd2;

	init_cmd(&cmd1, f1);
	init_cmd(&cmd2, f2);
	if (!get_cmd(envp,&cmd1,ag[2]) || !get_cmd(envp,&cmd2,ag[4]))
		return(free_all(&cmd1,&cmd2));
	if(!check_cmd(&cmd1) || !check_cmd(&cmd2))
		return(free_all(&cmd1,&cmd2));
	execv(&cmd1, &cmd2);
}