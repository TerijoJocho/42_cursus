#include "my_bsq.h"

int main(int argc, char** argv)
{
    if (argc == 1) //like {./a.out}
    {
        if (execute_my_bsq(stdin) == -1)
        {
            fprintf(stderr, "map error\n");
            return (-1);
        }
    }
    else if (argc == 2) // like {./a.out map.txt}
    {
        if (my_convert_file_pointer(argv[1]) == -1)
        {
            fprintf(stderr, "map error\n");
            return (-1);
        }
    }
    else //like {./a.out map1 map2 map3...}
    {
        int i = 1;
        while (i < argc)
        {
            if (my_convert_file_pointer(argv[i]) == -1)
                fprintf(stderr, "map error\n");
            i += 1;
            if (i < argc)
                fprintf(stdout, "\n");
        }
    }
    return (0);
}