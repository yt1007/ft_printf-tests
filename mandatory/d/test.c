#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"
#include "ft_printf_test.h"

static void	expected_cases(int (*f)(const char *, ...), int fd)
{
	int	i;

	i = -128;
	while (++i < 128)
		yt_putnbrline_fd(f("%%d, i (-128 - 127): %d\n", i), fd);
	yt_putnbrline_fd(f("%%d, INT_MIN: %d\n", INT_MIN), fd);
	yt_putnbrline_fd(f("%%d, INT_MAX: %d\n", INT_MAX), fd);
}

static void	exceptional_cases(int (*f)(const char *, ...), int fd)
{
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

/* Prints a decimal number using the %d flag, */
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
