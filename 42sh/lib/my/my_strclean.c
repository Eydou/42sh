/*
** EPITECH PROJECT, 2019
** navy
** File description:
** issou
*/

#include "mysh.h"

#include <stdlib.h>

static int is_a_space(char *line, int count)
{
    if ((line[count] == ' ' && line[count + 1] == ' ') ||
        (line[count] == '\t' && line[count + 1] == ' ') ||
        (line[count] == ' ' && line[count + 1] == '\t'))
        return (1);
    return (0);
}

static int is_a_real_space(char *line, int count)
{
    if (line[count] == '\t' && line[count + 1] != '\t' &&
        line[count + 1] != ' ')
        return (1);
    return (0);
}

static int get_count(char *line)
{
    int count = 0;

    for (; line[count] == ' ' || line[count] == '\t'; count++);
    return (count);
}

char *my_strclean(char *line)
{
    int count = get_count(line);
    int i = 0;
    char *result = calloc(1, sizeof(char) * my_strlen(line) + 10);

    for (; line[count] != '\0'; count++) {
        if (is_a_space(line, count));
        else if (is_a_real_space(line, count))
            result[i++] = ' ';
        else
            result[i++] = line[count];
    }
    if (i == 0);
    else if (result[i - 1] == ' ' || result[i - 1] == '\t')
        result[i - 1] = '\0';
    free(line);
    return (result);
}
