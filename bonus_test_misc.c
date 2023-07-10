#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"
#include "ft_printf_test.h"

void	run_tests(int (*f)(const char *, ...), int fd)
{
	f("%%.s:%.s\n", "-");
	f("%%.2d:%.2d\n", -1);
	f("%%.3d:%.3d\n", -11);
	f("%%.4d:%.4d\n", -14);
	f("%%.3d:%.3d\n", -99);
	f("%%.4d:%.4d\n", -101);
	f("%%.10d:%.10d\n", LONG_MAX);
	f("%%.12d:%.12d\n", UINT_MAX);
	f("%%.13d:%.13d\n", ULONG_MAX);
	f("%%.14d:%.14d\n", 9223372036854775807LL);
	f("%%.8d %%.9d %%.10d %%.11d %%.12d %%.13d %%.14d:%.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	f("%%#x:%#x\n", 0);
	f("%%#x:%#x\n", LONG_MIN);
	f("%%#x %%#x %%#x %%#x %%#x %%#x %%#x :%#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
}
