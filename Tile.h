#ifndef TILE_H
#define TILE_H

#include "TextureManager.h"
#include <SFML/Graphics.hpp>

class Tile{
private:
sf::Sprite baseSprite;
sf::Sprite treeSprite;

int randomx;
int randomy;
int randomx1;
int randomy1;

public:
Tile(sf::Texture& texture);
~Tile();
TextureManager* texturemanager;
sf::Vector2i source;

void Draw(int x, int y, sf::RenderWindow* rw);
void Draw(int x, int y, sf::RenderWindow* rw,TextureManager* texturemanager);
};
#endif

