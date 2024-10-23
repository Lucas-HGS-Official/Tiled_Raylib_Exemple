#include <stdio.h>
#include "raylib.h"

#define CUTE_TILED_IMPLEMENTATION
#include "cute_tiled.h"


int main(int argc, char const *argv[])
{
    cute_tiled_map_t* map = cute_tiled_load_map_from_file("../data/export/basic.json", NULL);


    printf("%d\n", map->height);
    
    return 0;
}
