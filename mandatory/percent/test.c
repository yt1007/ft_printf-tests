#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"
#include "ft_printf_test.h"

static void	expected_cases(int (*f)(const char *, ...), int fd)
{
	yt_putnbrline_fd(f("%%%%: %%\n"), fd);
	yt_putnbrline_fd(f("%%%% %%%%: %% %%\n"), fd);
	yt_putnbrline_fd(f("%%%%d%%%%: %%d%%\n"), fd);
}

static void	exceptional_cases(int (*f)(const char *, ...), int fd)
{
	yt_putnbrline_fd(f("%%: %\n"), fd);
	yt_putnbrline_fd(f("%% %%%%: % %%\n"), fd);
	yt_putnbrline_fd(f("%%%% %%%%%%: %% %%%\n"), fd);
	yt_putnbrline_fd(f("%%y: %y\n"), fd);
}

/* Prints a percent character using the %% flag, */
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