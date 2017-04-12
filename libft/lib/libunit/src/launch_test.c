/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:03:38 by starrit           #+#    #+#             */
/*   Updated: 2017/02/12 19:21:09 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	succes(t_test *tmp, int *res, int a)
{
	ft_putstr("    > ");
	ft_putstr(tmp->name);
	if (a == 0)
	{
		ft_putendl(": \033[32m[OK]\033[0m");
		res[0]++;
	}
	else
		ft_putendl(": \033[31m[KO]\033[0m");
}

static void	error(t_test *tmp, int status)
{
	ft_putstr("    > ");
	ft_putstr(tmp->name);
	if (status == 10)
		ft_putendl(": \033[31m[BUSE]\033[0m");
	else if (status == 11)
		ft_putendl(": \033[31m[SEGV]\033[0m");
	else if (status == 6)
		ft_putendl(": \033[31m[SIGABRT]\033[0m");
	else if (status == 14)
		ft_putendl(": \033[33m[TIMEOUT]\033[0m");
	else
		ft_putendl(": \033[31m[UNEXPECTED SIGNAL ERROR]\033[0m");
}

static void	father_part(t_test *tmp, int *res_test, int ret)
{
	int		status;

	status = 0;
	wait(&status);
	if (!WIFSIGNALED(status))
	{
		ret = WEXITSTATUS(status);
		if (ret == 0)
			succes(tmp, res_test, 0);
		else
			succes(tmp, res_test, 1);
	}
	else
		error(tmp, status);
	res_test[1]++;
}

void		launch_tests(t_test **testlist, int *res_test)
{
	t_test	*tmp;
	pid_t	pid;
	int		ret;

	tmp = *testlist;
	ret = 0;
	while (tmp)
	{
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
		{
			alarm(ALARM_TIMER);
			ret = tmp->f();
			del_test_lst(testlist);
			exit(ret);
		}
		else
		{
			father_part(tmp, res_test, ret);
			tmp = tmp->next;
		}
	}
}
