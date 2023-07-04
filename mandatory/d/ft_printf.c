#include <limits.h>
#include "ft_printf.h"
#include "ft_printf_test.h"

static void	expected_cases(int fd)
{
	int	i;

	i = -128;
	while (++i < 128)
		yt_putnbrline_fd(ft_printf("%%d, i (-128 - 127): %d\n", i), fd);
	yt_putnbrline_fd(ft_printf("%%d, INT_MIN: %d\n", INT_MIN), fd);
	yt_putnbrline_fd(ft_printf("%%d, INT_MAX: %d\n", INT_MAX), fd);
}

static void	exceptional_cases(int fd)
{
	yt_putnbrline_fd(ft_printf("%%d, NULL: %d\n", NULL), fd);
	yt_putnbrline_fd(ft_printf("%%d, INT_MIN: %d\n", INT_MIN - 1), fd);
	yt_putnbrline_fd(ft_printf("%%d, INT_MAX: %d\n", INT_MAX + 1), fd);
	yt_putnbrline_fd(ft_printf("%%d, UINT_MAX: %d\n", UINT_MAX), fd);
	yt_putnbrline_fd(ft_printf("%%d, LONG_MIN: %d\n", LONG_MIN), fd);
	yt_putnbrline_fd(ft_printf("%%d, LONG_MAX: %d\n", LONG_MAX), fd);
	yt_putnbrline_fd(ft_printf("%%d, ULONG_MAX: %d\n", ULONG_MAX), fd);
	yt_putnbrline_fd(ft_printf("%%d, LLONG_MIN: %d\n", LLONG_MIN), fd);
	yt_putnbrline_fd(ft_printf("%%d, LLONG_MAX: %d\n", LLONG_MAX), fd);
	yt_putnbrline_fd(ft_printf("%%d, ULLONG_MAX: %d\n", ULLONG_MAX), fd);
}

/* Prints a decimal number using the %d flag, */
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
