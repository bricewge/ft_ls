/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:28:28 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/29 00:28:03 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS
# include <sys/stat.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include "libft.h"

typedef	struct dirent	t_dirent;
typedef	struct stat t_stat;
void	usage(char *options);
int		error(char *name, char *path);
char	*file_mode(mode_t mode);
#endif
