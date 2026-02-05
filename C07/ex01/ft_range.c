#include <stdlib.h>
#include <stdio.h>

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

int main()
{
    int min = -9;
    int max = 9;
    int i = 0;
    int *ptr = ft_range(min,max);
    while (i < max - min)
    {
        printf("%d\n",ptr[i]);
        i++;
    }
    free(ptr);
}
