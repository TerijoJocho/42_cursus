
int ft_check_end_line(char *stash)
{
    while (*stash)
    {
        if (*stash == '\n')
            return (1);
        *stash++;
    }
    return (0);
}

char *ft_enleve_le_n_et_renvoie_la_ligne(char *stash)
{
    char *line;

    while (*stash != '\n')
        *line++ = *stash++;
    return (line);
}

char    *get_next_line(int fd)
{
    static char *stash;
    static t_list *stash;
    char    *buf;
    char    *line;
    int res_read;

    res_read = read(fichier.txt, buf, buf_size);
    if (res_read == 0)
        return (NULL);
    line = malloc(buf_size * sizeof(char));
    if (!line)
        return (NULL);  
    while (res_read != 0)
    {
        stash = ft_stock_dans_stash(buf);
        if (ft_check_end_line(stash) == 1)
        {
            line = ft_enleve_le_n_et_renvoie_la_ligne(stash);
            return (line); //s'arrete nan?
        }
        res_read = read(fichier.txt, buf, buf_size);
    }
}
NB : si on a buf_size = 9999, il faut donc que mon ft_check_end_line
        regarde combien de \n il y a dans mon buffer et que mon 
        ft_enleve_le_n_et_renvoie_la_ligne ???