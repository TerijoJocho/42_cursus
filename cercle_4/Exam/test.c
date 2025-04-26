#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int ft_error(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
    return (1);
}

int ft_cd(char **argv, int i)
{
    if (i != 2)
        return (ft_error("error: cd: bad arguments"), ft_error("\n"));
    if (chdir(argv[1]) == -1)
        return (ft_error("error: cd: cannot change directory to "), ft_error(argv[1]), ft_error("\n"));
    return (0);
}

int ft_exec(char **argv, int i, char **envp)
{
    int status;
    int fd[2];
    int pid;
    int has_pipe;

    has_pipe = 0;
    if (argv[i] && !strcmp(argv[i], "|"))
        has_pipe = 1;
    if (!has_pipe && !strcmp(*argv, "cd"))
        return(ft_cd(argv, i));
    if (has_pipe && pipe(fd) == -1)
        return (ft_error("error: fatal\n"));
    pid = fork();
    if (!pid)
    {
        argv[i] = NULL;
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return (ft_error("error: fatal\n"));
        if (has_pipe && !strcmp(*argv, "cd"))
            ft_cd(argv, i);
        execve(*argv, argv, envp);
        return (ft_error("error: cannot execute "), ft_error(*argv), ft_error("\n"));
    }
    waitpid(pid, &status, 0);
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return (ft_error("error: fatal\n"));
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (1);
}

int main(int argc, char **argv, char **envp)
{
    int i;
    int status;

    i = 0;
    status = 0;
    if (argc > 1)
    {
        while(argv[i] && argv[i + 1])
        {
            i++;
            argv = &argv[i];
            i = 0;
            while(argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++;
            status = ft_exec(argv, i ,envp);
        }
    }
    return(status);
}