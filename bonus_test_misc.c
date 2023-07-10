#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"
#include "ft_printf_test.h"

void	run_tests(int (*f)(const char *, ...), int fd)
{
	f(" %.s ", "-");
	f(" %.2d ", -1);
	f(" %.3d ", -11);
	f(" %.4d ", -14);
	f(" %.3d ", -99);
	f(" %.4d ", -101);
	f(" %.10d ", LONG_MAX);
	f(" %.12d ", UINT_MAX);
	f(" %.13d ", ULONG_MAX);
	f(" %.14d ", 9223372036854775807LL);
	f(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
}
