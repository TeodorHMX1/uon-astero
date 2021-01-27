#include "scoreBean.h"

scoreBean::scoreBean(GRRLIB_ttfFont *_font)
{

    font = _font;
    pScore = 0;
    pHighScore = 0;

}

scoreBean::~scoreBean()
{}

int scoreBean::updateScore()
{
    return ++pScore;
}

void scoreBean::drawText()
{

    char strScore[32];
    char strHighScore[32];

    // sprintf deprecated (to use sprintf_s) but it is not
    // available in the compiler's c++ language version
    sprintf(strScore, "%d", pScore);
    sprintf(strHighScore, "%d", pHighScore);

    GRRLIB_PrintfTTF(50, 0, font, "SCORE:", 32, 0xFFFFFFFF);
    GRRLIB_PrintfTTF(150, 0, font, strScore, 32, 0xFFFFFFFF);

    GRRLIB_PrintfTTF(50, 40, font, "HIGH SCORE:", 32, 0xFFFFFFFF);
    GRRLIB_PrintfTTF(205, 40, font, strHighScore, 32, 0xFFFFFFFF);

}

void scoreBean::onGameOver()
{
    if (pScore > pHighScore)
    {
        pHighScore = pScore;
    }
    pScore = 0;
}
