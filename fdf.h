
#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct s_coord
{
	int x;
	int y;
	int z;
	struct s_coord *next;
}	t_coord;
#endif
