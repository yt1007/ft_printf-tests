#include "ft_printf_test.h"

 void	run_tests(int (*f)(const char *, ...), int fd)
{
	int	i;
	char *s[7];

	s[0] = "";
	s[1] = "\n";
	s[2] = "A cat";
	s[3] = "A cat is not a dog.";
	s[4] = "The quick brown fox jumps over the lazy dog.";
	s[5] = "The quick brown fox jumps over the lazy dog.\n";
	s[6] = "Th!s is @ f^cking l0ng $entence with a p%rc&n+ char in it.";
	i = -1;
	while (++i < 6)
		yt_putnbrline_fd(f("%%s, s: %s\n", s[i]), fd);
	yt_putnbrline_fd(f("%%s, s (NULL): %s\n", NULL), fd);
	yt_putnbrline_fd(f("%%s, s (Sentence with percent symbol): %s\n", s[6]), fd);
			
}
