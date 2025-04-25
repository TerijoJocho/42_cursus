

#include "../includes/cube3d.h"

char    **add_line(char **lines, char *line, int line_count)
{
    int     i;
    char    **new_lines;

    i = 0;
    new_lines = malloc(sizeof(char *) * (line_count + 2));
    if (!new_lines)
        return (NULL);
    while (i < line_count)
    {
        new_lines[i] = lines[i];
        i++;
    }
    new_lines[line_count] = ft_strdup(line);
    new_lines[line_count + 1] = NULL;
    free(lines);
    return (new_lines);
}

int    ft_get_file(char *argv)
{
    int     fd;
    char    *line;
    char    **lines;
    int     line_count;

    lines = NULL;
    line_count = 0;
    fd = open(argv, O_RDONLY);
    if (fd < 0)
        return (printf("error: .cub file not found\n"), 1);
    while ((line = get_next_line(fd)))
    {
        lines = add_line(lines, line, line_count);
        if (!lines)
            return (printf("error: malloc\n"));
        line_count++;
        free(line);
    }
    close(fd);
    if (line_count == 0)
        return (printf("error: empty .cub file\n"), 1);
    ft_parse_file(lines);
    return (0);
}