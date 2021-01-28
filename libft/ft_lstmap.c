/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:41:52 by iouali            #+#    #+#             */
/*   Updated: 2020/11/23 10:54:24 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*elt;

	if (!lst || !f)
		return (NULL);
	if (!(elt = ft_lstnew((*f)(lst->content))))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst->next;
	new_lst = elt;
	while (lst)
	{
		if (!(elt = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, elt);
	}
	return (new_lst);
}
