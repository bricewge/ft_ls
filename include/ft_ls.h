/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:28:28 by bwaegene          #+#    #+#             */
/*   Updated: 2017/02/05 12:57:26 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/stat.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <stdlib.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include "libft.h"

typedef	struct dirent	t_dirent;
typedef struct timespec	t_timespec;
typedef	struct stat		t_stat;
typedef struct			s_ls
{
	t_dirent			dirent;
	t_stat				stat;
}						t_ls;

void					usage(char *options);

int						error(char *name, char *path);
char					*file_mode(mode_t mode);
char					file_type(mode_t mode);

void					display_one(t_ls *entry, int length);
void					display_long(t_ls *entry, int lenght);
#endif
