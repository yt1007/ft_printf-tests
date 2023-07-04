#include <limits.h>
#include "ft_printf.h"

static void	expected_cases(void)
{
	int	i;

	i = -128;
	while (++i < 128)
		ft_printf("%%i, i (-128 - 127): %i\n", i);
	ft_printf("%%i, INT_MIN: %i\n", INT_MIN);
	ft_printf("%%i, INT_MAX: %i\n", INT_MAX);
}

static void	exceptional_cases(void)
{
	ft_printf("%%i, NULL: %i\n", NULL);
	ft_printf("%%i, INT_MIN: %i\n", INT_MIN - 1);
	ft_printf("%%i, INT_MAX: %i\n", INT_MAX + 1);
	ft_printf("%%i, UINT_MAX: %i\n", UINT_MAX);
	ft_printf("%%i, LONG_MIN: %i\n", LONG_MIN);
	ft_printf("%%i, LONG_MAX: %i\n", LONG_MAX);
	ft_printf("%%i, ULONG_MAX: %i\n", ULONG_MAX);
	ft_printf("%%i, LLONG_MIN: %i\n", LLONG_MIN);
	ft_printf("%%i, LLONG_MAX: %i\n", LLONG_MAX);
	ft_printf("%%i, ULLONG_MAX: %i\n", ULLONG_MAX);
}

/* Prints a decimal number using the %i flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
