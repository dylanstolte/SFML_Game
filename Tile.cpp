#include "Tile.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "SFML/Graphics.hpp"
#include <iostream>

//Tile::Tile(sf::Texture& texture,TextureManager* texturemanager){
//baseSprite.setTexture(texture);
//}

Tile::Tile(TextureManager*  texturemanager, int picNum){
baseSprite.setTexture(texturemanager->GetTexture(picNum));
treeSprite.setTexture(texturemanager->GetTexture(4));
treeSprite.scale(1.4,1.4);
  /* generate secret number between 1 and 700: */
randomx = rand() % 700 + 1;
randomy = rand() % 700 + 1;
randomx1 = rand() % 700 + 1;
randomy1 = rand() % 700 + 1;
randomx2 = rand() % 700 + 1;
randomy2 = rand() % 700 + 1;
randomvar = rand () % 6 + 1;
source.y = 0;
source.x = 0;
}

Tile::~Tile(){
    delete texturemanager;
}

void Tile::Draw(int x, int y, sf::RenderWindow* rw){
baseSprite.setPosition(x, y);
rw->draw(baseSprite);
}

void Tile::Draw(int x, int y, sf::RenderWindow* rw,TextureManager* texturemanager){
Draw(x,y,rw);



treeSprite.setTextureRect(sf::IntRect(source.x * 80, source.y * 80,80, 80));

treeSprite.setPosition(x + randomx,y + randomy);
rw->draw(treeSprite);

//treeSprite.setTextureRect(sf::IntRect(source.x* 80, source.y * 80,80, 80));
//
//treeSprite.setPosition(x + randomx1  ,y + randomy1);
//rw->draw(treeSprite);

//treeSprite.setTextureRect(sf::IntRect(source.x * 80, ((source.y + randomvar >= 10) ? source.y = 10 : source.y + randomvar) * 80,80, 80));
//
//treeSprite.setPosition(x + randomx2  ,y + randomy2);
//rw->draw(treeSprite);
}
