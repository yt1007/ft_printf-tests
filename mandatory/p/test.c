#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"
#include "ft_printf_test.h"

 void	run_tests(int (*f)(const char *, ...), int fd)
{
	int	i;

	i = -1;
	while (++i < 256)
		yt_putnbrline_fd(f("%%p, i (0 - 255): %p\n", i), fd);
	yt_putnbrline_fd(f("%%p, INT_MAX: %p\n", INT_MAX), fd);
	yt_putnbrline_fd(f("%%p, UINT_MAX: %p\n", UINT_MAX), fd);
	yt_putnbrline_fd(f("%%p, NULL: %p\n", NULL), fd);
	yt_putnbrline_fd(f("%%p, -1: %p\n", -1), fd);
	yt_putnbrline_fd(f("%%p, -17: %p\n", -17), fd);
	yt_putnbrline_fd(f("%%p, -42: %p\n", -42), fd);
	yt_putnbrline_fd(f("%%p, INT_MIN: %p\n", INT_MIN), fd);
	yt_putnbrline_fd(f("%%p, UINT_MAX: %p\n", UINT_MAX + 1), fd);
	yt_putnbrline_fd(f("%%p, LONG_MIN: %p\n", LONG_MIN), fd);
	yt_putnbrline_fd(f("%%p, LONG_MAX: %p\n", LONG_MAX), fd);
	yt_putnbrline_fd(f("%%p, ULONG_MAX: %p\n", ULONG_MAX), fd);
	yt_putnbrline_fd(f("%%p, LLONG_MIN: %p\n", LLONG_MIN), fd);
	yt_putnbrline_fd(f("%%p, LLONG_MAX: %p\n", LLONG_MAX), fd);
	yt_putnbrline_fd(f("%%p, ULLONG_MAX: %p\n", ULLONG_MAX), fd);
}
