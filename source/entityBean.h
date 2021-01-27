#pragma once

// include external headers
#include <iostream>
#include <vector>
#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>
#include "time.h"

// include generated headers
#include "ship_png.h"
#include "alienPurple_png.h"
#include "alienPink_png.h"
#include "alienBlue_png.h"

// include project headers
#include "bullet.h"

class entityBean
{

public:

    entityBean()
    {}

    ~entityBean()
    {}

    float x, y, width, height;
    float moveSpeed;
    int start;

    std::vector <bulletObject> bullets;
    bulletObject *pBullet;

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int getWidth()
    {
        return width;
    }

    int getHeight()
    {
        return height;
    }


};

class enemyBean : public entityBean
{

public:
    int randAngle;
    bool hitLeft;
    bool hitRight;
    GRRLIB_texImg *enemySprite;

    enemyBean(float _x, float _y, float _width, float _height);

    ~enemyBean();

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int getWidth()
    {
        return width;
    }

    int getHeight()
    {
        return height;
    }

    void draw(int _x, int _y, float width, float height);

};

class playerBean : public entityBean
{
public:
    GRRLIB_texImg *playerSprite;

    playerBean(float _x, float _y, float _width, float _height);

    ~playerBean();

    void move();

    void draw(GRRLIB_ttfFont *text);

    void bulletMove();

    void bulletCollision(std::vector <enemyBean> &enemy);

    void setGameStatus(bool isOver);

    bool isGameEnd();

private:
    bool isGameOver;

};