/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:25:33 by ramahrez          #+#    #+#             */
/*   Updated: 2025/02/19 20:03:40 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_list(t_list *list)
{
	t_list	*tmp;

	while (list != NULL)
	{
		tmp = list;
		free(list->content);
		list = list->next;
		free(tmp);
		tmp = NULL;
	}
}

void	*ft_malloc(size_t size)
{
	void			*ptr;
	static t_list	*adr = NULL;

	if (size == 0)
	{
		ft_free_list(adr);
		adr = NULL;
		return (NULL);
	}
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size);
	ft_lstadd_front(&adr, ft_lstnew(ptr));
	return (ptr);
}
