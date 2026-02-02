#include <unistd.h>
#include <stdio.h>

void    ft_putchar(char c)
{
    write (1,&c,1);
}

int    factorial(int n)
{
    if (n <= 1)
    {
        printf("base case");
        return 1;
    }
    ft_putchar('\n');
    ft_putchar(n + '0');
    ft_putchar('\n');
    return n * factorial(n - 1);
}

int main()
{
    ft_putchar('\n');
    printf("%d",factorial(7));
    ft_putchar('\n');
    return 0;
}
