#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	len_of_dest;
	int	i;

	len_of_dest = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[len_of_dest + i] = src[i];
		i++;
	}
	dest[len_of_dest + i] = 0;
	return (dest);
}

char	*size_zero(void)
{
	char	*ptr;

	ptr = malloc(1);
	if (!ptr)
		return (NULL);
	*ptr = 0;
	return (ptr);
}

char	*merge_str(int size, char **strs, char *sep, int len)
{
	char	*ptr;
	int		i;

	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	*ptr = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(ptr, strs[i]);
		if (i != size - 1)
			ft_strcat(ptr, sep);
		i++;
	}
	return (ptr);
}
char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	if (size == 0)
		return (size_zero());
	i = 0;
	len = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	len += ft_strlen(sep) * (size - 1);
	return (merge_str(size, strs, sep, len));
}
