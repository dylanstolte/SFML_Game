#ifndef _PLAYER_H
#define _PLAYER_H

#include <SFML\Graphics.hpp>

class Player
{
private:


    	//Absolute position of camera (number of
	//pixels from origin of level map)
	sf::Vector2f position;

	//Target position camera is moving towards
	sf::Vector2f target;

    float speed;

    	   //Player sprite


public:
    Player();//sf::Texture& texture);
    ~Player();
sf::Sprite playerSprite;
sf::Texture texture;
sf::Vector2i rect;
    void Update();
    void Move(int x, int y);
    void GoTo(int x, int y);
    void SetRect(int x,int y);

    sf::Vector2i GetPosition() { return sf::Vector2i((int)position.x, (int)position.y); }
    sf::Vector2i GetTarget() { return sf::Vector2i((int)target.x, (int)target.y); }
    sf::Vector2i Getrect() { return sf::Vector2i((int)rect.x, (int)rect.y); }
    void Draw(sf::IntRect rect,sf::RenderWindow* rw);

};

#endif
