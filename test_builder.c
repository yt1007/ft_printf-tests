/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:12:57 by yetay             #+#    #+#             */
/*   Updated: 2023/07/07 10:59:11 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_test.h"

static void	yt_putline_fd(char *s, int fd);
static void	var_builder(char f, int fd);
static void	test_builder(char f, char *flags, int fd);

/* Program builds tests with various combination of bonus specifiers          */
/* for the given conversion                                                   */
int	main(int argc, char **argv)
{
	int	fd;

	fd = open("auto_test.c", O_WRONLY | O_CREAT);
	if (fd < 0)
		return (1);
	yt_putline_fd("#include <stdio.h>", fd);
	yt_putline_fd("#include \"ft_printf.h\"", fd);
	yt_putline_fd("#include \"ft_printf_test.h\"", fd);
	yt_putline_fd("", fd);
	yt_putline_fd("void\trun_tests(int (*f)(const char *, ...), int fd)", fd);
	yt_putline_fd("{", fd);
	if (*argv[1] == 'p' && argv[1][1] == 'e')
		test_builder('%', "-0# +", fd);
	else if (*argv[1] == 'x')
	{
		if (argv[1][2] == 'l')
			test_builder('x', "-0# +", fd);
		else
			test_builder('X', "-0# +", fd);
	}
	else
		test_builder(*argv[1], "-0# +", fd);
	yt_putline_fd("}", fd);
	close(fd);
	return (0);
}

static void	yt_putline_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

static void	var_builder(char f, int fd)
{
	write(fd, "\t", 1);
	if (f == 'c')
		write(fd, "char\t", 5);
	else if (f == 's' || f == 'p')
		write(fd, "char\t*", 6);
	else if (f == 'd' || f == 'i')
		write(fd, "int\t", 4);
	else
		write(fd, "unsigned int\t", 13);
	write(fd, "x;\n\n", 4);
	write(fd, "\tx = ", 5);
	if (f == 'c')
		write(fd, "'C'", 3);
	else if (f == 's' || f == 'p')
		write(fd, "\"A string.\"", 11);
	else
		write(fd, "42", 2);
	write(fd, ";\n", 2);
}

static void	put_test(char f, char a, char b, char c, char d, char e, int minlen, int prcn, int fd)
{
	write(fd, "\tf(\"%%", 6);
	write(fd, &a, 1);
	if (b)
		write(fd, &b, 1);
	if (c)
		write(fd, &c, 1);
	if (d)
		write(fd, &d, 1);
	if (e)
		write(fd, &e, 1);
	if (minlen)
		yt_putnbr_fd(minlen, fd);
	if (prcn)
	{
		write(fd, ".", 1);
		yt_putnbr_fd(prcn, fd);
	}
	write(fd, &f, 1);
	write(fd, "\\\\n:%", 5);
	write(fd, &a, 1);
	if (b)
		write(fd, &b, 1);
	if (c)
		write(fd, &c, 1);
	if (d)
		write(fd, &d, 1);
	if (e)
		write(fd, &e, 1);
	if (minlen)
		yt_putnbr_fd(minlen, fd);
	if (prcn)
	{
		write(fd, ".", 1);
		yt_putnbr_fd(prcn, fd);
	}
	write(fd, &f, 1);
	write(fd, "\\n\"", 3);
	if (f != '%')
		write(fd, ", x", 3);
	write(fd, ");\n", 3);
}

static void	test_builder(char f, char *flags, int fd)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;
	int	p[5];
	int	minlen;
	int	prcn;

	p[0] = 0;
	p[1] = 1;
	p[2] = 2;
	p[3] = 4;
	p[4] = 8;
	if (f != '%')
		var_builder(f, fd);
	minlen = -1;
	while (++minlen < 5)
	{
		prcn = -1;
		while (++prcn < 5)
		{
			if (minlen > 0 && prcn > 0 && minlen == prcn)
				continue ;
			a = -1;
			while (flags[++a])
			{
				put_test(f, flags[a], 0, 0, 0, 0, p[minlen], p[prcn], fd);
				b = -1;
				while (flags[++b])
				{
					if (flags[a] == flags[b])
						continue ;
					put_test(f, flags[a], flags[b], 0, 0, 0, p[minlen], p[prcn], fd);
					c = -1;
					while (flags[++c])
					{
						if (flags[a] == flags[c] || flags[b] == flags[c])
							continue ;
						put_test(f, flags[a], flags[b], flags[c], 0, 0, p[minlen], p[prcn], fd);
						d = -1;
						while (flags[++d])
						{
							if (flags[a] == flags[d])
								continue ;
							if (flags[b] == flags[d])
								continue ;
							if (flags[c] == flags[d])
								continue ;
							put_test(f, flags[a], flags[b], flags[c], flags[d], 0, p[minlen], p[prcn], fd);
							e = -1;
							while (flags[++e])
							{
								if (flags[a] == flags[e])
									continue ;
								if (flags[b] == flags[e])
									continue ;
								if (flags[c] == flags[e])
									continue ;
								if (flags[d] == flags[e])
									continue ;
								put_test(f, flags[a], flags[b], flags[c], flags[d], flags[e], p[minlen], p[prcn], fd);
							}
						}
					}
				}
			}
		}
	}
}
