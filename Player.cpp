#include <SFML\Graphics.hpp>
#include <math.h>

#include "Player.h"
#include "Engine.h"
#include "Level.h"

Player::Player()//sf::Texture& texture)
{

	texture.loadFromFile("solider_sprite.png");


    playerSprite.setTexture(texture);
    // playerSprite.scale(1.5,1.5);
    SetRect(0,0);
    speed = 1;
    target.x = 10;
    target.y = 10;
    position.x = 10;
    position.y = 10;
    source.x = 0;
    source.y = 0;
    currentTile.x = 0;
    currentTile.y = 0;
    magicCounter = false;
}

Player::~Player(){}

void Player::magicAnimation(TextureManager* texturemanager)
{
    powerPosition.x = position.x;
    powerPosition.y = position.y;

    magicSprite.setTexture(texturemanager->GetTexture(5));

    magicSprite.setPosition(powerPosition.x,powerPosition.y);
    magicCounter = true;


};

void Player::magicAnimationDraw(sf::RenderWindow* rw)
{
    magicSprite.setPosition(powerPosition.x,powerPosition.y);
    magicSprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32,32));

    if(source.x * source.y == 33)
        magicCounter = false;

    rw->draw(magicSprite);
//
}
//set sprite image to load
void Player::SetRect(int x,int y)
{
    rect.x = x;
    rect.y = y;
};
//Moves camera to coordinates
void Player::Move(int x, int y)
{

	position.x = (float)x;
	position.y = (float)y;
	target.x = (float)x;
	target.y = (float)y;
}

//Centers target at coordinates
void Player::GoTo(int x, int y)
{

	target.x = (float)x;
	target.y = (float)y;
}


void Player::Draw(sf::IntRect rect,sf::RenderWindow* rw)
{
 //   baseSprite.setPosition(target.x, target.y);
 playerSprite.setPosition(position.x, position.y);
 playerSprite.setTextureRect(rect);

    rw->draw(playerSprite);
//
//    sf::Texture texture;
//
//	texture.loadFromFile("megaman16.png");
}

void Player::Update()
{
	//X distance to target, Y distance to target, and Euclidean distance
	float x, y, d;

	//Velocity magnitudes
	float vx, vy, v;

	//Find x and y
	x = (float)(target.x - position.x);
	y = (float)(target.y - position.y);

	//If we're within 1 pixel of the target already, just snap
	//to target and stay there. Otherwise, continue
	if((x*x + y*y) <= 1)
	{
		position.x = target.x;
		position.y = target.y;
	}
	else
	{
		//Distance formula
		d = sqrt((x*x + y*y));

		//We set our velocity to move 1/60th of the distance to
		//the target. 60 is arbitrary, I picked it because I intend
		//to run this function once every 60th of a second. We also
		//allow the user to change the camera speed via the speed member
		v = (d * speed);

		//Keep v above 1 pixel per update, otherwise it may never get to
		//the target. v is an absolute value thanks to the squaring of x
		//and y earlier
		if(v < 1.0f)
			v = 1.0f;

		//Similar triangles to get vx and vy
		vx = x * (v/d);
		vy = y * (v/d);

		//Then update camera's position and we're done
		position.x += vx;
		position.y += vy;
	}
}
