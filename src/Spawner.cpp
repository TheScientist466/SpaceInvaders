#include "Headers/Spawner.h"

#include <random>
#include <iostream>
#include "Config/Config.h"

Spawner::Spawner()
{
	
}

Spawner::Spawner(std::vector<Enemy*>* _enemies)
{
	Spawner();
	enemies = _enemies;
	difficulty = Config::Enemy::SpawnTimePeriod;
	ctr = Config::Enemy::SpawnDifficultyRate;
	spawnEnemy();
	clk.restart();
}

void Spawner::update()
{
	float time = clk.getElapsedTime().asSeconds();
	if(time >= difficulty)
	{
		spawnEnemy();
		ctr--;
		clk.restart();
	}

	if(ctr <= 0)
	{
		ctr = Config::Enemy::SpawnDifficultyRate;
		difficulty -= 0.1;
		if(difficulty <= 0.4)
		{
			difficulty = Config::Enemy::SpawnTimePeriod;
			wave++;
		}
	}
}

void Spawner::spawnEnemy()
{
	for(unsigned int i = 0; i < wave; i++)
	{
		int moveSpeed = rand() % (Config::WindowConfig::windowDimentions.x - 2 * Config::Enemy::TextureSize.x) + Config::Enemy::TextureSize.x;
		Enemy* e = new Enemy(sf::Vector2f(moveSpeed, -100));
		enemies->push_back(e);
	}
}