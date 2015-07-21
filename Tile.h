#ifndef TILE_H
#define TILE_H

#include "TextureManager.h"
#include <SFML/Graphics.hpp>

class Tile{
public:
sf::Sprite baseSprite;
sf::Sprite treeSprite;

int randomx;
int randomy;
int randomx1;
int randomy1;
int randomx2;
int randomy2;
int randomvar;

Tile(TextureManager* texturemanager, int picNum);
~Tile();
TextureManager* texturemanager;
sf::Vector2i source;

void Draw(int x, int y, sf::RenderWindow* rw);
void Draw(int x, int y, sf::RenderWindow* rw,TextureManager* texturemanager);
};
#endif

