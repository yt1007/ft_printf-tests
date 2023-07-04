#include <limits.h>
#include <stdio.h>

static void	expected_cases(void)
{
	int	i;

	i = -1;
	while (++i < 256)
		printf("%%p, i (0 - 255): %p\n", i);
	printf("%%p, INT_MAX: %p\n", INT_MAX);
	printf("%%p, UINT_MAX: %p\n", UINT_MAX);
}

static void	exceptional_cases(void)
{
	printf("%%p, NULL: %p\n", NULL);
	printf("%%p, -1: %p\n", -1);
	printf("%%p, -17: %p\n", -17);
	printf("%%p, -42: %p\n", -42);
	printf("%%p, INT_MIN: %p\n", INT_MIN);
	printf("%%p, UINT_MAX: %p\n", UINT_MAX + 1);
	printf("%%p, LONG_MIN: %p\n", LONG_MIN);
	printf("%%p, LONG_MAX: %p\n", LONG_MAX);
	printf("%%p, ULONG_MAX: %p\n", ULONG_MAX);
	printf("%%p, LLONG_MIN: %p\n", LLONG_MIN);
	printf("%%p, LLONG_MAX: %p\n", LLONG_MAX);
	printf("%%p, ULLONG_MAX: %p\n", ULLONG_MAX);
}

/* Prints a hexadecimal number using the %p flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
