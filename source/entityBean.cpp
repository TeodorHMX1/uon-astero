#include "entityBean.h"

//enemy
enemyBean::enemyBean(float _x, float _y, float _width, float _height)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    moveSpeed = 1;
    srand(time(NULL));
    int spriteChance = rand() % 30;
    if (spriteChance % 3 == 0)
    {
        enemySprite = GRRLIB_LoadTexture(alienPurple_png);
    } else if (spriteChance % 3 == 1)
    {
        enemySprite = GRRLIB_LoadTexture(alienPink_png);
    } else if (spriteChance % 3 == 2)
    {
        enemySprite = GRRLIB_LoadTexture(alienBlue_png);
    }
}

enemyBean::~enemyBean()
{}


void enemyBean::draw(int _x, int _y, float width, float height)
{
    GRRLIB_InitTileSet(enemySprite, width, height, 0);
    GRRLIB_DrawTile(_x, _y, enemySprite, 0, 2, 2, GRRLIB_WHITE, 0);
}

//player
playerBean::playerBean(float _x, float _y, float _width, float _height)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    moveSpeed = 5;
    pBullet = new bulletObject;
    start = 0;
    pBullet->x = x + 16;
    pBullet->y = y + 16;
    isGameOver = false;

    playerSprite = GRRLIB_LoadTexture(ship_png);
}

playerBean::~playerBean()
{
    // delete bullets;
    //delete pbullet;
}

void playerBean::move()
{

    if (x > 560)
    {
        x = 560;
    } else if (x - width < 0)
    {
        x = 0 + width;
    }

    if (PAD_ButtonsHeld(0) & PAD_BUTTON_RIGHT)
    {
        x += moveSpeed;

    } else if (PAD_ButtonsHeld(0) & PAD_BUTTON_LEFT)
    {
        x -= moveSpeed;
    }
    if (PAD_ButtonsHeld(0) & PAD_BUTTON_A)
    {
        if (start == 0)
        {
            pBullet->x = x + 12;
            pBullet->y = y - 16;
            bullets.push_back(*pBullet);
            start += 1;
        }
    }
    if (start > 0 && start <= 25)
    {
        start++;
    } else if (start >= 25)
    {
        start = 0;
    }

}

void playerBean::bulletCollision(std::vector <enemyBean> &enemy)
{
    for (size_t i = 0; i < bullets.size(); i++)
    {
        for (size_t j = 0; j < enemy.size(); j++)
        {
            if (bullets[i].x + bullets[i].width > enemy[j].x && bullets[i].x < enemy[j].x + (enemy[j].width * 2) &&
                bullets[i].y + bullets[i].height > enemy[j].y && bullets[i].y < enemy[j].y + (enemy[j].height * 2))
            {
                enemy.erase(enemy.begin() + j);
                bullets.erase(bullets.begin() + i);
            }
        }
    }
}

void playerBean::draw(GRRLIB_ttfFont *text)
{
    if (playerSprite != nullptr)
    {
        GRRLIB_InitTileSet(playerSprite, width, height, 0);
        GRRLIB_DrawTile(x, y, playerSprite, 0, 2, 2, GRRLIB_WHITE, 0);
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {

        bullets[i].draw(bullets[i].x, bullets[i].y, bullets[i].frame, bullets[i].bulletSprite);
        if (bullets[i].y <= 0)
        {
            bullets.erase(i + bullets.begin());
        }
    }
}

void playerBean::bulletMove()
{
    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].y -= bullets[i].bulletSpeed;
    }
}

void playerBean::setGameStatus(bool isOver)
{
    this->isGameOver = isOver;
}

bool playerBean::isGameEnd()
{
    return this->isGameOver;
}