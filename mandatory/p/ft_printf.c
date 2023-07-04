#include <limits.h>
#include "ft_printf.h"

static void	expected_cases(void)
{
	int	i;

	i = -1;
	while (++i < 256)
		ft_printf("%%p, i (0 - 255): %p\n", i);
	ft_printf("%%p, INT_MAX: %p\n", INT_MAX);
	ft_printf("%%p, UINT_MAX: %p\n", UINT_MAX);
}

static void	exceptional_cases(void)
{
	ft_printf("%%p, NULL: %p\n", NULL);
	ft_printf("%%p, -1: %p\n", -1);
	ft_printf("%%p, -17: %p\n", -17);
	ft_printf("%%p, -42: %p\n", -42);
	ft_printf("%%p, INT_MIN: %p\n", INT_MIN);
	ft_printf("%%p, UINT_MAX: %p\n", UINT_MAX + 1);
	ft_printf("%%p, LONG_MIN: %p\n", LONG_MIN);
	ft_printf("%%p, LONG_MAX: %p\n", LONG_MAX);
	ft_printf("%%p, ULONG_MAX: %p\n", ULONG_MAX);
	ft_printf("%%p, LLONG_MIN: %p\n", LLONG_MIN);
	ft_printf("%%p, LLONG_MAX: %p\n", LLONG_MAX);
	ft_printf("%%p, ULLONG_MAX: %p\n", ULLONG_MAX);
}

/* Prints a hexadecimal number using the %p flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
