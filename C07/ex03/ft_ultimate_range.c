#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*arr;

	if (!range)
		return (-1);
	if (min >= max)
	{
		*range = NULL;
		return (0);
    }
	size = max - min;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (-1);
	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (size);
}

int main()
{
    int i = 0;
    int size;
    int *range = NULL;
    size = ft_ultimate_range(&range,-8,7);
    while (i < size)
    {
        printf("%d\n",range[i]);
        i++;
    }
    free(range);
    return 0;
}
