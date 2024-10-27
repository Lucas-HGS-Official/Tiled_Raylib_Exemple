#include <stdio.h>
#include "raylib.h"

#define CUTE_TILED_IMPLEMENTATION
#include "cute_tiled.h"


// int main(int argc, char const *argv[])
// {


//     printf("%d\n", layer->data[1119]);
    
//     return 0;
// }

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1366;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    cute_tiled_map_t* map = cute_tiled_load_map_from_file("../data/export/basic.json", NULL);
    cute_tiled_layer_t* layer = map->layers;

    Texture2D tilemapTexture = LoadTexture("../graphics/tilesets/tiles.png");
    // TODO: Correct the X and Y of the srcTilemapRec
    

    int numColsTilesInTilemapTexture = (tilemapTexture.width / map->tilewidth) - 1;
    int numRowsTilesInTilemapTexture = (tilemapTexture.height / map->tileheight) - 1;

    Rectangle srcTilemapRec = { 0, 0, map->tilewidth, map->tileheight };
    Rectangle destTilemapRec = { 0, 0, map->tilewidth, map->tileheight };
    Vector2 tileOrigin = { 0, 0 };

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        
        


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            int i = 0, j = 0, aux = 0, x = 0;

            for (x = 0; x < layer->height * layer->width; x++) {

                for (i = 0; i < numRowsTilesInTilemapTexture; i++) {
                    for (j = 0; j < numColsTilesInTilemapTexture; j++) {

                        if (aux == layer->data[0]-1) {
                            srcTilemapRec.x = j * map->tilewidth;
                            srcTilemapRec.y = i * map->tileheight;

                            printf("\n%d\n\n", layer->data[0]);

                            DrawTexturePro(tilemapTexture, srcTilemapRec, destTilemapRec, tileOrigin, 0.f, WHITE);

                            // destTilemapRec.x += map->tilewidth;
                            // if (destTilemapRec.x >= layer->width * map->tilewidth) {
                            //     destTilemapRec.x = 0;
                            //     destTilemapRec.y += map->tileheight;
                            // }
                            // if (destTilemapRec.y >= layer->height * map->tileheight) {
                            //     destTilemapRec.y = 0;
                            // }

                        }

                        aux++;
                    }
                    aux++;
                }
            }


            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(tilemapTexture);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}