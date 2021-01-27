#pragma once

// include external headers
#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>

// include generated headers
#include "blast_png.h"

#define GRRLIB_WHITE     0xFFFFFFFF

class bulletBean
{

public:
    float x, y, width, height;
    GRRLIB_texImg *bulletSprite;
    int bulletSpeed;
    float bulletSpawnTime;
    int frame;

    bulletBean();

    ~bulletBean();

};

class bulletObject : public bulletBean
{

public:
    bulletObject();

    ~bulletObject();

    void draw(int _x, int _y, int _frame, GRRLIB_texImg *_bulletSprite);

};