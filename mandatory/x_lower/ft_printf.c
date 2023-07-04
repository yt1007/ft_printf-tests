#include <limits.h>
#include "ft_printf.h"

static void	expected_cases(void)
{
	int	i;

	i = -1;
	while (++i < 256)
		ft_printf("%%x, i (0 - 255): %x\n", i);
	ft_printf("%%x, INT_MAX: %x\n", INT_MAX);
	ft_printf("%%x, UINT_MAX: %x\n", UINT_MAX);
}

static void	exceptional_cases(void)
{
	ft_printf("%%x, NULL: %x\n", NULL);
	ft_printf("%%x, -1: %x\n", -1);
	ft_printf("%%x, -17: %x\n", -17);
	ft_printf("%%x, -42: %x\n", -42);
	ft_printf("%%x, INT_MIN: %x\n", INT_MIN);
	ft_printf("%%x, UINT_MAX: %x\n", UINT_MAX + 1);
	ft_printf("%%x, LONG_MIN: %x\n", LONG_MIN);
	ft_printf("%%x, LONG_MAX: %x\n", LONG_MAX);
	ft_printf("%%x, ULONG_MAX: %x\n", ULONG_MAX);
	ft_printf("%%x, LLONG_MIN: %x\n", LLONG_MIN);
	ft_printf("%%x, LLONG_MAX: %x\n", LLONG_MAX);
	ft_printf("%%x, ULLONG_MAX: %x\n", ULLONG_MAX);
}

/* Prints a hexadecimal number using the %x flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
