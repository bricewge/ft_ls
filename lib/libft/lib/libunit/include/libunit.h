/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:46:15 by starrit           #+#    #+#             */
/*   Updated: 2017/02/12 16:08:54 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H
# define ALARM_TIMER 10
# include <signal.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

typedef struct		s_test
{
	char			*name;
	int				(*f)(void);
	struct s_test	*next;
}					t_test;
/*
**			LIBFT FUNCTIONS
*/
size_t				ft_strlen(const char *s);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
void				ft_putchar(int c);
void				ft_putstr(char *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int nb);
/*
**			LIST FUNCTIONS
*/
t_test				*create_test_lst(void);
void				add_test_lst(t_test *base);
void				del_test_lst(t_test **base);
/*
**			LIBUNIT FUNCTIONS
*/
void				print_header(void);
void				load_test(t_test **testlist, char *name, int (*f)(void));
void				launch_tests(t_test **testlist, int *res_test);
int					print_total(int *res_test);
#endif
