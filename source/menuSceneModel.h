#pragma once

// include external headers
#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>

// include generated headers
#include "startMenu_png.h"

// include project headers
#include "fontManager.h"

#define GRRLIB_WHITE 0xFFFFFFFF

class menuSceneModel
{
public:
    menuSceneModel()
    {}

    ~menuSceneModel()
    {}

    fontManager fonts;

};

class menu : public menuSceneModel
{

public:
    menu();

    ~menu();

    void drawMenu();

public:
    GRRLIB_texImg *menuTex;

};

class pause : public menuSceneModel
{

public:
    pause();

    ~pause();

    void displayText();

    void setStatus(bool isPaused);

    bool isGamePaused();

private:
    bool isPaused;

};