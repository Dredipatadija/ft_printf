/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:23:29 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/23 19:38:31 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

int	ft_padwidth_bonus(char p, int len)
{
	int		i;
	char	*spacestr;
	int		printed;

	i = 0;
	spacestr = (char *)malloc(sizeof(char) * len + 1);
	if (!spacestr)
		return (-1);
	while (i < len)
		spacestr[i++] = p;
	spacestr[i] = '\0';
	printed = ft_putstr(spacestr);
	free(spacestr);
	return (printed);
}
