/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:12:22 by yetay             #+#    #+#             */
/*   Updated: 2023/07/05 15:12:30 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TEST_H
# define FT_PRINTF_TEST_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

void	yt_putnbr_fd(int n, int fd);
void	yt_putnbrline_fd(int i, int fd);

#endif
