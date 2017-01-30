/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 00:22:27 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/30 02:53:35 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "libft.h"

/* Assume: */
/* int	opterr = 1,		/\* if error message should be printed *\/ */
/* 	optind = 1,		/\* index into parent argv vector *\/ */
/* 	optopt,			/\* character checked for validity *\/ */
/* 	optreset;		/\* reset getopt *\/ */
/* char	*optarg; /\* argument associated with option *\/ */

void		ft_getopt_error(char *name, char *error)
{
	char	c[2];

	if (opterr)
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

static void		ft_getopt_reset(void)
{
	if (!optind || optreset == 1)
	{
		optind = 1;
		optreset = 0;
	}
}

static int		ft_getopt_valid(char *const argv[], const char *optstring,
								char *opt)
{
	// The option take an argument
	if (opt[1] == ':')
	{
		// The flag has an argument without a whitespace
		if (argv[(uintptr_t)optind][2])
			optarg = (char*)argv[(uintptr_t)optind];
		// The flag has an arguement with a whitespace
		else if (argv[(uintptr_t)optind + 1])
			optarg = (char*)argv[(uintptr_t)optind++ + 1];
		// The flag should have had an arguemnt
		else
		{
			ft_getopt_error((char*)argv[0], "option requires an argument");
			++optind;
			return ((*optstring == ':' ? ':' : '?'));
		}
		++optind;
		return (optopt);
	}
	// This option doesn't take argument
	optarg = (char*)argv[(uintptr_t)optind];
	return (optopt);
}

int		ft_getopt(int argc, char *const argv[], const char *optstring)
{
	int		arg_i;
	char	*opt;
	int		result;

	ft_getopt_reset();
	// There is still argument to process
	if (optind < argc)
	{
		arg_i = 0;
		while (argv[(uintptr_t)optind] && argv[(uintptr_t)optind][arg_i])
		{
			(optopt = argv[(uintptr_t)optind][arg_i]);
			if (optopt == '-')
				;
			// The option is valid
			else if ((opt = ft_strchr(optstring, optopt)) != NULL)
				result = ft_getopt_valid(argv, optstring, opt);
			// The option is invalid
			else
			{
				ft_getopt_error((char*)argv[0], "illegal option");
				++optind;
				result = '?';
			}
			++arg_i;
		}
		++optind;
		return (result);
	}
	// Argument list exhausted
	++optind;
	return (-1);
}
