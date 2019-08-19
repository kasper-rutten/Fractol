/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:10:18 by krutten           #+#    #+#             */
/*   Updated: 2018/10/10 21:24:45 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*reader;

	reader = *alst;
	while (reader)
	{
		(*del)(reader->content, reader->content_size);
		free(reader);
		reader = reader->next;
	}
	*alst = NULL;
}
