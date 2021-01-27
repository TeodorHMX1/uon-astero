#include "bullet.h"

bulletBean::bulletBean()
{}

bulletBean::~bulletBean()
{}

bulletObject::bulletObject()
{

    x = 0;
    y = 0;
    width = 24;
    height = 24;
    frame = 0;

    bulletSpawnTime = 0.5;
    bulletSpeed = 7;

    bulletSprite = GRRLIB_LoadTexture(blast_png);

}

bulletObject::~bulletObject()
{}

void bulletObject::draw(int _x, int _y, int _frame, GRRLIB_texImg *bulletSprite)
{

    if (bulletSprite == nullptr)
    {
        GRRLIB_Rectangle(_x, _y, width, height, GRRLIB_WHITE, 0);
    } else
    {
        GRRLIB_InitTileSet(bulletSprite, width, height, 0);
        GRRLIB_DrawTile(_x, _y, bulletSprite, 0, 1, 1, GRRLIB_WHITE, 0);
    }

}