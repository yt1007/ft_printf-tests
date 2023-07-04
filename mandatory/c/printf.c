#include <limits.h>
#include <stdio.h>
#include "ft_printf_test.h"

static void	expected_cases(int fd)
{
	int	i;

	i = -1;
	while (++i < 256)
		yt_putnbrline_fd(printf("%%c, i (0 - 255): %c\n", i), fd);
}

static void	exceptional_cases(int fd)
{
	yt_putnbrline_fd(printf("%%c, INT_MIN: %c\n", INT_MIN), fd);
	yt_putnbrline_fd(printf("%%c, -42: %c\n", -42), fd);
	yt_putnbrline_fd(printf("%%c, -17: %c\n", -17), fd);
}

/* Prints a single character using the %c flag, */
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
