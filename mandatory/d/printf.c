#include <limits.h>
#include <stdio.h>

static void	expected_cases(void)
{
	int	i;

	i = -128;
	while (++i < 128)
		printf("%%d, i (-128 - 127): %d\n", i);
	printf("%%d, INT_MIN: %d\n", INT_MIN);
	printf("%%d, INT_MAX: %d\n", INT_MAX);
}

static void	exceptional_cases(void)
{
	printf("%%d, NULL: %d\n", NULL);
	printf("%%d, INT_MIN: %d\n", INT_MIN - 1);
	printf("%%d, INT_MAX: %d\n", INT_MAX + 1);
	printf("%%d, UINT_MAX: %d\n", UINT_MAX);
	printf("%%d, LONG_MIN: %d\n", LONG_MIN);
	printf("%%d, LONG_MAX: %d\n", LONG_MAX);
	printf("%%d, ULONG_MAX: %d\n", ULONG_MAX);
	printf("%%d, LLONG_MIN: %d\n", LLONG_MIN);
	printf("%%d, LLONG_MAX: %d\n", LLONG_MAX);
	printf("%%d, ULLONG_MAX: %d\n", ULLONG_MAX);
}

/* Prints a decimal number using the %d flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
