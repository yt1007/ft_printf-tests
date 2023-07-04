#include <limits.h>
#include <stdio.h>

static void	expected_cases(void)
{
	int	i;

	i = -1;
	while (++i < 256)
		printf("%%u, i (0 - 255): %u\n", i);
	printf("%%u, INT_MAX: %u\n", INT_MAX);
	printf("%%u, UINT_MAX: %u\n", UINT_MAX);
}

static void	exceptional_cases(void)
{
	printf("%%u, NULL: %u\n", NULL);
	printf("%%u, -1: %u\n", -1);
	printf("%%u, -17: %u\n", -17);
	printf("%%u, -42: %u\n", -42);
	printf("%%u, INT_MIN: %u\n", INT_MIN);
	printf("%%u, UINT_MAX: %u\n", UINT_MAX + 1);
	printf("%%u, LONG_MIN: %u\n", LONG_MIN);
	printf("%%u, LONG_MAX: %u\n", LONG_MAX);
	printf("%%u, ULONG_MAX: %u\n", ULONG_MAX);
	printf("%%u, LLONG_MIN: %u\n", LLONG_MIN);
	printf("%%u, LLONG_MAX: %u\n", LLONG_MAX);
	printf("%%u, ULLONG_MAX: %u\n", ULLONG_MAX);
}

/* Prints a decimal number using the %u flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
