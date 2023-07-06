#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"
#include "ft_printf_test.h"

 void	run_tests(int (*f)(const char *, ...), int fd)
{
	yt_putnbrline_fd(f("%%%%: %%\n"), fd);
	yt_putnbrline_fd(f("%%%% %%%%: %% %%\n"), fd);
	yt_putnbrline_fd(f("%%%%d%%%%: %%d%%\n"), fd);
	yt_putnbrline_fd(f("%%: %\n"), fd);
	yt_putnbrline_fd(f("%% %%%%: % %%\n"), fd);
	yt_putnbrline_fd(f("%%%% %%%%%%: %% %%%\n"), fd);
	yt_putnbrline_fd(f("%%y: %y\n"), fd);
}
