#include <limits.h>
#include <stdio.h>

static void	expected_cases(void)
{
	int	i;

	i = -1;
	while (++i < 256)
		printf("%%X, i (0 - 255): %X\n", i);
	printf("%%X, INT_MAX: %X\n", INT_MAX);
	printf("%%X, UINT_MAX: %X\n", UINT_MAX);
}

static void	exceptional_cases(void)
{
	printf("%%X, NULL: %X\n", NULL);
	printf("%%X, -1: %X\n", -1);
	printf("%%X, -17: %X\n", -17);
	printf("%%X, -42: %X\n", -42);
	printf("%%X, INT_MIN: %X\n", INT_MIN);
	printf("%%X, UINT_MAX: %X\n", UINT_MAX + 1);
	printf("%%X, LONG_MIN: %X\n", LONG_MIN);
	printf("%%X, LONG_MAX: %X\n", LONG_MAX);
	printf("%%X, ULONG_MAX: %X\n", ULONG_MAX);
	printf("%%X, LLONG_MIN: %X\n", LLONG_MIN);
	printf("%%X, LLONG_MAX: %X\n", LLONG_MAX);
	printf("%%X, ULLONG_MAX: %X\n", ULLONG_MAX);
}

/* Prints a hexadecimal number using the %X flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
