#include "menuSceneModel.h"

menu::menu()
{
    menuTex = GRRLIB_LoadTexture(startMenu_png);
}

menu::~menu()
{}

void menu::drawMenu()
{
    GRRLIB_InitTileSet(menuTex, 640, 528, 0);
    GRRLIB_DrawTile(0, 0, menuTex, 0, 1, 1, GRRLIB_WHITE, 0);
    GRRLIB_PrintfTTF(155, 100, fonts.fontM, "PRESS 'A' TO START", 48, 0xFFFFFFFF);
    GRRLIB_PrintfTTF(120, 210, fonts.fontM, "Movement: 'D-PAD'", 32, 0xFFFFFFFF);
    GRRLIB_PrintfTTF(120, 250, fonts.fontM, "Shoot: 'A'", 32, 0xFFFFFFFF);
    GRRLIB_PrintfTTF(120, 290, fonts.fontM, "Pause: 'B'", 32, 0xFFFFFFFF);
    GRRLIB_PrintfTTF(170, 400, fonts.fontM, "Objective: defend the ground line", 24, 0xFFFFFFFF);
}

pause::pause()
{}

pause::~pause()
{}

void pause::displayText()
{
    GRRLIB_PrintfTTF(200, 210, fonts.fontM, "GAME IS PAUSED", 40, 0xFFFFFFFF);
    GRRLIB_PrintfTTF(230, 270, fonts.fontM, "Press 'B' to resume", 24, 0xFFFFFFFF);
}

void pause::setStatus(bool isPaused)
{
    this->isPaused = isPaused;
}

bool pause::isGamePaused()
{
    return isPaused;
}

