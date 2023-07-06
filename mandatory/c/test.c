#include <limits.h>
#include "ft_printf_test.h"

 void	run_tests(int (*f)(const char *, ...), int fd)
{
	int	i;

	i = -1;
	while (++i < 256)
		yt_putnbrline_fd(f("%%c, i (0 - 255): %c\n", i), fd);
	yt_putnbrline_fd(f("%%c, INT_MIN: %c\n", INT_MIN), fd);
	yt_putnbrline_fd(f("%%c, -42: %c\n", -42), fd);
	yt_putnbrline_fd(f("%%c, -17: %c\n", -17), fd);
}
