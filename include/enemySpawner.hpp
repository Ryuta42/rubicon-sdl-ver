#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include <list>
#include <string>
#include <vector>

#include "util.hpp"
#include "pod.hpp"
#include "drone.hpp"
#include "enemy.hpp"

class EnemySpawner
{
public:
    EnemySpawner();
    EnemySpawner(int minSpawnY, int maxSpawnY);
    ~EnemySpawner();

    void update();                          // update enemy positions
    void draw();                            // draw all active enemies

private:
    int minSpawnY;
    int maxSpawnY;
    float spawnMinTime;
    float spawnMaxTime;
    float spawnNextTime;
    float currentTime;
    float spawnTime;
    std::vector<Enemy*> enemies;            // pool of all enemies
    std::list<Enemy*> activeEnemies;        // list of enemies on screen
    int spawnCredits;
    float waveTime;                         // max time current wave allows
    bool spawning = false;;                 // in the process of spawning wave

    void spawn(int enemyID);

    static int wave;

friend class Stage;
friend class GameOver;
friend class Score;
};

#endif // ENEMYSPAWNER_H
