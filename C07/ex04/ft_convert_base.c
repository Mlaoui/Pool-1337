#include <unistd.h>

int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(long nbr, char *base);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_checkbase(char *base)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(base);
	if (len < 2)
		return (0);
	i = 0;
	while (i < len)
	{
		if (base[i] <= 32 || base[i] == '+' || base[i] == '-' || base[i] == 127)
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	decimal_value;

	if (nbr == NULL || base_from == NULL || base_to == NULL)
		return (NULL);
	if (!ft_checkbase(base_from) || !ft_checkbase(base_to))
		return (NULL);
	decimal_value = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(decimal_value, base_to));
}
