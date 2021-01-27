#pragma once

// include external headers
#include <iostream>
#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>

class scoreBean
{
public:
    scoreBean(GRRLIB_ttfFont *_font);

    ~scoreBean();

    int updateScore();

    void drawText();

    void onGameOver();

public:
    GRRLIB_ttfFont *font;

private:
    int pScore, pHighScore;

};