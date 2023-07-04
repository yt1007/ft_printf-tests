#include <limits.h>
#include <stdio.h>

static void	expected_cases(void)
{
	int	i;

	i = -128;
	while (++i < 128)
		printf("%%i, i (-128 - 127): %i\n", i);
	printf("%%i, INT_MIN: %i\n", INT_MIN);
	printf("%%i, INT_MAX: %i\n", INT_MAX);
}

static void	exceptional_cases(void)
{
	printf("%%i, NULL: %i\n", NULL);
	printf("%%i, INT_MIN: %i\n", INT_MIN - 1);
	printf("%%i, INT_MAX: %i\n", INT_MAX + 1);
	printf("%%i, UINT_MAX: %i\n", UINT_MAX);
	printf("%%i, LONG_MIN: %i\n", LONG_MIN);
	printf("%%i, LONG_MAX: %i\n", LONG_MAX);
	printf("%%i, ULONG_MAX: %i\n", ULONG_MAX);
	printf("%%i, LLONG_MIN: %i\n", LLONG_MIN);
	printf("%%i, LLONG_MAX: %i\n", LLONG_MAX);
	printf("%%i, ULLONG_MAX: %i\n", ULLONG_MAX);
}

/* Prints a decimal number using the %i flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
