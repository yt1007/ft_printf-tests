#include <limits.h>
#include <stdio.h>

static void	expected_cases(void)
{
	int	i;

	i = -1;
	while (++i < 256)
		printf("%%c, i (0 - 255): %c\n", i);
}

static void	exceptional_cases(void)
{
	printf("%%c, INT_MIN: %c\n", INT_MIN);
	printf("%%c, -42: %c\n", -42);
	printf("%%c, -17: %c\n", -17);
}

/* Prints a single character using the %c flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
