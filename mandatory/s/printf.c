#include <stdio.h>

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
	i = -1;
	while (++i < 6)
		printf("%%s, s: %s\n", s[i]);
}

static void	exceptional_cases(void)
{
	char *s;

	printf("%%s, s (NULL): %s\n", NULL);
	s = "Th!s is @ f^cking l0ng $entence with a p%rc&n+ char in it.";
	printf("%%s, s (Sentence with percent symbol): %s\n", s);
			
}

/* Prints a string of character using the %s flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
