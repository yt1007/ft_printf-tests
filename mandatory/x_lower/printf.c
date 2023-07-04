#include <limits.h>
#include <stdio.h>

static void	expected_cases(void)
{
	int	i;

	i = -1;
	while (++i < 256)
		printf("%%x, i (0 - 255): %x\n", i);
	printf("%%x, INT_MAX: %x\n", INT_MAX);
	printf("%%x, UINT_MAX: %x\n", UINT_MAX);
}

static void	exceptional_cases(void)
{
	printf("%%x, NULL: %x\n", NULL);
	printf("%%x, -1: %x\n", -1);
	printf("%%x, -17: %x\n", -17);
	printf("%%x, -42: %x\n", -42);
	printf("%%x, INT_MIN: %x\n", INT_MIN);
	printf("%%x, UINT_MAX: %x\n", UINT_MAX + 1);
	printf("%%x, LONG_MIN: %x\n", LONG_MIN);
	printf("%%x, LONG_MAX: %x\n", LONG_MAX);
	printf("%%x, ULONG_MAX: %x\n", ULONG_MAX);
	printf("%%x, LLONG_MIN: %x\n", LLONG_MIN);
	printf("%%x, LLONG_MAX: %x\n", LLONG_MAX);
	printf("%%x, ULLONG_MAX: %x\n", ULLONG_MAX);
}

/* Prints a hexadecimal number using the %x flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
