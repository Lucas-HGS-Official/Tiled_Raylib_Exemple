#include <stdio.h>
#include "raylib.h"

#define CUTE_TILED_IMPLEMENTATION
#include "cute_tiled.h"


int main(int argc, char const *argv[])
{
    cute_tiled_map_t* map = cute_tiled_load_map_from_file("../data/export/basic.json", NULL);
    cute_tiled_layer_t* layer = map->layers;

    int i = 0, j = 0, aux = 0, x = 0;


    for(x = 0; x < layer->height * layer->width; x++) {

        aux = 1;

        for (i = 0; i < 13; i++) {
            for (j = 0; j < 23; j++) {

                if (aux == 97) {
                    printf("%d | %d   %d | %d\n", x, aux, j, i);
                }


                // if (aux == layer->data[x]) {
                    
                //     // printf("\nx = %d with data = %d at j(x) = %d and i(y) = %d", x, layer->data[x], j, i);
                    
                //     break;
                // }
        

                aux++;
            }
            if (aux == layer->data[x]) {
                break;
            }
        }
    }


    return 0;
}

// int main(void)
// {
//     // Initialization
//     //--------------------------------------------------------------------------------------
//     const int screenWidth = 1366;
//     const int screenHeight = 768;

//     InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

//     SetTargetFPS(3);               // Set our game to run at 60 frames-per-second
//     //--------------------------------------------------------------------------------------

//     cute_tiled_map_t* map = cute_tiled_load_map_from_file("../data/export/basic.json", NULL);
//     cute_tiled_layer_t* layer = map->layers;

//     Texture2D tilemapTexture = LoadTexture("../graphics/tilesets/tiles.png");
//     // TODO: Correct the X and Y of the srcTilemapRec
    

//     int numColsTilesInTilemapTexture = (tilemapTexture.width / map->tilewidth); // 23
//     int numRowsTilesInTilemapTexture = (tilemapTexture.height / map->tileheight); // 13

//     Rectangle srcTilemapRec = { 0, 0, map->tilewidth, map->tileheight };
//     Rectangle destTilemapRec = { 0, 0, map->tilewidth, map->tileheight };
//     Vector2 tileOrigin = { 0, 0 };

//     int i = 0, j = 0, aux = 0, x = 0;


//     // Main game loop
//     while (!WindowShouldClose())    // Detect window close button or ESC key
//     {
//         // Update
//         //----------------------------------------------------------------------------------


//         // TODO: Update your variables here
//         //----------------------------------------------------------------------------------


//         BeginDrawing();

//             ClearBackground(RAYWHITE);

//             for(x = 0; x < layer->height * layer->width; x++) {

//                 aux = 1;

//                 for (i = 0; i < numRowsTilesInTilemapTexture-1; i++) {
//                     for (j = 0; j < numColsTilesInTilemapTexture-1; j++) {

//                         if (aux == layer->data[x]) {
//                             srcTilemapRec.x = j * map->tilewidth;
//                             srcTilemapRec.y = i * map->tileheight;

                        
//                             printf("\n%d | %d\n\n", i, j);

//                             // Draw
//                             //----------------------------------------------------------------------------------


//                                 DrawTexturePro(tilemapTexture, srcTilemapRec, destTilemapRec, tileOrigin, 0.f, WHITE);


//                             //----------------------------------------------------------------------------------

                            
//                             if (destTilemapRec.y >= screenHeight) {
//                                 destTilemapRec.y = 0;
//                             }
//                             aux = 1;
//                         }
                        

//                         aux++;
//                     }
//                     if (aux == layer->data[x]-1) {
//                         destTilemapRec.x += map->tilewidth;
//                         if (destTilemapRec.x >= screenWidth) {
//                             destTilemapRec.x = 0;
//                             destTilemapRec.y += map->tileheight;
//                         }
//                     }

//                     aux++;
//                 }
//             }
        
//             DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

//         EndDrawing();
//     }

//     // De-Initialization
//     //--------------------------------------------------------------------------------------
//     printf("\n\n%d | %d\n", numColsTilesInTilemapTexture, numRowsTilesInTilemapTexture);
//     UnloadTexture(tilemapTexture);
//     CloseWindow();        // Close window and OpenGL context
//     //--------------------------------------------------------------------------------------

//     return 0;
// }