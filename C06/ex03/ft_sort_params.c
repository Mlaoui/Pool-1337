#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort(int ac, char **av)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) > 0)
			{
				swap = av[i];
				av[i] = av[j];
				av[j] = swap;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	len;

	if (ac < 2)
		return (0);
	ft_sort(ac - 1, av + 1);
	i = 0;
	while (i < ac - 1)
	{
		len = 0;
		while (av[i + 1][len])
			len++;
		write(1, av[i + 1], len);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
