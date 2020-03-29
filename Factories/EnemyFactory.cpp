#include "EnemyFactory.h"

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


Character* EnemyFactory::randomEnemy(float x, float y, GameMap* gamemap) {
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int randomItem = rand() % 10;
	Character* character_placeholder;
	
	switch (0) {
	case 0:
		character_placeholder = new FireChicken(x,y,gamemap);
		break;
	case 1:
		character_placeholder = new CollegeStudent(x, y);
		break;
	case 2:
		character_placeholder = new Block(x, y);
		break;
	case 3:
		character_placeholder = new Dumb(x, y);
		break;
	case 4:
		character_placeholder = new Fish(x, y);
		break;
	case 5:
		character_placeholder = new FishTwo(x, y);
		break;
	case 6:
		character_placeholder = new FlyingRodent(x, y);
		break;
	case 7:
		character_placeholder = new GhostMan(x, y);
		break;
	case 8:
		character_placeholder = new HairlessCat(x, y);
		break;
	case 9:
		character_placeholder = new HappyFace(x, y);
		break;
	case 10:
		character_placeholder = new Rodent(x, y);
		break;
	case 11:
		character_placeholder = new Trash(x, y);
		break;
	default:
		character_placeholder = new CollegeStudent(x, y);
		break;
	}
	return character_placeholder;
}