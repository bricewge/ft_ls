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
# define OPTIONS "Ralrt"

typedef	struct dirent	t_dirent;
typedef struct timespec	t_timespec;
typedef	struct stat		t_stat;
typedef struct			s_ls
{
	t_dirent			dirent;
	t_stat				stat;
}						t_ls;
typedef struct			s_opt
{
	int 				dlong : 1;
	int 				done : 1;
	int 				recur : 1;
	int 				all : 1;
	int 				sortrev : 1;
	int 				sortmtime : 1;
	int 				sortatime : 1;
	int 				color : 1;
	int 				sortno : 1;
	int 				dir : 1;
	int 				grpname : 1;
}						t_opt;

void					usage(char *options);

int						error(char *path);
char					*progname(char *name);

char					*file_mode(t_ls entry, char *dirname);
char					file_type(mode_t mode);

t_opt					options(t_opt *opt);
void					opt_parse(int *ac, char ***av);

void					display(char *av);
void					display_one(t_ls *entry, int length);
void					display_long(t_ls *entry, int lenght, char *dirname);

int						alphacmp(const void *p1, const void *p2);
int						mtimecmp(const void *p1, const void *p2);
int						atimecmp(const void *p1, const void *p2);

void					dirent(char *dirname);
int						dirent_cnt(char *dirname);
t_ls					*dir_store(char *dirname, int length);

char					*padding(char *str, int len, int pos);
void					putstrp(char *str, int len, int pos);
void					putnbrp(int nbr, int len, int pos);
void					padsize(t_ls *entry, int length, int *padlen);

char					*ft_pathjoin(const char *dir, const char *file);
#endif
