/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 00:22:27 by bwaegene          #+#    #+#             */
/*   Updated: 2017/02/04 10:43:11 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "libft.h"

void		ft_getopt_error(char *name, char *error, const char *optstring)
{
	char	c[2];

	if (opterr && *optstring != ':')
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(error, 2);
		ft_putstr_fd(" -- ", 2);
		c[0] = (char)(uintptr_t)optopt;
		c[1] = '\0';
		ft_putendl_fd(c, 2);
	}
}

static int		ft_getopt_valid(char *const argv[], const char *optstring,
								char *opt, int *arg_i)
{
	optopt = argv[(uintptr_t)optind][*arg_i];
	// The option take an argument
	if (opt[1] == ':')
	{
		// The option has an argument without a whitespace
		if (argv[(uintptr_t)optind][*arg_i + 1])
		{
			optarg = (char*)argv[(uintptr_t)optind] + *arg_i + 1;
			++optind;
			*arg_i = 1;
		}
		// The option has an arguement with a whitespace
		else if (argv[(uintptr_t)optind + 1])
		{
			++optind;
			optarg = (char*)argv[(uintptr_t)optind++];
			*arg_i = 1;
		}
		// The option should have had an arguemnt
		else
		{
			ft_getopt_error((char*)argv[0], "option requires an argument", optstring);
			optind += 2;
			optarg = NULL;
			return ((optstring[0] == ':' ? ':' : '?'));
		}
	}
	// This option doesn't take argument
	else
	{
		optarg = NULL;
		// There are other option left to process in this argument
		if (argv[(uintptr_t)optind][*arg_i + 1])
			++(*arg_i);
		// This is the last option in this argument
		else
		{
			++optind;
			*arg_i = 1;
		}
	}
	return (optopt);
}

int		ft_getopt(int argc, char *const argv[], const char *optstring)
{
	static int	arg_i = 1;
	char		*opt;

	if (optreset == 1)
	{
		optreset = 0;
		arg_i = 1;
	}
	if (ft_strequ(argv[(uintptr_t)optind], "--"))
	{
		++optind;
		return (-1);
	}
	// There is still arguments to process
	if (optind < argc && argv[(uintptr_t)optind][0] == '-')
	{
		while (argv[(uintptr_t)optind][arg_i])
		{
			// The option is valid
			if ((opt = ft_strchr(optstring, argv[(uintptr_t)optind][arg_i])) != NULL)
				return (ft_getopt_valid(argv, optstring, opt, &arg_i));
			// The option is invalid
			else
			{
				optopt = argv[(uintptr_t)optind][arg_i];
				if (optopt != '-')
					++optind;
				ft_getopt_error((char*)argv[0], "illegal option", optstring);
				return('?');
			}
			++arg_i;
		}
	}
	// Argument list exhausted
	return (-1);
}
