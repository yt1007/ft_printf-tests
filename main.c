/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:31:22 by yetay             #+#    #+#             */
/*   Updated: 2023/06/28 18:23:12 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

static int	ft_printf_isdiff(void)
{
	return (system("/usr/bin/diff stdout.ft_printf stdout.printf > /dev/null"));
}

static void	ft_putfile_fd(char *fn, int fd)
{
	int		fd_fn;
	char	c;

	fd_fn = open(fn, O_RDONLY);
	if (!fd_fn)
		return ;
	while (read(fd_fn, &c, 1))
		write(fd, &c, 1);
}

static void ft_puttest(int i, char *a)
{
	ft_putstr_fd(" test ", 2);
	ft_putnbr_fd(i, 2);
	ft_putendl_fd(" failed!", 2);
	ft_putstr_fd("    Arguments: ", 2);
	ft_putendl_fd(a, 2);
}

static void ft_putres(int x, int y)
{
	ft_putstr_fd("      Results: ", 2);
	ft_putnbr_fd(y, 2);
	ft_putstr_fd(" (printf) ", 2);
	ft_putfile_fd("stdout.printf", 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("               ", 2);
	ft_putnbr_fd(x, 2);
	ft_putstr_fd(" (ft_printf) ", 2);
	ft_putfile_fd("stdout.ft_printf", 2);
	ft_putendl_fd("", 2);
}

int	main(void)
{
	int			errors;
	int			i;
	int			x;
	int			y;
	long long	l[9];
	char		*s[8];

	errors = 0;
	l[0] = INT_MIN;
	l[1] = INT_MAX;
	l[2] = LONG_MIN;
	l[3] = LONG_MAX;
	l[4] = LLONG_MIN;
	l[5] = LLONG_MAX;
	l[6] = UINT_MAX;
	l[7] = ULONG_MAX;
	l[8] = ULLONG_MAX;
	// %c tests
	i = -1;
	while (++i < 256)
	{
		freopen("stdout.ft_printf", "w", stdout);
		x = ft_printf("%c", i);
		fclose(stdout);
		freopen("stdout.printf", "w", stdout);
		y = printf("%c", i);
		fclose(stdout);
		freopen("/dev/stdout", "w", stdout);
		if (x != y || ft_printf_isdiff())
		{
			ft_putstr_fd("%c", 2);
			ft_puttest(i, "\"%c\", i");
			ft_putstr_fd("               i = ", 2);
			ft_putnbr_fd(i, 2);
			ft_putendl_fd("", 2);
			ft_putres(x, y);
			errors++;
		}
	}
	// %d tests
	i = -129;
	while (++i < 128)
	{
		freopen("stdout.ft_printf", "w", stdout);
		x = ft_printf("%d", i);
		fclose(stdout);
		freopen("stdout.printf", "w", stdout);
		y = printf("%d", i);
		fclose(stdout);
		freopen("/dev/stdout", "w", stdout);
		if (x != y || ft_printf_isdiff())
		{
			ft_putstr_fd("%d", 2);
			ft_puttest(i, "\"%d\", i");
			ft_putstr_fd("               i = ", 2);
			ft_putnbr_fd(i + 128, 2);
			ft_putendl_fd("", 2);
			ft_putres(x, y);
			errors++;
		}
	}
	i = -1;
	while (++i < 9)
	{
		freopen("stdout.ft_printf", "w", stdout);
		x = ft_printf("%d", l[i]);
		fclose(stdout);
		freopen("stdout.printf", "w", stdout);
		y = printf("%d", l[i]);
		fclose(stdout);
		freopen("/dev/stdout", "w", stdout);
		if (x != y || ft_printf_isdiff())
		{
			ft_putstr_fd("%d", 2);
			ft_puttest(i, "\"%d\", i");
			ft_putstr_fd("               i = ", 2);
			ft_putnbr_fd(l[i], 2);
			ft_putendl_fd("", 2);
			ft_putres(x, y);
			errors++;
		}
	}
	// %i tests
	i = -129;
	while (++i < 128)
	{
		freopen("stdout.ft_printf", "w", stdout);
		x = ft_printf("%i", i);
		fclose(stdout);
		freopen("stdout.printf", "w", stdout);
		y = printf("%i", i);
		fclose(stdout);
		freopen("/dev/stdout", "w", stdout);
		if (x != y || ft_printf_isdiff())
		{
			ft_putstr_fd("%i", 2);
			ft_puttest(i, "\"%i\", i");
			ft_putstr_fd("               i = ", 2);
			ft_putnbr_fd(i + 128, 2);
			ft_putendl_fd("", 2);
			ft_putres(x, y);
			errors++;
		}
	}
	i = -1;
	while (++i < 9)
	{
		freopen("stdout.ft_printf", "w", stdout);
		x = ft_printf("%i", l[i]);
		fclose(stdout);
		freopen("stdout.printf", "w", stdout);
		y = printf("%i", l[i]);
		fclose(stdout);
		freopen("/dev/stdout", "w", stdout);
		if (x != y || ft_printf_isdiff())
		{
			ft_putstr_fd("%i", 2);
			ft_puttest(i, "\"%i\", i");
			ft_putstr_fd("               i = ", 2);
			ft_putnbr_fd(l[i], 2);
			ft_putendl_fd("", 2);
			ft_putres(x, y);
			errors++;
		}
	}
	// %u tests
	i = -129;
	while (++i < 128)
	{
		freopen("stdout.ft_printf", "w", stdout);
		x = ft_printf("%u", i);
		fclose(stdout);
		freopen("stdout.printf", "w", stdout);
		y = printf("%u", i);
		fclose(stdout);
		freopen("/dev/stdout", "w", stdout);
		if (x != y || ft_printf_isdiff())
		{
			ft_putstr_fd("%u", 2);
			ft_puttest(i, "\"%u\", i");
			ft_putstr_fd("               i = ", 2);
			ft_putnbr_fd(i + 128, 2);
			ft_putendl_fd("", 2);
			ft_putres(x, y);
			errors++;
		}
	}
	i = -1;
	while (++i < 9)
	{
		freopen("stdout.ft_printf", "w", stdout);
		x = ft_printf("%u", l[i]);
		fclose(stdout);
		freopen("stdout.printf", "w", stdout);
		y = printf("%u", l[i]);
		fclose(stdout);
		freopen("/dev/stdout", "w", stdout);
		if (x != y || ft_printf_isdiff())
		{
			ft_putstr_fd("%u", 2);
			ft_puttest(i, "\"%u\", i");
			ft_putstr_fd("               i = ", 2);
			ft_putnbr_fd(l[i], 2);
			ft_putendl_fd("", 2);
			ft_putres(x, y);
			errors++;
		}
	}
	// %p tests
	i = -129;
	while (++i < 128)
	{
		freopen("stdout.ft_printf", "w", stdout);
		x = ft_printf("%p", i);
		fclose(stdout);
		freopen("stdout.printf", "w", stdout);
		y = printf("%p", i);
		fclose(stdout);
		freopen("/dev/stdout", "w", stdout);
		if (x != y || ft_printf_isdiff())
		{
			ft_putstr_fd("%p", 2);
			ft_puttest(i, "\"%p\", i");
			ft_putstr_fd("               i = ", 2);
			ft_putnbr_fd(i + 128, 2);
			ft_putendl_fd("", 2);
			ft_putres(x, y);
			errors++;
		}
	}
	i = -1;
	while (++i < 9)
	{
		freopen("stdout.ft_printf", "w", stdout);
		x = ft_printf("%p", l[i]);
		fclose(stdout);
		freopen("stdout.printf", "w", stdout);
		y = printf("%p", l[i]);
		fclose(stdout);
		freopen("/dev/stdout", "w", stdout);
		if (x != y || ft_printf_isdiff())
		{
			ft_putstr_fd("%p", 2);
			ft_puttest(i, "\"%p\", i");
			ft_putstr_fd("               i = ", 2);
			ft_putnbr_fd(l[i], 2);
			ft_putendl_fd("", 2);
			ft_putres(x, y);
			errors++;
		}
	}
	// %x tests
	i = -129;
	while (++i < 128)
	{
		freopen("stdout.ft_printf", "w", stdout);
		x = ft_printf("%x", i);
		fclose(stdout);
		freopen("stdout.printf", "w", stdout);
		y = printf("%x", i);
		fclose(stdout);
		freopen("/dev/stdout", "w", stdout);
		if (x != y || ft_printf_isdiff())
		{
			ft_putstr_fd("%x", 2);
			ft_puttest(i, "\"%x\", i");
			ft_putstr_fd("               i = ", 2);
			ft_putnbr_fd(i + 128, 2);
			ft_putendl_fd("", 2);
			ft_putres(x, y);
			errors++;
		}
	}
	i = -1;
	while (++i < 9)
	{
		freopen("stdout.ft_printf", "w", stdout);
		x = ft_printf("%x", l[i]);
		fclose(stdout);
		freopen("stdout.printf", "w", stdout);
		y = printf("%x", l[i]);
		fclose(stdout);
		freopen("/dev/stdout", "w", stdout);
		if (x != y || ft_printf_isdiff())
		{
			ft_putstr_fd("%x", 2);
			ft_puttest(i, "\"%x\", i");
			ft_putstr_fd("               i = ", 2);
			ft_putnbr_fd(l[i], 2);
			ft_putendl_fd("", 2);
			ft_putres(x, y);
			errors++;
		}
	}
	// %X tests
	i = -129;
	while (++i < 128)
	{
		freopen("stdout.ft_printf", "w", stdout);
		x = ft_printf("%X", i);
		fclose(stdout);
		freopen("stdout.printf", "w", stdout);
		y = printf("%X", i);
		fclose(stdout);
		freopen("/dev/stdout", "w", stdout);
		if (x != y || ft_printf_isdiff())
		{
			ft_putstr_fd("%X", 2);
			ft_puttest(i, "\"%X\", i");
			ft_putstr_fd("               i = ", 2);
			ft_putnbr_fd(i + 128, 2);
			ft_putendl_fd("", 2);
			ft_putres(x, y);
			errors++;
		}
	}
	i = -1;
	while (++i < 9)
	{
		freopen("stdout.ft_printf", "w", stdout);
		x = ft_printf("%X", l[i]);
		fclose(stdout);
		freopen("stdout.printf", "w", stdout);
		y = printf("%X", l[i]);
		fclose(stdout);
		freopen("/dev/stdout", "w", stdout);
		if (x != y || ft_printf_isdiff())
		{
			ft_putstr_fd("%X", 2);
			ft_puttest(i, "\"%X\", i");
			ft_putstr_fd("               i = ", 2);
			ft_putnbr_fd(l[i], 2);
			ft_putendl_fd("", 2);
			ft_putres(x, y);
			errors++;
		}
	}
	// %% tests
	i = 0;
	freopen("stdout.ft_printf", "w", stdout);
	x = ft_printf("%%");
	fclose(stdout);
	freopen("stdout.printf", "w", stdout);
	y = printf("%%");
	fclose(stdout);
	freopen("/dev/stdout", "w", stdout);
	if (x != y || ft_printf_isdiff())
	{
		ft_putstr_fd("%%", 2);
		ft_puttest(i, "\"%%\"");
		ft_putres(x, y);
		errors++;
	}
	i = 1;
	freopen("stdout.ft_printf", "w", stdout);
	x = ft_printf("%%%%");
	fclose(stdout);
	freopen("stdout.printf", "w", stdout);
	y = printf("%%%%");
	fclose(stdout);
	freopen("/dev/stdout", "w", stdout);
	if (x != y || ft_printf_isdiff())
	{
		ft_putstr_fd("%%", 2);
		ft_puttest(i, "\"%%%%\"");
		ft_putres(x, y);
		errors++;
	}
	i = 2;
	freopen("stdout.ft_printf", "w", stdout);
	x = ft_printf("%% %%");
	fclose(stdout);
	freopen("stdout.printf", "w", stdout);
	y = printf("%% %%");
	fclose(stdout);
	freopen("/dev/stdout", "w", stdout);
	if (x != y || ft_printf_isdiff())
	{
		ft_putstr_fd("%%", 2);
		ft_puttest(i, "\"%% %%\"");
		ft_putres(x, y);
		errors++;
	}
	i = 3;
	freopen("stdout.ft_printf", "w", stdout);
	x = ft_printf("%");
	fclose(stdout);
	freopen("stdout.printf", "w", stdout);
	y = printf("%");
	fclose(stdout);
	freopen("/dev/stdout", "w", stdout);
	if (x != y || ft_printf_isdiff())
	{
		ft_putstr_fd("%%", 2);
		ft_puttest(i, "\"%\"");
		ft_putres(x, y);
		errors++;
	}
	i = 4;
	freopen("stdout.ft_printf", "w", stdout);
	x = ft_printf("% %%");
	fclose(stdout);
	freopen("stdout.printf", "w", stdout);
	y = printf("% %%");
	fclose(stdout);
	freopen("/dev/stdout", "w", stdout);
	if (x != y || ft_printf_isdiff())
	{
		ft_putstr_fd("%%", 2);
		ft_puttest(i, "\"% %%\"");
		ft_putres(x, y);
		errors++;
	}
	i = 5;
	freopen("stdout.ft_printf", "w", stdout);
	x = ft_printf("%% %%%");
	fclose(stdout);
	freopen("stdout.printf", "w", stdout);
	y = printf("%% %%%");
	fclose(stdout);
	freopen("/dev/stdout", "w", stdout);
	if (x != y || ft_printf_isdiff())
	{
		ft_putstr_fd("%%", 2);
		ft_puttest(i, "\"%% %%%\"");
		ft_putres(x, y);
		errors++;
	}
	// %s tests
	s[0] = "";
	s[1] = "\n";
	s[2] = "A";
	s[3] = "A cat is not a dog.";
	s[4] = "The quick brown fox jumps over the lazy dog.";
	s[5] = "The quick brown fox jumps over the lazy dog.\n";
	s[6] = "Th!s is @ f^cking l0ng a$$ sentence with a p%rc&n+ char in it.";
	s[7] = NULL;
	i = -1;
	while (++i < 8)
	{
		freopen("stdout.ft_printf", "w", stdout);
		x = ft_printf("%s", s[i]);
		fclose(stdout);
		freopen("stdout.printf", "w", stdout);
		y = printf("%s", s[i]);
		fclose(stdout);
		freopen("/dev/stdout", "w", stdout);
		if (x != y || ft_printf_isdiff())
		{
			ft_putstr_fd("%s", 2);
			ft_puttest(i, "\"%s\", s");
			ft_putstr_fd("               s = ", 2);
			ft_putendl_fd(s[i], 2);
			ft_putres(x, y);
			errors++;
		}
	}
	// MIXED FORMATS
	i = 0;
	freopen("stdout.ft_printf", "w", stdout);
	x = ft_printf("%s%c", s[4], '\n');
	fclose(stdout);
	freopen("stdout.printf", "w", stdout);
	y = printf("%s%c", s[4], '\n');
	fclose(stdout);
	freopen("/dev/stdout", "w", stdout);
	if (x != y || ft_printf_isdiff())
	{
		ft_putstr_fd("Mixed", 2);
		ft_puttest(i, "\"%s%c\", s, '\\n'");
		ft_putstr_fd("               s = ", 2);
		ft_putendl_fd(s[4], 2);
		ft_putres(x, y);
		errors++;
	}
	i = 1;
	freopen("stdout.ft_printf", "w", stdout);
	x = ft_printf("%s (%p)", s[4], s[4]);
	fclose(stdout);
	freopen("stdout.printf", "w", stdout);
	y = printf("%s (%p)", s[4], s[4]);
	fclose(stdout);
	freopen("/dev/stdout", "w", stdout);
	if (x != y || ft_printf_isdiff())
	{
		ft_putstr_fd("Mixed", 2);
		ft_puttest(i, "\"%s%c\", s, s");
		ft_putstr_fd("               s = ", 2);
		ft_putendl_fd(s[4], 2);
		ft_putres(x, y);
		errors++;
	}
	i = 2;
	freopen("stdout.ft_printf", "w", stdout);
	x = ft_printf("%d%% %s (%p)\n", 100, "working.", s[0]);
	fclose(stdout);
	freopen("stdout.printf", "w", stdout);
	y = printf("%d%% %s (%p)\n", 100, "working.", s[0]);
	fclose(stdout);
	freopen("/dev/stdout", "w", stdout);
	if (x != y || ft_printf_isdiff())
	{
		ft_putstr_fd("Mixed", 2);
		ft_puttest(i, "\"%d%% %s (%p)\\n\", 100, \"working.\", s");
		ft_putstr_fd("               s = ", 2);
		ft_putendl_fd(s[0], 2);
		ft_putres(x, y);
		errors++;
	}
	// END OF TESTS
	if (errors == 0)
		ft_putendl_fd("All tests passed.", 2);
	return (0);
}
