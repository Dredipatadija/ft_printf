/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padprecis_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:48:11 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/27 15:07:59 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

char	*ft_padprecis_bonus(char p, int len)
{
	int		i;
	char	*spacestr;

	i = 0;
	spacestr = (char *)malloc(sizeof(char) * len + 1);
	if (!spacestr)
		return (NULL);
	while (i < len)
		spacestr[i++] = p;
	spacestr[i] = '\0';
	return (spacestr);
}
