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
# define OPTIONS "1Ralrt"

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
	t_uint				dlong : 1;
	t_uint				done : 1;
	t_uint				recur : 1;
	t_uint				all : 1;
	t_uint				sortrev : 1;
	t_uint				sortmtime : 1;
	t_uint				sortatime : 1;
	t_uint				color : 1;
	t_uint				sortno : 1;
	t_uint				dir : 1;
	t_uint				grpname : 1;
}						t_opt;

void					usage(char *options);

int						error(char *path);
char					*progname(char *name);

char					*file_mode(t_ls entry, char *dirname);
char					file_type(mode_t mode);

t_opt					options(t_opt *opt);
int						opt_needstat(void);
void					opt_parse(int *ac, char ***av);

void					display(char *av);
void					display_one(t_ls *entry, int length, int dir);
void					display_long(t_ls *entry, int lenght, char *dirname,
										int flag[2]);

int						alphacmp(const void *p1, const void *p2);
int						mtimecmp(const void *p1, const void *p2);
int						atimecmp(const void *p1, const void *p2);

void					dirent(char *dirname, int ac);
int						dirent_cnt(char *dirname);
t_ls					*dir_store(char *dirname, int length);

char					*padding(char *str, int len, int pos);
void					putstrp(char *str, int len, int pos);
void					putnbrp(int nbr, int len, int pos);
void					padsize(t_ls *entry, int length, int *padlen, int dir);
void					putdirname(char *dir, int *first);

void					arg_sort(int argc, char ***argv);

char					*ft_pathjoin(const char *dir, const char *file);
void					arg_files(int ac, char **argv);
void					arg_files2(t_ls *fcont, int ac, int distype[],
									char *dirname);

void					putlongls(t_ls entry, char *dirname, int *padlen);
#endif
