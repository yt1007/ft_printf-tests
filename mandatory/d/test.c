#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"
#include "ft_printf_test.h"

 void	run_tests(int (*f)(const char *, ...), int fd)
{
	int	i;

	i = -128;
	while (++i < 128)
		yt_putnbrline_fd(f("%%d, i (-128 - 127): %d\n", i), fd);
	yt_putnbrline_fd(f("%%d, INT_MIN: %d\n", INT_MIN), fd);
	yt_putnbrline_fd(f("%%d, INT_MAX: %d\n", INT_MAX), fd);
	yt_putnbrline_fd(f("%%d, NULL: %d\n", NULL), fd);
	yt_putnbrline_fd(f("%%d, INT_MIN: %d\n", INT_MIN - 1), fd);
	yt_putnbrline_fd(f("%%d, INT_MAX: %d\n", INT_MAX + 1), fd);
	yt_putnbrline_fd(f("%%d, UINT_MAX: %d\n", UINT_MAX), fd);
	yt_putnbrline_fd(f("%%d, LONG_MIN: %d\n", LONG_MIN), fd);
	yt_putnbrline_fd(f("%%d, LONG_MAX: %d\n", LONG_MAX), fd);
	yt_putnbrline_fd(f("%%d, ULONG_MAX: %d\n", ULONG_MAX), fd);
	yt_putnbrline_fd(f("%%d, LLONG_MIN: %d\n", LLONG_MIN), fd);
	yt_putnbrline_fd(f("%%d, LLONG_MAX: %d\n", LLONG_MAX), fd);
	yt_putnbrline_fd(f("%%d, ULLONG_MAX: %d\n", ULLONG_MAX), fd);
}
