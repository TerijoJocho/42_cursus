#include <unistd.h>

int main(void)
{
    int i;
    int j;
    int k;

    i = 1;
    while (i <= 100)
    {
        if (i % 15 == 0)
            write(1, "FizzBuzz", 8);
        else if (i % 5 == 0)
            write(1, "Buzz", 4);
        else if (i % 3 == 0)
            write(1, "Fizz", 4);
        else if (i > 10)
        {
            j = i / 10 + '0';
            k = i % 10 + '0';
            write(1, &j, 1);
            write(1, &k, 1);
        } 
        else
        {
            k = i + '0';
            write(1, &k, 1);
        }
        write(1, "\n", 1);
        i++;
    }
    return (0);
}