#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"
#include "ft_printf_test.h"

static void	expected_cases(int (*f)(const char *, ...), int fd)
{
	int	i;

	i = -128;
	while (++i < 128)
		yt_putnbrline_fd(f("%%i, i (-128 - 127): %i\n", i), fd);
	yt_putnbrline_fd(f("%%i, INT_MIN: %i\n", INT_MIN), fd);
	yt_putnbrline_fd(f("%%i, INT_MAX: %i\n", INT_MAX), fd);
}

static void	exceptional_cases(int (*f)(const char *, ...), int fd)
{
	yt_putnbrline_fd(f("%%i, NULL: %i\n", NULL), fd);
	yt_putnbrline_fd(f("%%i, INT_MIN: %i\n", INT_MIN - 1), fd);
	yt_putnbrline_fd(f("%%i, INT_MAX: %i\n", INT_MAX + 1), fd);
	yt_putnbrline_fd(f("%%i, UINT_MAX: %i\n", UINT_MAX), fd);
	yt_putnbrline_fd(f("%%i, LONG_MIN: %i\n", LONG_MIN), fd);
	yt_putnbrline_fd(f("%%i, LONG_MAX: %i\n", LONG_MAX), fd);
	yt_putnbrline_fd(f("%%i, ULONG_MAX: %i\n", ULONG_MAX), fd);
	yt_putnbrline_fd(f("%%i, LLONG_MIN: %i\n", LLONG_MIN), fd);
	yt_putnbrline_fd(f("%%i, LLONG_MAX: %i\n", LLONG_MAX), fd);
	yt_putnbrline_fd(f("%%i, ULLONG_MAX: %i\n", ULLONG_MAX), fd);
}

/* Prints a decimal number using the %i flag, */
/* followed by a new line. */
int	main(void)
{
	int	fd;

	freopen("printf.out", "w", stdout);
	fd = open("printf.ret", O_WRONLY | O_CREAT);
	if (fd < 0)
		return (1);
	expected_cases(&printf, fd);
	exceptional_cases(&printf, fd);
	close(fd);
	fclose(stdout);
	freopen("/dev/stdout", "w", stdout);
	freopen("ft_printf.out", "w", stdout);
	fd = open("ft_printf.ret", O_WRONLY | O_CREAT);
	if (fd < 0)
		return (1);
	expected_cases(&ft_printf, fd);
	exceptional_cases(&ft_printf, fd);
	close(fd);
	fclose(stdout);
	freopen("/dev/stdout", "w", stdout);
	return (0);
}
