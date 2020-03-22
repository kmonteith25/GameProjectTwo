#pragma once


#include "../Entities/Characters/Character.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory();
	static Character* randomEnemy(float x, float y);
private:
};


