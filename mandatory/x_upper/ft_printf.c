#include <limits.h>
#include "ft_printf.h"

static void	expected_cases(void)
{
	int	i;

	i = -1;
	while (++i < 256)
		ft_printf("%%X, i (0 - 255): %X\n", i);
	ft_printf("%%X, INT_MAX: %X\n", INT_MAX);
	ft_printf("%%X, UINT_MAX: %X\n", UINT_MAX);
}

static void	exceptional_cases(void)
{
	ft_printf("%%X, NULL: %X\n", NULL);
	ft_printf("%%X, -1: %X\n", -1);
	ft_printf("%%X, -17: %X\n", -17);
	ft_printf("%%X, -42: %X\n", -42);
	ft_printf("%%X, INT_MIN: %X\n", INT_MIN);
	ft_printf("%%X, UINT_MAX: %X\n", UINT_MAX + 1);
	ft_printf("%%X, LONG_MIN: %X\n", LONG_MIN);
	ft_printf("%%X, LONG_MAX: %X\n", LONG_MAX);
	ft_printf("%%X, ULONG_MAX: %X\n", ULONG_MAX);
	ft_printf("%%X, LLONG_MIN: %X\n", LLONG_MIN);
	ft_printf("%%X, LLONG_MAX: %X\n", LLONG_MAX);
	ft_printf("%%X, ULLONG_MAX: %X\n", ULLONG_MAX);
}

/* Prints a hexadecimal number using the %X flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
