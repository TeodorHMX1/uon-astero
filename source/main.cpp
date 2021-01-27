// include external headers
#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>
#include <asndlib.h>
#include <mp3player.h>

// include generated headers
#include "gameSound_mp3.h"

// include project headers
#include "scenesManager.h"

#define GRRLIB_BLACK 0x000000FF

int main()
{
    // initialise controller library
    PAD_Init();
    GRRLIB_Init();

    // initialise audio
    ASND_Init();
    MP3Player_Init();

    // initialise the scene manager
    scenesManager *zScenesManager = new scenesManager();
    // set the starting scene to stratScene
    zScenesManager->setCurrentLevel(zScenesManager->menuScene);

    MP3Player_PlayBuffer(gameSound_mp3, gameSound_mp3_size, NULL);

    while (true)
    {
        GRRLIB_FillScreen(GRRLIB_BLACK);
        PAD_ScanPads();

        zScenesManager->drawScene();

        GRRLIB_Render();
    }

    // destroy elements on exit
    GRRLIB_Exit();
    zScenesManager->freeTextures();
    delete zScenesManager;

    return 0;
}