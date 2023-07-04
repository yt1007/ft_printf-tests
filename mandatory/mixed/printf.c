#include <stdio.h>
#include "ft_printf_test.h"

static void	expected_cases(int fd)
{
	int	i;
	char *s[6];

	s[0] = "";
	s[1] = "\n";
	s[2] = "A cat";
	s[3] = "A cat is not a dog.";
	s[4] = "The quick brown fox jumps over the lazy dog.";
	s[5] = "The quick brown fox jumps over the lazy dog.\n";
	yt_putnbrline_fd(printf("%%s%%c, s (sentence w/o nl), c (new line char): %s%c", s[4], '\n'), fd);
	yt_putnbrline_fd(printf("%%s (%%p)\\n, s (sentence), s (sentence): %s (%p)\n", s[4], s[4]), fd);
	yt_putnbrline_fd(printf("%%d%%%% %%s (%%p)\\n, 100, \"pass\", s[0]: %d%% %s (%p)\n", 100, "pass", s[0]), fd);
}

/* Prints a string of characters from a mixed set of values using a mix of */
/* the %c, %d, %i, %p, %s, %u, %x, %X, and %% flags, followed by a new line. */
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
