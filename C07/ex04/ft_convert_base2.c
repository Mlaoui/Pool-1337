#include <stdlib.h>

int		ft_strlen(char *str);

int	ft_get_index(char c, char *base)
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

int	ft_atoi_base(char *str, char *base)
{
	long	nbr;
	int		sign;
	int		base_len;
	int		char_value;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	nbr = 0;
	base_len = ft_strlen(base);
	char_value = ft_get_index(*str, base);
	while (char_value != -1)
	{
		nbr = nbr * base_len + char_value;
		str++;
		char_value = ft_get_index(*str, base);
	}
	return (nbr * sign);
}

int	ft_count_digits(long nbr, int base_len)
{
	int	count;

	if (nbr == 0)
		return (1);
	count = 0;
	if (nbr < 0)
	{
		count = 1;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= base_len;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(long nbr, char *base)
{
	char	*result;
	int		len;
	int		base_len;
	int		is_negative;

	base_len = ft_strlen(base);
	len = ft_count_digits(nbr, base_len);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	is_negative = (nbr < 0);
	if (is_negative)
		nbr = -nbr;
	if (nbr == 0)
		result[0] = base[0];
	while (nbr > 0)
	{
		result[--len] = base[nbr % base_len];
		nbr /= base_len;
	}
	if (is_negative)
		result[0] = '-';
	return (result);
}
