#include "stdafx.h"
#include <iostream>
#include "GameLogic.h"
#include "System.h"
#include "World.h"
#include "Player.h"

GameLogic::GameLogic(World& world)
	:m_world(world)
{

}


GameLogic::~GameLogic()
{
}

void GameLogic::processInput()
{

	if (!System::keyHit())
		return; //no keyboard event to be processed


	while (System::keyHit())
	{
		char c = System::getNextKey();
		switch (c)
		{
		case 'w':
			World::getInstance()->getPlayer(1).moveUp(); break;
		case 's':
			World::getInstance()->getPlayer(1).moveDown(); break;
		case 'd':
			World::getInstance()->getPlayer(1).moveRight(); break;
		case 'a':
			World::getInstance()->getPlayer(1).moveLeft(); break;
		case '8':
			World::getInstance()->getPlayer(2).moveUp(); break;
		case '2':
			World::getInstance()->getPlayer(2).moveDown(); break;
		case '6':
			World::getInstance()->getPlayer(2).moveRight(); break;
		case '4':
			World::getInstance()->getPlayer(2).moveLeft(); break;
		case 27:
			//'Esc' key pressed. Exit the game
			exit(0);
		}
	}
}

bool GameLogic::gameHasEnded()
{
	/*if ((m_world.pointsP1 + m_world.pointsP2) == m_world.numCoins) {
		return true;
	}*/
	return false;
}