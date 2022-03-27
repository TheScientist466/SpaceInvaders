#pragma once

#include <vector>

#include "Enemy.h"

class Spawner
{
public:
	Spawner();
	Spawner(std::vector<Enemy*>* enemiesVector);
	
private:
	std::vector<Enemy*>* enemies;
	sf::Clock clk;
	float difficulty;
	int ctr;
	unsigned int wave = 1;
	
public:
	void update();
	void spawnEnemy();
};