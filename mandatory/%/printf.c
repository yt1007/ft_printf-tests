#include <limits.h>
#include <stdio.h>

static void	expected_cases(void)
{
	printf("%%%%: %%\n");
	printf("%%%% %%%%: %% %%\n");
	printf("%%%%d%%%%: %%d%%\n");
}

static void	exceptional_cases(void)
{
	printf("%%: %\n");
	printf("%% %%%%: % %%\n");
	printf("%%%% %%%%%%: %% %%%\n");
}

/* Prints a percent character using the %% flag, */
/* followed by a new line. */
int	main(void)
{
	expected_cases();
	exceptional_cases();
	return (0);
}
