#include <unistd.h>
#include <stdio.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}


void    ft_putnbr(int nb)
{
    if (nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + '0');
}

int     fibonacci(int n)
{
    if (n == 1)
        return 1;
    ft_putnbr(n);
    ft_putchar('\n');
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    printf("%d,\n",fibonacci(6));
    return 0;
}
