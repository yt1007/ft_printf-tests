#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"
#include "ft_printf_test.h"

static void	expected_cases(int (*f)(const char *, ...), int fd)
{
	int	i;

	i = -1;
	while (++i < 256)
		yt_putnbrline_fd(f("%%u, i (0 - 255): %u\n", i), fd);
	yt_putnbrline_fd(f("%%u, INT_MAX: %u\n", INT_MAX), fd);
	yt_putnbrline_fd(f("%%u, UINT_MAX: %u\n", UINT_MAX), fd);
}

static void	exceptional_cases(int (*f)(const char *, ...), int fd)
{
	yt_putnbrline_fd(f("%%u, NULL: %u\n", NULL), fd);
	yt_putnbrline_fd(f("%%u, -1: %u\n", -1), fd);
	yt_putnbrline_fd(f("%%u, -17: %u\n", -17), fd);
	yt_putnbrline_fd(f("%%u, -42: %u\n", -42), fd);
	yt_putnbrline_fd(f("%%u, INT_MIN: %u\n", INT_MIN), fd);
	yt_putnbrline_fd(f("%%u, UINT_MAX: %u\n", UINT_MAX + 1), fd);
	yt_putnbrline_fd(f("%%u, LONG_MIN: %u\n", LONG_MIN), fd);
	yt_putnbrline_fd(f("%%u, LONG_MAX: %u\n", LONG_MAX), fd);
	yt_putnbrline_fd(f("%%u, ULONG_MAX: %u\n", ULONG_MAX), fd);
	yt_putnbrline_fd(f("%%u, LLONG_MIN: %u\n", LLONG_MIN), fd);
	yt_putnbrline_fd(f("%%u, LLONG_MAX: %u\n", LLONG_MAX), fd);
	yt_putnbrline_fd(f("%%u, ULLONG_MAX: %u\n", ULLONG_MAX), fd);
}

/* Prints a decimal number using the %u flag, */
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
