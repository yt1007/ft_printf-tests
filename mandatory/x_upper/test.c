#include <limits.h>
#include "ft_printf_test.h"

 void	run_tests(int (*f)(const char *, ...), int fd)
{
	int	i;

	i = -1;
	while (++i < 256)
		yt_putnbrline_fd(f("%%X, i (0 - 255): %X\n", i), fd);
	yt_putnbrline_fd(f("%%X, INT_MAX: %X\n", INT_MAX), fd);
	yt_putnbrline_fd(f("%%X, UINT_MAX: %X\n", UINT_MAX), fd);
	yt_putnbrline_fd(f("%%X, NULL: %X\n", NULL), fd);
	yt_putnbrline_fd(f("%%X, -1: %X\n", -1), fd);
	yt_putnbrline_fd(f("%%X, -17: %X\n", -17), fd);
	yt_putnbrline_fd(f("%%X, -42: %X\n", -42), fd);
	yt_putnbrline_fd(f("%%X, INT_MIN: %X\n", INT_MIN), fd);
	yt_putnbrline_fd(f("%%X, UINT_MAX + 1: %X\n", UINT_MAX + 1), fd);
	yt_putnbrline_fd(f("%%X, LONG_MIN: %X\n", LONG_MIN), fd);
	yt_putnbrline_fd(f("%%X, LONG_MAX: %X\n", LONG_MAX), fd);
	yt_putnbrline_fd(f("%%X, ULONG_MAX: %X\n", ULONG_MAX), fd);
	yt_putnbrline_fd(f("%%X, LLONG_MIN: %X\n", LLONG_MIN), fd);
	yt_putnbrline_fd(f("%%X, LLONG_MAX: %X\n", LLONG_MAX), fd);
	yt_putnbrline_fd(f("%%X, ULLONG_MAX: %X\n", ULLONG_MAX), fd);
}
