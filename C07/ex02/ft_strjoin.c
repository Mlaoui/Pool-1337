#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*size_zero(void)
{
	char	*ptr;

	ptr = (char *)malloc(1);
	if (!ptr)
		return (NULL);
	*ptr = 0;
	return (ptr);
}

char	*merge_str(int size, char **strs, char *sep, int len)
{
	int		i;
	char	*ptr;
	char	*p_str;
	char	*s;

	i = 0;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	p_str = ptr;
	while (i < size)
	{
		while (*strs[i])
			*p_str++ = *strs[i]++;
		if (i != size - 1 && sep != NULL)
		{
			s = sep;
			while (*s)
				*p_str++ = *s++;
		}
		i++;
	}
	*p_str = '\0';
	return (ptr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	if (size == 0)
		return (size_zero());
	i = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	len += ft_strlen(sep) * (size - 1);
	return (merge_str(size, strs, sep, len));
}
