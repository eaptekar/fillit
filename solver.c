//
// Created by Eugene APTEKAR on 1/24/18.
//

#include "fillit.h"

static char     **rec_alg(char **map, t_tetri *list, int n)
{
    int     i;
    int     j;
    char    **final_map;

    j = 0;
    if (list->next == NULL)
        return (map);
    while (j < n)
    {
        i = 0;
        while (i < n)
        {
            if (check_insert_tetri(list, map, n) == 0)
                final_map = rec_alg(write_map(list, map, n), list->next, n);
            if (final_map)
                return (final_map);
            map = clear_map(list, map, n);
            i++;
        }
        j++;
    }
    return (NULL);
}

void            solve_map(t_tetri *list, int nmb)
{
    int     n;
    char    **map;
    char    **result;

    n = size_map(nmb);
    map = gen_map(n);
    while (!(result = rec_alg(map, list, n)))
    {
        n++;
        free(map);
        map = gen_map(n);
    }
    print_map(result);
}