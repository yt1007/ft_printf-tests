#include <limits.h>
#include <stdio.h>
#include "ft_printf_test.h"

static void	expected_cases(int fd)
{
	int	i;

	i = -1;
	while (++i < 256)
		yt_putnbrline_fd(printf("%%X, i (0 - 255): %X\n", i), fd);
	yt_putnbrline_fd(printf("%%X, INT_MAX: %X\n", INT_MAX), fd);
	yt_putnbrline_fd(printf("%%X, UINT_MAX: %X\n", UINT_MAX), fd);
}

static void	exceptional_cases(int fd)
{
	yt_putnbrline_fd(printf("%%X, NULL: %X\n", NULL), fd);
	yt_putnbrline_fd(printf("%%X, -1: %X\n", -1), fd);
	yt_putnbrline_fd(printf("%%X, -17: %X\n", -17), fd);
	yt_putnbrline_fd(printf("%%X, -42: %X\n", -42), fd);
	yt_putnbrline_fd(printf("%%X, INT_MIN: %X\n", INT_MIN), fd);
	yt_putnbrline_fd(printf("%%X, UINT_MAX: %X\n", UINT_MAX + 1), fd);
	yt_putnbrline_fd(printf("%%X, LONG_MIN: %X\n", LONG_MIN), fd);
	yt_putnbrline_fd(printf("%%X, LONG_MAX: %X\n", LONG_MAX), fd);
	yt_putnbrline_fd(printf("%%X, ULONG_MAX: %X\n", ULONG_MAX), fd);
	yt_putnbrline_fd(printf("%%X, LLONG_MIN: %X\n", LLONG_MIN), fd);
	yt_putnbrline_fd(printf("%%X, LLONG_MAX: %X\n", LLONG_MAX), fd);
	yt_putnbrline_fd(printf("%%X, ULLONG_MAX: %X\n", ULLONG_MAX), fd);
}

/* Prints a hexadecimal number using the %X flag, */
/* followed by a new line. */
int	main(void)
{
	int	fd;

	fd = open("printf.ret", O_WRONLY | O_CREAT);
	if (fd < 0)
		return (1);
	expected_cases(fd);
	exceptional_cases(fd);
	close(fd);
	return (0);
}
