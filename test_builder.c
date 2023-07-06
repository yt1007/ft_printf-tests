/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:12:57 by yetay             #+#    #+#             */
/*   Updated: 2023/07/06 17:36:33 by yetay            ###   ########.fr       */
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

static void	test_builder(char f, char *flags, int fd)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;
	int	p[3];
	int	minlen;
	int	prcn;

	p[0] = 0;
	p[1] = 4;
	p[2] = 8;
	if (f != '%')
		var_builder(f, fd);
	minlen = -1;
	while (++minlen < 3)
	{
		prcn = -1;
		while (++prcn < 3)
		{
			if (minlen > 0 && prcn > 0 && minlen == prcn)
				continue ;
			a = -1;
			while (flags[++a])
			{
				write(fd, "\tf(\"%", 5);
				write(fd, &flags[a], 1);
				if (p[minlen])
					yt_putnbr_fd(p[minlen], fd);
				if (p[prcn])
				{
					write(fd, ".", 1);
					yt_putnbr_fd(p[prcn], fd);
				}
				write(fd, &f, 1);
				write(fd, "\\n\"", 3);
				if (f != '%')
					write(fd, ", x", 3);
				write(fd, ");\n", 3);
				b = -1;
				while (flags[++b])
				{
					if (flags[a] == flags[b])
						continue ;
					write(fd, "\tf(\"%", 5);
					write(fd, &flags[a], 1);
					write(fd, &flags[b], 1);
					if (p[minlen])
						yt_putnbr_fd(p[minlen], fd);
					if (p[prcn])
					{
						write(fd, ".", 1);
						yt_putnbr_fd(p[prcn], fd);
					}
					write(fd, &f, 1);
					write(fd, "\\n\"", 3);
					if (f != '%')
						write(fd, ", x", 3);
					write(fd, ");\n", 3);
					c = -1;
					while (flags[++c])
					{
						if (flags[a] == flags[c] || flags[b] == flags[c])
							continue ;
						write(fd, "\tf(\"%", 5);
						write(fd, &flags[a], 1);
						write(fd, &flags[b], 1);
						write(fd, &flags[c], 1);
						if (p[minlen])
							yt_putnbr_fd(p[minlen], fd);
						if (p[prcn])
						{
							write(fd, ".", 1);
							yt_putnbr_fd(p[prcn], fd);
						}
						write(fd, &f, 1);
						write(fd, "\\n\"", 3);
						if (f != '%')
							write(fd, ", x", 3);
						write(fd, ");\n", 3);
						d = -1;
						while (flags[++d])
						{
							if (flags[a] == flags[d])
								continue ;
							if (flags[b] == flags[d])
								continue ;
							if (flags[c] == flags[d])
								continue ;
							write(fd, "\tf(\"%", 5);
							write(fd, &flags[a], 1);
							write(fd, &flags[b], 1);
							write(fd, &flags[c], 1);
							write(fd, &flags[d], 1);
							if (p[minlen])
								yt_putnbr_fd(p[minlen], fd);
							if (p[prcn])
							{
								write(fd, ".", 1);
								yt_putnbr_fd(p[prcn], fd);
							}
							write(fd, &f, 1);
							write(fd, "\\n\"", 3);
							if (f != '%')
								write(fd, ", x", 3);
							write(fd, ");\n", 3);
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
								write(fd, "\tf(\"%", 5);
								write(fd, &flags[a], 1);
								write(fd, &flags[b], 1);
								write(fd, &flags[c], 1);
								write(fd, &flags[d], 1);
								write(fd, &flags[e], 1);
								if (p[minlen])
									yt_putnbr_fd(p[minlen], fd);
								if (p[prcn])
								{
									write(fd, ".", 1);
									yt_putnbr_fd(p[prcn], fd);
								}
								write(fd, &f, 1);
								write(fd, "\\n\"", 3);
								if (f != '%')
									write(fd, ", x", 3);
								write(fd, ");\n", 3);
							}
						}
					}
				}
			}
		}
	}
}
