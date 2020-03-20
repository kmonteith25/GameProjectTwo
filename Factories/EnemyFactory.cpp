#include "EnemyFactory.h"


Character* EnemyFactory::randomEnemy(float x, float y) {
	srand(time(NULL));
	int randomItem = rand() % 10;
	Character* character_placeholder;
	
	switch (5) {
	case 0:
		character_placeholder = new FireChicken(x,y);
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