int	*ft_range(int min, int max)
{
	int	i;
	int	*ptr;

	if (min >= max)
		return (NULL);
	ptr = (int *)malloc((max - min) * sizeof(int));
	if (!ptr)
		return (NULL);
	i = 0;
	while (min + i < max)
	{
		ptr[i] = min + i;
		i++;
	}
	return (ptr);
}
