#include "entitySpawner.h"

entitySpawn::entitySpawn()
{
    spawnPointX[0] = 20;
    spawnPointX[1] = 188;
    spawnPointX[2] = 345;
    spawnPointX[3] = 400;
    spawnPointX[4] = 460;
    spawnPointY = -20;
    spawnTime = 0;
    randX = 0;
}

entitySpawn::~entitySpawn()
{}

void entitySpawn::spawnEnemy()
{
    srand(time(NULL));
    int spawnTimeLimit = 60;
    if (spawnTime <= 0)
    {
        enemy = new enemyBean(rand() % 400 + 50, spawnPointY, 16.0, 16.0);
        enemy->randAngle = 0;
        enemy->hitRight = false;
        enemy->hitLeft = false;
        enemy->randAngle = rand() % 3;
        enemy->x = rand() % 400 + 50;
        enemy->y = spawnPointY;
        enemies.push_back(*enemy);
        spawnTime++;
    }
    if (spawnTime > 0 && spawnTime < spawnTimeLimit)
    {
        spawnTime++;
    } else if (spawnTime >= spawnTimeLimit)
    {
        spawnTime = 0;
        randX = rand() % 5;
    }

    for (size_t i = 0; i < enemies.size(); i++)
    {
        if (randX == 0 || enemies[i].y <= 0)
        {
            enemies[i].x += cos(enemies[i].randAngle) * enemies[i].moveSpeed;
        } else if (randX == 2 || enemies[i].y >= 375)
        {
            enemies[i].x -= cos(enemies[i].randAngle) * enemies[i].moveSpeed;
        }
        enemies[i].y += enemy->moveSpeed;
    }
}

bool entitySpawn::checkGameLost()
{

    size_t i = 0;
    bool lost = false;
    while (i < enemies.size() && !lost)
    {
        if (enemies[i].y > 440)
        {
            lost = true;
        }
        i++;
    }
    return lost;

}

void entitySpawn::draw()
{
    for (size_t i = 0; i < enemies.size(); i++)
    {
        enemies[i].draw(enemies[i].x, enemies[i].y, enemies[i].width, enemies[i].height);
        if (enemies[i].y > 500)
        {
            enemies.erase(i + enemies.begin());
        }
    }
}