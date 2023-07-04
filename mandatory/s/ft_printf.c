#include <limits.h>
#include "ft_printf.h"
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
	i = -1;
	while (++i < 6)
		yt_putnbrline_fd(ft_printf("%%s, s: %s\n", s[i]), fd);
}

static void	exceptional_cases(int fd)
{
	char *s;

	yt_putnbrline_fd(ft_printf("%%s, s (NULL): %s\n", NULL), fd);
	s = "Th!s is @ f^cking l0ng $entence with a p%rc&n+ char in it.";
	yt_putnbrline_fd(ft_printf("%%s, s (Sentence with percent symbol): %s\n", s), fd);
			
}

/* Prints a string of character using the %s flag, */
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
