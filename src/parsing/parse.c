

#include "../../inc/map.h"

int is_player(char c){
    if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (1)
    return (0);
}

int check_neighbors(char **map, int i, int j){
    if (!map[i][j])
        return (0);
    
    
    // check for 0 and player
    if(map[i][j] == ' ' || is_player(map[i][j])
        && map[i][j - 1] && map[j][i + 1] 
        && map[i][j - 1] == '1' && map[i][j + 1] == '1'
        && map[i - 1][j] && map[i + 1][j]
        && map[i - 1][j] == '1' && map[i + 1][j] == '1')

    // check for spaces 
    if(map[i][j] == ' ' && map[i][j - 1] && map[j][i + 1] 
        && map[i][j - 1] == '1' && map[i][j + 1] == '1'
        && map[i - 1][j] && map[i + 1][j]
        && map[i - 1][j] == '1' && map[i + 1][j] == '1')
}


int check_top_line(char *line, char *bottom){
    int i;

    if(!line)
        return (0);
    i = 0;
    while(line[i]){
        if(line[i] == '0') 
            return (0);
        else if(line[i] == ' ' && bottom[i] == '0')
            return (0);
        i++;
    }
    return (1);
}

int check_map(char **map)
{
    
    int i;
    char *trimed;

    i = 0;
    while(map[i]){
        trimed = ft_strtrim(map[i], ' ');
        
        i++;
    }

}