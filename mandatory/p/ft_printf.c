#include <limits.h>
#include "ft_printf.h"
#include "ft_printf_test.h"

static void	expected_cases(int fd)
{
	int	i;

	i = -1;
	while (++i < 256)
		yt_putnbrline_fd(ft_printf("%%p, i (0 - 255): %p\n", i), fd);
	yt_putnbrline_fd(ft_printf("%%p, INT_MAX: %p\n", INT_MAX), fd);
	yt_putnbrline_fd(ft_printf("%%p, UINT_MAX: %p\n", UINT_MAX), fd);
}

static void	exceptional_cases(int fd)
{
	yt_putnbrline_fd(ft_printf("%%p, NULL: %p\n", NULL), fd);
	yt_putnbrline_fd(ft_printf("%%p, -1: %p\n", -1), fd);
	yt_putnbrline_fd(ft_printf("%%p, -17: %p\n", -17), fd);
	yt_putnbrline_fd(ft_printf("%%p, -42: %p\n", -42), fd);
	yt_putnbrline_fd(ft_printf("%%p, INT_MIN: %p\n", INT_MIN), fd);
	yt_putnbrline_fd(ft_printf("%%p, UINT_MAX: %p\n", UINT_MAX + 1), fd);
	yt_putnbrline_fd(ft_printf("%%p, LONG_MIN: %p\n", LONG_MIN), fd);
	yt_putnbrline_fd(ft_printf("%%p, LONG_MAX: %p\n", LONG_MAX), fd);
	yt_putnbrline_fd(ft_printf("%%p, ULONG_MAX: %p\n", ULONG_MAX), fd);
	yt_putnbrline_fd(ft_printf("%%p, LLONG_MIN: %p\n", LLONG_MIN), fd);
	yt_putnbrline_fd(ft_printf("%%p, LLONG_MAX: %p\n", LLONG_MAX), fd);
	yt_putnbrline_fd(ft_printf("%%p, ULLONG_MAX: %p\n", ULLONG_MAX), fd);
}

/* Prints a hexadecimal number using the %p flag, */
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
