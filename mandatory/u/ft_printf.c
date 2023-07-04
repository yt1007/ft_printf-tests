#include <limits.h>
#include "ft_printf.h"
#include "ft_printf_test.h"

static void	expected_cases(int fd)
{
	int	i;

	i = -1;
	while (++i < 256)
		yt_putnbrline_fd(ft_printf("%%u, i (0 - 255): %u\n", i), fd);
	yt_putnbrline_fd(ft_printf("%%u, INT_MAX: %u\n", INT_MAX), fd);
	yt_putnbrline_fd(ft_printf("%%u, UINT_MAX: %u\n", UINT_MAX), fd);
}

static void	exceptional_cases(int fd)
{
	yt_putnbrline_fd(ft_printf("%%u, NULL: %u\n", NULL), fd);
	yt_putnbrline_fd(ft_printf("%%u, -1: %u\n", -1), fd);
	yt_putnbrline_fd(ft_printf("%%u, -17: %u\n", -17), fd);
	yt_putnbrline_fd(ft_printf("%%u, -42: %u\n", -42), fd);
	yt_putnbrline_fd(ft_printf("%%u, INT_MIN: %u\n", INT_MIN), fd);
	yt_putnbrline_fd(ft_printf("%%u, UINT_MAX: %u\n", UINT_MAX + 1), fd);
	yt_putnbrline_fd(ft_printf("%%u, LONG_MIN: %u\n", LONG_MIN), fd);
	yt_putnbrline_fd(ft_printf("%%u, LONG_MAX: %u\n", LONG_MAX), fd);
	yt_putnbrline_fd(ft_printf("%%u, ULONG_MAX: %u\n", ULONG_MAX), fd);
	yt_putnbrline_fd(ft_printf("%%u, LLONG_MIN: %u\n", LLONG_MIN), fd);
	yt_putnbrline_fd(ft_printf("%%u, LLONG_MAX: %u\n", LLONG_MAX), fd);
	yt_putnbrline_fd(ft_printf("%%u, ULLONG_MAX: %u\n", ULLONG_MAX), fd);
}

/* Prints a decimal number using the %u flag, */
/* followed by a new line. */
int	main(void)
{
	int	fd;

	fd = open("ft_printf.ret", O_WRONLY | O_CREAT);
	if (fd < 0)
		return (1);
	expected_cases(fd);
	exceptional_cases(fd);
	close(fd);
	return (0);
}
