#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_format
{
	size_t	width;
	int		zerofilled;
	int		leftaligned;
	int		hash;
	int		plus;
	int		space;
	int		bytesprinted;
}				t_format;

#endif

