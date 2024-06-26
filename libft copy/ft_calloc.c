/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:12:12 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/26 18:13:02 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	max;

	max = (size_t)-1;
	if (size != 0 && nmemb > (max / size))
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
} */

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	max;
	size_t	i;

	max = (size_t)-1;
	if (size != 0 && nmemb > (max / size))
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	max = nmemb * size;
	i = 0;
	while (i < max)
		ptr[i++] = '\0';
	return (ptr);
}
