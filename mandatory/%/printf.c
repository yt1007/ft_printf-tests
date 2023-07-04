#include <limits.h>
#include <stdio.h>
#include "ft_printf_test.h"

static void	expected_cases(int fd)
{
	yt_putnbrline_fd(printf("%%%%: %%\n"), fd);
	yt_putnbrline_fd(printf("%%%% %%%%: %% %%\n"), fd);
	yt_putnbrline_fd(printf("%%%%d%%%%: %%d%%\n"), fd);
}

static void	exceptional_cases(int fd)
{
	yt_putnbrline_fd(printf("%%: %\n"), fd);
	yt_putnbrline_fd(printf("%% %%%%: % %%\n"), fd);
	yt_putnbrline_fd(printf("%%%% %%%%%%: %% %%%\n"), fd);
}

/* Prints a percent character using the %% flag, */
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
