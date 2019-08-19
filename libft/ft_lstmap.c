/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:36:54 by krutten           #+#    #+#             */
/*   Updated: 2018/10/10 21:30:53 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*reader;
	t_list	*mapped;
	t_list	*newhead;
	t_list	*mapreader;

	reader = lst;
	newhead = NULL;
	while (reader)
	{
		mapped = malloc(sizeof(t_list));
		mapped = f(reader);
		if (!newhead)
		{
			newhead = mapped;
			mapreader = mapped;
		}
		else
		{
			mapreader->next = mapped;
			mapreader = mapreader->next;
		}
		reader = reader->next;
	}
	return (newhead);
}
