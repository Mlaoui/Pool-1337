#include <stdio.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13) || base[i] == '-'
			|| base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	skip_spaces_signs(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	i;
	int	v;
	int	len_of_base;

	if (!str || !base)
		return (0);
	result = 0;
	sign = 1;
	len_of_base = check_base(base);
	if (len_of_base == 0)
		return (0);
	i = skip_spaces_signs(str, &sign);
	v = value(str[i], base);
	while (v != -1)
	{
		result = result * len_of_base + v;
		i++;
		v = value(str[i], base);
	}
	return (result * sign);
}

int	main(void)
{
	char	*base;
	char	*str;

	base = "01";
	str = "11111111";
	printf("expected returned value is  %d\n", ft_atoi_base(str, base));
	return (0);
}
