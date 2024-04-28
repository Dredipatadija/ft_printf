/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:09:54 by arenilla          #+#    #+#             */
/*   Updated: 2024/04/28 19:25:41 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_format
{
	size_t	width;
	size_t	precision;
	int		point;
	int		zerofilled;
	int		leftaligned;
	int		hash;
	int		plus;
	int		space;
}				t_format;

int			ft_check_bonus(const char *format, t_format *fmt, va_list args);
int			ft_errorstr(char *str);
int			ft_print_char_bonus(char c, t_format *fmt);
int			ft_print_hex_bonus(unsigned long n, char ch, t_format *fmt);
int			ft_print_nbr_bonus(int n, t_format *fmt);
int			ft_print_ptr_bonus(void *ptr, t_format *fmt);
int			ft_print_str_bonus(char *str, t_format *fmt);
int			ft_print_unbr_bonus(unsigned int n, t_format *fmt);
int			ft_printf_bonus(const char *format, ...);
int			ft_padwidth_bonus(char p, int len);
const char	*ft_precision(t_format *fmt, const char *format);
char		*ft_padprecis_bonus(char p, int len);
int			ft_widthmajor_h(t_format *fmt, long long pstr, char *s);
int			ft_widthmajor_n(t_format *fmt, long long pstr, char *s);
void		ft_pointernegate(t_format *fmt);
char		*ft_conditionprecis(t_format *fmt, char *str);
char		*ft_pluspa(char *str, t_format *fmt,
				char *strprecis, char *padprecis);
char		*ft_unbrconditions(size_t l, char *str,
				unsigned int n, t_format *fmt);
int			ft_unbrlefta(t_format *fmt, int printedstr, char *str, int pflag);
int			ft_suprawidth(t_format *fmt, char *str);
char		*ft_fillstr(unsigned int n, size_t len, char *str);
char		*ft_uitoa(size_t len, unsigned int n, t_format *fmt);
char		*ft_positnum(char *str, t_format *fmt);

#endif
