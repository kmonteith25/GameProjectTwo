#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../GameMap.h"
class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory();
	static Character* randomEnemy(float x, float y,GameMap* gamemap);
private:
};


