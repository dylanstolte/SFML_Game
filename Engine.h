#ifndef _ENGINE_H
#define _ENGINE_H

#include <SFML\Graphics.hpp>

#include "TextureManager.h"
#include "Tile.h"
#include "Level.h"
#include "Camera.h"
#include "Player.h"

class Engine
{
private:
	//SFML Render Window
	sf::RenderWindow* window;
	TextureManager* texturemanager;

	float frameCounter, frameCounter1, switchFrame, frameSpeed;
	sf::Clock* clock;

    bool slide;
	//Initializes the engine
	bool Init();
	//Main Game Loop
	void MainLoop();
	//Renders one frame
	void RenderFrame();
	//Processes user input
	void ProcessInput();
	//Updates all Engine internals
	void Update();



	//Temporary

	void LoadTextures();
	void LoadLevel();
	Tile* testTile;
	Camera* camera;
	Level* currentLevel;
	Player* player1;

public:

	Engine();
	~Engine();
	void Go();					//Starts the engine
};

#endif

