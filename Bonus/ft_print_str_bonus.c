/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:59:20 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/23 19:31:13 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

static int	ft_leftalig_str(t_format *fmt, char *str, char *space)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (fmt->leftaligned != 0)
	{
		i = ft_putstr(str);
		j = ft_putstr(space);
	}
	else if (fmt->leftaligned == 0)
	{
		j = ft_putstr(space);
		i = ft_putstr(str);
	}
	if (i == -1 || j == -1)
		return (-1);
	return (i + j);
}

int	ft_print_str_bonus(char *str, t_format *fmt)
{
	char	*spacestr;
	int		i;
	int		len;
	int		printed;

	i = 0;
	printed = 0;
	spacestr = NULL;
	if (str == NULL)
		return (ft_putstr("(null)"));
	if (fmt->width > ft_strlen(str))
	{
		len = fmt->width - ft_strlen(str);
		spacestr = malloc(sizeof(char) * len + 1);
		if (!spacestr)
			return (-1);
		while (i < len)
			spacestr[i++] = ' ';
		spacestr[i] = '\0';
		printed = ft_leftalig_str(fmt, str, spacestr);
		free(spacestr);
	}
	else if (fmt->width <= ft_strlen(str))
		return (ft_putstr(str));
	return (printed);
}
