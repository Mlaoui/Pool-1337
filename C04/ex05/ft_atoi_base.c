#include <stdio.h>

int     checkbase(char *base)
{
    int i;
    int j;
    if (base[0] == '\0' || base[1] == '\0')
        return 0;
    i = 0;
    while (base[i])
    {
        if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13) || base[i] == '-' || base[i] == '+')
            return 0;
        j = i + 1;
        while(base[j])
        {
            if (base[i] == base[j])
                return 0;
            j++;
        }
        i++;
    }
    return i;
}

int     value(char c,char *base)
{
    int i = 0;
    while (base[i])
    {
        if (base[i] == c)
            return i;
        i++;
    }
    return -1;
}

int ft_atoi_base(char *str,char *base)
{
    int len_of_base = checkbase(base);
    if (len_of_base == 0)
        return 0;
    int result = 0;
    int sign = 1;
    int i = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
            i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    int v = value(str[i],base);
    while (v != -1)
    {

        result = result * len_of_base + v;
        i++;
    }
    return result * sign;
}

int main()
{
    char *base = "01";
    char *str = "  -+-101avs";
    printf("expected returned value is 5 %d",ft_atoi_base(str,base));
    return 0;
}
