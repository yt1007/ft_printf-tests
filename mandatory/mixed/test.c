#include <stdio.h>
#include "ft_printf.h"
#include "ft_printf_test.h"

 void	run_tests(int (*f)(const char *, ...), int fd)
{
	int	i;
	char *s[6];

	s[0] = "";
	s[1] = "\n";
	s[2] = "A cat";
	s[3] = "A cat is not a dog.";
	s[4] = "The quick brown fox jumps over the lazy dog.";
	s[5] = "The quick brown fox jumps over the lazy dog.\n";
	yt_putnbrline_fd(f("%%s%%c, s (sentence w/o nl), c (new line char): %s%c", s[4], '\n'), fd);
	yt_putnbrline_fd(f("%%s (%%p)\\n, s (sentence), s (sentence): %s (%p)\n", s[4], s[4]), fd);
	yt_putnbrline_fd(f("%%d%%%% %%s (%%p)\\n, 100, \"pass\", s[0]: %d%% %s (%p)\n", 100, "pass", s[0]), fd);
}
