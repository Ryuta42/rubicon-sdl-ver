#include "enemySpawner.hpp"

using namespace std;

EnemySpawner::EnemySpawner()
{}
EnemySpawner::EnemySpawner(int minSpawnY, int maxSpawnY)
{
    spawnMinTime = 0.1;
    spawnMaxTime = 0.7;
    this->minSpawnY = minSpawnY;
    this->maxSpawnY = maxSpawnY;
    currentTime = spawnTime = 0;
    wave = spawnCredits = 0;
    waveTime = wave * 5.0;
    spawnNextTime = grf(spawnMinTime, spawnMaxTime);
}
EnemySpawner::~EnemySpawner()
{
    // enemies cleanup
    for (vector<Enemy*>::iterator p = enemies.begin(); p != enemies.end(); ++p)
    {
        delete *p;                              // destroy all enemies
        *p = nullptr;
    }
    enemies.clear();

    // activeEnemies cleanup
    for (list<Enemy*>::iterator p = activeEnemies.begin(); p != activeEnemies.end(); ++p)
        *p = nullptr;
    activeEnemies.clear();
}
int EnemySpawner::wave = 0;

void EnemySpawner::spawn(int id)
{
    int x = SCREEN_WIDTH;
    int y = gri(minSpawnY, maxSpawnY);
    for (vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++)
    {
        if (!(*it)->isActive && (*it)->enemyID == id)              // if there is an inactive enemy
        {
            (*it)->activate(x, y);         // respawn
            activeEnemies.push_back(*it);
            return;
        }
    }

    // create new enemy
    Enemy *newEnemy;
    if (id == ENEMY_POD)
        newEnemy = new Pod(x,y);
    else if (id == ENEMY_DRONE)
        newEnemy = new Drone(x, y);
    enemies.push_back(newEnemy);                        // add new enemy to enemy pool
    activeEnemies.push_back(newEnemy);
}
void EnemySpawner::update()
{
    currentTime += timer.delta;

    // advance to next wave
    if (currentTime >= waveTime || activeEnemies.size() == 0)
    {
        currentTime = 0;
        wave ++;
        spawnCredits = wave * 2;
        waveTime = wave * 2.5;
        spawnNextTime = 0;
        spawning = true;
    }

    // if spawning new wave
    if (spawning)
    {
        spawnTime += timer.delta;
        if (spawnTime >= spawnNextTime)
        {
            spawnTime = 0;
            spawnNextTime = grf(spawnMinTime, spawnMaxTime);

            if (spawnCredits >= 7)                  // spawn another enother enemy
            {
                int i = gri(0,2);
                if (i == 0)
                {
                    spawn(ENEMY_DRONE);
                }
                else
                {
                    spawn(ENEMY_POD);
                    spawn(ENEMY_POD);
                    spawn(ENEMY_POD);
                }
                spawnCredits -= 3;
            }
            else if (spawnCredits >= 1)
            {
                spawn(ENEMY_POD);
                spawnCredits -= 1;
            }
        }

        if (spawnCredits <= 0)
            spawning = false;
    }

    // update active enemies
    for (list<Enemy*>::iterator it = activeEnemies.begin(); it != activeEnemies.end(); ++it)
    {
        if ((*it)->isActive)
            (*it)->update();
        else
            activeEnemies.erase(it);
    }
}
void EnemySpawner::draw()
{
    for (list<Enemy*>::iterator it = activeEnemies.begin(); it != activeEnemies.end(); ++it)
        (*it)->draw();
}
