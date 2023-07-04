#include <limits.h>
#include "ft_printf.h"

static void	expected_cases(void)
{
	int	i;

	i = -128;
	while (++i < 128)
		ft_printf("%%d, i (-128 - 127): %d\n", i);
	ft_printf("%%d, INT_MIN: %d\n", INT_MIN);
	ft_printf("%%d, INT_MAX: %d\n", INT_MAX);
}

static void	exceptional_cases(void)
{
	ft_printf("%%d, NULL: %d\n", NULL);
	ft_printf("%%d, INT_MIN: %d\n", INT_MIN - 1);
	ft_printf("%%d, INT_MAX: %d\n", INT_MAX + 1);
	ft_printf("%%d, UINT_MAX: %d\n", UINT_MAX);
	ft_printf("%%d, LONG_MIN: %d\n", LONG_MIN);
	ft_printf("%%d, LONG_MAX: %d\n", LONG_MAX);
	ft_printf("%%d, ULONG_MAX: %d\n", ULONG_MAX);
	ft_printf("%%d, LLONG_MIN: %d\n", LLONG_MIN);
	ft_printf("%%d, LLONG_MAX: %d\n", LLONG_MAX);
	ft_printf("%%d, ULLONG_MAX: %d\n", ULLONG_MAX);
}

/* Prints a decimal number using the %d flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
