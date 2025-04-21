#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

/*
*Affiche un message d'erreur
*/
int ft_error(char *str)
{
    while(*str)
        write(2, str++, 1);
    return (1);
}

/*
*Gère la cmd CD
*avec un seul arg, sinon erreur
*/
int ft_cd(char **argv, int i)
{
    if (i != 2)
        return (ft_error("error: cd: bad arguments\n"));
    if (chdir(argv[1]) == -1)
        return (ft_error("error: cd: cannot change directory to "), ft_error(argv[1]), ft_error("\n"));
    return (0);
}

/*
*fonction d'exec
*/
int ft_exec(char **argv, int i, char **envp)
{
    int fd[2];
    int status;
    int has_pipe;

    /*pipe apres la cmd?*/
    has_pipe = 0;
    if (argv[i] != NULL)
    {
        if (strcmp(argv[i], "|") == 0)
            has_pipe = 1;
        else
            has_pipe = 0;
    }
    /*pas de pipe + cd*/
    if (has_pipe == 0 && strcmp(*argv, "cd") == 0)
        return (ft_cd(argv, i));
    /*si pipe, on creer le pipe*/
    if (has_pipe == 1)
        if (pipe(fd) == -1)
            return (ft_error("error: fatal\n"));
    /*creation de l'enfant pour exec la cmd*/
    int pid = fork();
    if (pid == 0)
    {
        /*on coupe le tab argv au pipe*/
        argv[i] = NULL;
        /*on dup2 car on a un pipe et on ferme les fd*/
        if (has_pipe == 1)
            if (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
                return (ft_error("error: fatal\n"));
        /*on fait un cd dans l'enfant meme si c'est inutile*/
        if (strcmp(*argv, "cd") == 0)
            return (ft_cd(argv, i));
        /*on exec la cmd*/
        execve(*argv, argv, envp);
        /*si execve n'a pas reussi alors on revient ici et on affiche error*/
        return (ft_error("error: cannot execute "), ft_error(*argv), ft_error("\n"));
    }
    waitpid(pid, &status, 0);
    if (has_pipe == 1)
        if (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
            return (ft_error("error: fatal\n"));
    return (WIFEXITED(status) && WEXITSTATUS(status));
}

/*
*Le main fait le parsing,
*il se balade dans argv et avance entre chaque cmd
*/
int main(int argc, char **argv, char **envp)
{
    int i;
    int status;

    i = 0;
    status = 0;
    if (argc > 1)
    {
        while (argv[i] && argv[i + 1])
        {
            i++;
            argv = &argv[i];
            i = 0;
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++;
            status = ft_exec(argv, i, envp);
        }
    }
    return (status);
}