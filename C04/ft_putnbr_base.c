#include <unistd.h>

int     base_check(char *base)
{
    int i = 0;
    int j;
    if (!base || !base[0] || !base[1])
        return 0;
    while (base[i])
    {
        if (base[i] == '+' || base[i] == '-')
            return 0;
        j = i + 1;
        while (base[j])
        {
            if (base[i] ==  base[j])
                return 0;
            j++;
        }
        i++;
    }
    return i;
}

void    ft_putnbr_base_rec(char *base,long nb,int len)
{
    if (nb >= len)
        ft_putnbr_base_rec(base, nb / len, len);
    write(1,&base[nb % len],1);
}

void    ft_putnbr_base(int nbr,char *base)
{
    long nb;
    int len;
    len = base_check(base);
    if (!len)
        return ;
    nb = nbr;
    if (nb < 0)
    {
        write(1,"\n",1);
        nb = -nb;
    }
    ft_putnbr_base_rec(base, nb, len);
}
