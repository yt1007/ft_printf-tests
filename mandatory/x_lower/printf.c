#include <limits.h>
#include <stdio.h>
#include "ft_printf_test.h"

static void	expected_cases(int fd)
{
	int	i;

	i = -1;
	while (++i < 256)
		yt_putnbrline_fd(printf("%%x, i (0 - 255): %x\n", i), fd);
	yt_putnbrline_fd(printf("%%x, INT_MAX: %x\n", INT_MAX), fd);
	yt_putnbrline_fd(printf("%%x, UINT_MAX: %x\n", UINT_MAX), fd);
}

static void	exceptional_cases(int fd)
{
	yt_putnbrline_fd(printf("%%x, NULL: %x\n", NULL), fd);
	yt_putnbrline_fd(printf("%%x, -1: %x\n", -1), fd);
	yt_putnbrline_fd(printf("%%x, -17: %x\n", -17), fd);
	yt_putnbrline_fd(printf("%%x, -42: %x\n", -42), fd);
	yt_putnbrline_fd(printf("%%x, INT_MIN: %x\n", INT_MIN), fd);
	yt_putnbrline_fd(printf("%%x, UINT_MAX: %x\n", UINT_MAX + 1), fd);
	yt_putnbrline_fd(printf("%%x, LONG_MIN: %x\n", LONG_MIN), fd);
	yt_putnbrline_fd(printf("%%x, LONG_MAX: %x\n", LONG_MAX), fd);
	yt_putnbrline_fd(printf("%%x, ULONG_MAX: %x\n", ULONG_MAX), fd);
	yt_putnbrline_fd(printf("%%x, LLONG_MIN: %x\n", LLONG_MIN), fd);
	yt_putnbrline_fd(printf("%%x, LLONG_MAX: %x\n", LLONG_MAX), fd);
	yt_putnbrline_fd(printf("%%x, ULLONG_MAX: %x\n", ULLONG_MAX), fd);
}

/* Prints a hexadecimal number using the %x flag, */
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
