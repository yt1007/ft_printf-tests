#include <limits.h>
#include "ft_printf.h"

static void	expected_cases(void)
{
	ft_printf("%%%%: %%\n");
	ft_printf("%%%% %%%%: %% %%\n");
	ft_printf("%%%%d%%%%: %%d%%\n");
}

static void	exceptional_cases(void)
{
	ft_printf("%%: %\n");
	ft_printf("%% %%%%: % %%\n");
	ft_printf("%%%% %%%%%%: %% %%%\n");
}

/* Prints a percent character using the %% flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
