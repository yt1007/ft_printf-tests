#include <unistd.h>

void	yt_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (-(n / 10) > 0)
			yt_putnbr_fd(-(n / 10), fd);
		yt_putnbr_fd(-(n % 10), fd);
	}
	if (n > 10)
	{
		yt_putnbr_fd(n / 10, fd);
		yt_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = (char) n;
		c += '0';
		write(fd, &c, 1);
	}
}

void	yt_putnbrline_fd(int i, int fd)
{
	yt_putnbr_fd(i, fd);
	write(fd, "\n", 1);
}
