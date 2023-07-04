#include <limits.h>
#include "ft_printf.h"

static void	expected_cases(void)
{
	int	i;

	i = -1;
	while (++i < 256)
		ft_printf("%%u, i (0 - 255): %u\n", i);
	ft_printf("%%u, INT_MAX: %u\n", INT_MAX);
	ft_printf("%%u, UINT_MAX: %u\n", UINT_MAX);
}

static void	exceptional_cases(void)
{
	ft_printf("%%u, NULL: %u\n", NULL);
	ft_printf("%%u, -1: %u\n", -1);
	ft_printf("%%u, -17: %u\n", -17);
	ft_printf("%%u, -42: %u\n", -42);
	ft_printf("%%u, INT_MIN: %u\n", INT_MIN);
	ft_printf("%%u, UINT_MAX: %u\n", UINT_MAX + 1);
	ft_printf("%%u, LONG_MIN: %u\n", LONG_MIN);
	ft_printf("%%u, LONG_MAX: %u\n", LONG_MAX);
	ft_printf("%%u, ULONG_MAX: %u\n", ULONG_MAX);
	ft_printf("%%u, LLONG_MIN: %u\n", LLONG_MIN);
	ft_printf("%%u, LLONG_MAX: %u\n", LLONG_MAX);
	ft_printf("%%u, ULLONG_MAX: %u\n", ULLONG_MAX);
}

/* Prints a decimal number using the %u flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
