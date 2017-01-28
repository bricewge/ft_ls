/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:52:29 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/29 00:30:58 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*file_mode(mode_t mode)
{
	char	*result;

	result = ft_strdup("---------");
	if ( mode & S_IRUSR ) result[0] = 'r';
    if ( mode & S_IWUSR ) result[1] = 'w';
    if ( mode & S_IXUSR ) result[2] = 'x';
    if ( mode & S_IRGRP ) result[3] = 'r';
    if ( mode & S_IWGRP ) result[4] = 'w';
    if ( mode & S_IXGRP ) result[5] = 'x';
    if ( mode & S_IROTH ) result[6] = 'r';
    if ( mode & S_IWOTH ) result[7] = 'w';
    if ( mode & S_IXOTH ) result[8] = 'x';
	return (result);
}

char	*file_type(mode_t mode)
{
	if (S_ISREG(mode))
		return ("Fichier");
	if (S_ISDIR(mode))
		return ("Dossier");
	if (S_ISCHR(mode))
		return ("Character device");
	if (S_ISBLK(mode))
		return ("Block device");
	if (S_ISFIFO(mode))
		return ("FIFO");
	if (S_ISLNK(mode))
		return ("Lien symbolique");
	if (S_ISSOCK(mode))
		return ("Socket");
	return ("Inconnu");
}

int		main(int ac, char **av)
{
	t_stat	buf;

	if (ac == 2)
	{
		if (stat(av[1], &buf) == 0)
		{
			ft_putstr("Nom: ");
			ft_putendl(av[1]);
			ft_putstr("Type: ");
			ft_putendl(file_type((buf.st_mode)));
			ft_putstr("Modes: ");
			ft_putendl(file_mode((buf.st_mode)));
			ft_putstr("Nombre de liens: ");
			ft_putnbr(buf.st_nlink);
			ft_putchar('\n');
			ft_putstr("Proprietaire: ");
			ft_putendl(getpwuid(buf.st_uid)->pw_name);
			ft_putstr("Groupe: ");
			ft_putendl(getgrgid(buf.st_gid)->gr_name);
			ft_putstr("Taille: ");
			ft_putnbr(buf.st_size);
			ft_putstr(" octets\n");
			ft_putstr("Date de derniere modification: ");
			ft_putstr(ctime(&buf.st_mtimespec.tv_sec));
		}
	}
	return (0);
}
