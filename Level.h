#ifndef _LEVEL_H
#define _LEVEL_H

#include <vector>
#include "Tile.h"

class Level
{
private:
	//A 2D array of Tile pointers
	std::vector<std::vector<Tile*> > map;

	//Width and height of level (in tiles)
	int w;
	int h;

	void SetDimensions(int w, int h);

public:
	Level(int w, int h);
	~Level();

	void AddTile(int x, int y, Tile* tile);
	Tile* GetTile(int x, int y);

	void LoadLevel();

	int GetWidth();
	int GetHeight();
};

#endif


