/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:31:22 by yetay             #+#    #+#             */
/*   Updated: 2023/07/05 17:32:42 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int	strlen(char *c)
{
	int	i;

	if (!c)
		return (0);
	i = 0;
	while (c[i])
		i++;
	return (i);
}

static int	ft_printf_out_isdiff(void)
{
	return (system("/usr/bin/diff -a printf.out ft_printf.out > diff.out"));
}

static int	ft_printf_ret_isdiff(void)
{
	return (system("/usr/bin/diff -a printf.ret ft_printf.ret > diff.ret"));
}

int	main(int argc, char **argv)
{
	int	output_is_diff;
	int	retval_is_diff;

	if (argc != 2)
		return (1);
	write(2, "Running tests for ", 18);
	write(2, argv[1], strlen(argv[1]));
	write(2, "...", 3);
	output_is_diff = ft_printf_out_isdiff();
	retval_is_diff = ft_printf_ret_isdiff();
	if (output_is_diff || retval_is_diff)
		write(2, " Tests FAILED. Check diffs.\n", 28);
	else
	{
		write(2, " All tests passed.\n", 19);
		unlink("diff.out");
		unlink("diff.ret");
	}
	unlink("printf.out");
	unlink("printf.ret");
	unlink("ft_printf.out");
	unlink("ft_printf.ret");
	return (0);
}
