#pragma once
#include "NumSet.h"
class Game
{
	NumSet _p1;
	NumSet _p2;
	int strategy;
public:
	Game(int strategy) {
	
		this->strategy = strategy;
	}
	void playerVScomp();
	void playerVSplayer();
	void  compVScomp();
	void winner();
	void menu();
};

