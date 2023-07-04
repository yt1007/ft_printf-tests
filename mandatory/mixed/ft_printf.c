#include <limits.h>
#include "ft_printf.h"

static void	expected_cases(void)
{
	int	i;
	char *s[6];

	s[0] = "";
	s[1] = "\n";
	s[2] = "A cat";
	s[3] = "A cat is not a dog.";
	s[4] = "The quick brown fox jumps over the lazy dog.";
	s[5] = "The quick brown fox jumps over the lazy dog.\n";
	ft_printf("%%s%%c, s (sentence w/o nl), c (new line char): %s%c", s[4], '\n');
	ft_printf("%%s (%%p)\\n, s (sentence), s (sentence): %s (%p)\n", s[4], s[4]);
	ft_printf("%%d%%%% %%s (%%p)\\n, 100, \"pass\", s[0]: %d%% %s (%p)\n", 100, "pass", s[0]);
}

/* Prints a string of characters from a mixed set of values using a mix of */
/* the %c, %d, %i, %p, %s, %u, %x, %X, and %% flags, followed by a new line. */
int	main(void)
{
	expected_cases();
	return (0);
}
