/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:49:11 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/09 16:18:49 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include <stdlib.h>
# include <stdbool.h>

struct	s_dlist;
typedef struct	s_dlist	t_dlist;

struct			s_dlist
{
	void	*content;
	t_dlist	*next;
	t_dlist	*prev;
};

/*
 * dlist.c
 */
t_dlist			*dlist_new(void *content);
void			dlist_destroy(t_dlist **lst, void (*del)(void *));
t_dlist			*dlist_copy(t_dlist *lst);

/*
 * ref.c
 */
t_dlist			*dlist_front(t_dlist *lst);
t_dlist			*dlist_back(t_dlist *lst);
size_t			dlist_size(t_dlist *lst);
bool			dlist_empty(t_dlist *lst);

/*
 * push.c
 */
void			dlist_push_front(t_dlist **lst, t_dlist *newlst);
void			dlist_push_back(t_dlist **lst, t_dlist *newlst);
t_dlist			*dlist_insert(t_dlist **lst, t_dlist *newlst);

/*
 * pop.c
 */
void			dlist_pop_front(t_dlist **lst, void (*del)(void *));
void			dlist_pop_back(t_dlist **lst, void (*del)(void *));
t_dlist			*dlist_erase(t_dlist **lst, void (*del)(void *));

/*
 * operate.c
 */
void			dlist_swap(t_dlist *a, t_dlist *b);
void			dlist_qsort(t_dlist *front, t_dlist *back,
		bool cmp(void *, void *));
void			dlist_qsort4(t_dlist *front, t_dlist *back,
		bool cmp(void *, void *, void *), void *arg);

#endif
