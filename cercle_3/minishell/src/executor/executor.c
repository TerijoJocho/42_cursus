

# include "../../includes/minishell.h"

// int executor(t_master *master)
// {
//     int pipefd[2];
//     pid_t pid;
//     char buf;

//     if (master->)
// }

// int executor(t_master *master)
// {
//     int pipefd[2];
//     pid_t pid;
//     char buf;

//     (void)master;
//     if (pipe(pipefd) == -1)
//         return (1);
//     pid = fork();
//     if (pid == -1)
//         return (1);
//     else if (pid == 0)
//     {
//         close(pipefd[1]);
//         write(STDOUT_FILENO, "K : le secret est : \n", 20);
//         while(read(pipefd[0], &buf, 1) > 0)
//             write(STDOUT_FILENO, &buf, 1);
//         // write(STDOUT_FILENO, "\"\n", 2);
//         close(pipefd[0]);
//         exit(EXIT_SUCCESS);
//     }
//     else
//     {
//         close(pipefd[0]);
//         write(STDOUT_FILENO, "P : j'ai un secret\n", 19);
//         write(pipefd[1], "\e[33m\"MINISHELL\"\e[0m\n", 21);
//         close(pipefd[1]);
//         wait(NULL);
//         write(STDOUT_FILENO, "P : GG\n", 7);
//     }
//     return (0);
// }
