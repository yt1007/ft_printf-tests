/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:31:22 by yetay             #+#    #+#             */
/*   Updated: 2023/06/28 13:54:28 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

static int	ft_printf_isdiff(void)
{
	int		x;
	int		y;
	char	a;
	char	b;
	int		rx;
	int		ry;

	x = open("stdout.ft_printf", O_RDONLY);
	if (!x)
		return (1);
	y = open("stdout.printf", O_RDONLY);
	if (!y)
	{
		close(x);
		return (1);
	}
	rx = 1;
	ry = 1;
	while (rx || ry)
	{
		rx = read(x, &a, 1);
		ry = read(y, &b, 1);
		if (a != b)
		{
			close(x);
			close(y);
			return (1);
		}
	}
	close(x);
	close(y);
	return (0);
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
	char		*s[7];
	long long	l[9];

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
	i = -1;
	while (++i < 256)
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
			ft_putnbr_fd(i, 2);
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
	i = -1;
	while (++i < 256)
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
			ft_putnbr_fd(i, 2);
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
	i = -1;
	while (++i < 256)
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
			ft_putnbr_fd(i, 2);
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
	if (errors == 0)
		ft_putendl_fd("All tests passed.", 2);
	return (0);
}
