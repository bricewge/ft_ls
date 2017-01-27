/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:52:29 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 16:06:53 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inspect_file.h"

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
			ft_putstr("Nombre de liens: ");
			ft_putstr("Proprietaire: ");
			ft_putendl(getpwuid(buf.st_uid)->pw_name);
			ft_putstr("Groupe: ");
			ft_putendl(getgrgid(buf.st_gid)->gr_name);
			ft_putstr("Taille: ");
			ft_putnbr(buf.st_size);
			ft_putstr(" octets\n");
			ft_putstr("Date de derniere modification: ");
			/* ft_putendl(buf.st_mtimespec); */
		}
	}
	return (0);
}
