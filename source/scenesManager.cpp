#include "scenesManager.h"

scenesManager::scenesManager()
{
    zPlayer = new playerBean(300, 400, 24, 24);
    zEntities = new entitySpawn();
    menuTex = GRRLIB_LoadTexture(bgGameScene_png);
    zScore = new scoreBean(zFonts.fontM);
    currentLevel = menuScene;
    currentTime = 0;
    timeLimit = 60;
}

scenesManager::~scenesManager()
{
    delete zPlayer->pBullet;
    delete zPlayer;
    delete zEntities;
    delete zScore;
}

void scenesManager::setCurrentLevel(levels level)
{
    currentLevel = level;
}

void scenesManager::drawScene()
{

    switch (currentLevel)
    {
        case menuScene:
            drawStartMenu();
            break;
        case gameScene:
            drawLevel1();
            break;
    }

}

void scenesManager::drawStartMenu()
{

    zMenuScene.drawMenu();
    if (PAD_ButtonsHeld(0) & PAD_BUTTON_A)
    {
        currentLevel = gameScene;
    }

}

void scenesManager::drawLevel1()
{

    GRRLIB_InitTileSet(menuTex, 640, 528, 0);
    GRRLIB_DrawTile(0, 0, menuTex, 0, 1, 1, GRRLIB_WHITE, 0);
    if (zPlayer->isGameEnd())
    {
        zEntities->enemies.clear();
        GRRLIB_PrintfTTF(125, 190, zFonts.fontM, "GAME OVER! PRESS 'X' TO RESTART", 32, 0xFFFFFFFF);
        GRRLIB_PrintfTTF(180, 230, zFonts.fontM, "PRESS 'B' TO RETURN TO MENU", 26, 0xFFFFFFFF);
        zScore->drawText();

        if (PAD_ButtonsHeld(0) & PAD_BUTTON_X)
        {
            zPlayer->setGameStatus(false);
        } else if (PAD_ButtonsDown(0) & PAD_BUTTON_B)
        {
            currentLevel = menuScene;
            zPlayer->setGameStatus(false);
        }
    } else if (zPauseScene.isGamePaused())
    {
        zPlayer->draw(zFonts.fontM);
        zEntities->draw();
        zPauseScene.displayText();
        zScore->drawText();

        if (PAD_ButtonsDown(0) & PAD_BUTTON_B)
        {
            zPauseScene.setStatus(false);
        }
    } else
    {
        zPlayer->move();
        zPlayer->bulletMove();
        zEntities->spawnEnemy();
        zEntities->draw();
        zScore->drawText();

        if (PAD_ButtonsDown(0) & PAD_BUTTON_B)
        {
            zPauseScene.setStatus(true);
        }

        currentTime++;
        if (currentTime == timeLimit)
        {
            zScore->updateScore();
            currentTime = 0;
        }
        zPlayer->bulletCollision(zEntities->enemies);
        zPlayer->draw(zFonts.fontM);
        if (zEntities->checkGameLost())
        {
            zPlayer->setGameStatus(true);
            zScore->onGameOver();
        }
    }

}

void scenesManager::freeTextures()
{
    GRRLIB_FreeTexture(zPlayer->playerSprite);
    GRRLIB_FreeTexture(zPlayer->pBullet->bulletSprite);
    GRRLIB_FreeTTF(zScore->font);
    GRRLIB_FreeTexture(zMenuScene.menuTex);
}