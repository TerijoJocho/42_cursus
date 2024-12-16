#include "pipex.h"

void    check_args(int argc, char **argv)
{
   if (argc < 5 && ft_strncmp(argv[1], "here_doc", 8) != 0)
   {
        perror("Error");
        exit(EXIT_FAILURE);
   }
   if (ft_strncmp(argv[1], "here_doc", 8) == 0)
   {
        data->is_invalid_infile = false;
        data->in_fd = -1;
        
   }
    
}