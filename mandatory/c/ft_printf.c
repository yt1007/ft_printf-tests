#include <limits.h>
#include "ft_printf.h"

static void	expected_cases(void)
{
	int	i;

	i = -1;
	while (++i < 256)
		ft_printf("%%c, i (0 - 255): %c\n", i);
}

static void	exceptional_cases(void)
{
	ft_printf("%%c, INT_MIN: %c\n", INT_MIN);
	ft_printf("%%c, -42: %c\n", -42);
	ft_printf("%%c, -17: %c\n", -17);
}

/* Prints a single character using the %c flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
