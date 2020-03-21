#pragma once

#include "../Entities/Characters/ComputerPlayers/Enemies/FireChicken.h"
#include "../Entities/Characters/ComputerPlayers/Enemies/CollegeStudent.h"
#include "../Entities/Characters/ComputerPlayers/Enemies/Block.h"
#include "../Entities/Characters/ComputerPlayers/Enemies/Dumb.h"
#include "../Entities/Characters/ComputerPlayers/Enemies/Fish.h"
#include "../Entities/Characters/ComputerPlayers/Enemies/FishTwo.h"
#include "../Entities/Characters/ComputerPlayers/Enemies/FlyingRodent.h"
#include "../Entities/Characters/ComputerPlayers/Enemies/GhostMan.h"
#include "../Entities/Characters/ComputerPlayers/Enemies/HairlessCat.h"
#include "../Entities/Characters/ComputerPlayers/Enemies/HappyFace.h"
#include "../Entities/Characters/ComputerPlayers/Enemies/Rodent.h"
#include "../Entities/Characters/ComputerPlayers/Enemies/Trash.h"
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


