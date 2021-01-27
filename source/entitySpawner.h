#pragma once

// include external headers
#include <cstdlib>
#include <chrono>
#include <math.h>
#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>

// include project headers
#include "entityBean.h"

class entitySpawn
{

public:
    entitySpawn();

    ~entitySpawn();

    void spawnEnemy();

    void draw();

    bool checkGameLost();

public:
    std::vector <enemyBean> enemies;
    enemyBean *enemy;
    float spawnPointX[5];
    float spawnPointY;
    int spawnTime;
    int randX;

};