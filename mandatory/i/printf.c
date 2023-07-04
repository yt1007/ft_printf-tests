#include <limits.h>
#include <stdio.h>
#include "ft_printf_test.h"

static void	expected_cases(int fd)
{
	int	i;

	i = -128;
	while (++i < 128)
		yt_putnbrline_fd(printf("%%i, i (-128 - 127): %i\n", i), fd);
	yt_putnbrline_fd(printf("%%i, INT_MIN: %i\n", INT_MIN), fd);
	yt_putnbrline_fd(printf("%%i, INT_MAX: %i\n", INT_MAX), fd);
}

static void	exceptional_cases(int fd)
{
	yt_putnbrline_fd(printf("%%i, NULL: %i\n", NULL), fd);
	yt_putnbrline_fd(printf("%%i, INT_MIN: %i\n", INT_MIN - 1), fd);
	yt_putnbrline_fd(printf("%%i, INT_MAX: %i\n", INT_MAX + 1), fd);
	yt_putnbrline_fd(printf("%%i, UINT_MAX: %i\n", UINT_MAX), fd);
	yt_putnbrline_fd(printf("%%i, LONG_MIN: %i\n", LONG_MIN), fd);
	yt_putnbrline_fd(printf("%%i, LONG_MAX: %i\n", LONG_MAX), fd);
	yt_putnbrline_fd(printf("%%i, ULONG_MAX: %i\n", ULONG_MAX), fd);
	yt_putnbrline_fd(printf("%%i, LLONG_MIN: %i\n", LLONG_MIN), fd);
	yt_putnbrline_fd(printf("%%i, LLONG_MAX: %i\n", LLONG_MAX), fd);
	yt_putnbrline_fd(printf("%%i, ULLONG_MAX: %i\n", ULLONG_MAX), fd);
}

/* Prints a decimal number using the %i flag, */
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
