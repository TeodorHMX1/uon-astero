#pragma once

// include external headers
#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>

// include generated headers
#include "bgGameScene_png.h"

// include project headers
#include "menuSceneModel.h"
#include "entityBean.h"
#include "scoreBean.h"
#include "bullet.h"
#include "entitySpawner.h"
#include "fontManager.h"

class scenesManager
{

public:
    enum levels
    {
        menuScene,
        gameScene
    } currentLevel;

public:
    scenesManager();

    ~scenesManager();

    void drawScene();

    void drawStartMenu();

    void drawLevel1();

    void setCurrentLevel(levels level);

    void freeTextures();

public:
    playerBean *zPlayer;
    entitySpawn *zEntities;
    fontManager zFonts;
    scoreBean *zScore;
    menu zMenuScene;
    pause zPauseScene;

private:
    int currentTime;
    int timeLimit;
    GRRLIB_texImg *menuTex;

};