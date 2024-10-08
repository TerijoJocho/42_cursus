int    is_power_of_2(unsigned int n)
{
    if (n > 0 && ((n & (n - 1)) == 0))
        return (1);
    return (0);
}

#include <stdio.h>

int main(void)
{
    printf("%d", is_power_of_2(4));
    return (0);
}