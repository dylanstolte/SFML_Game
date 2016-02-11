#include "Engine.h"
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;

Engine::Engine()
{

}

Engine::~Engine()
{
	delete window;
	//this is so that the 'window = new sf::RenderWindow' is removed from memory when the engine stops)
	delete texturemanager;
	//this is so that the texturemanager is also deleted once the engine is stopped
}

bool Engine::Init()
{
    /* initialize random seed: */
  srand (time(NULL));

	texturemanager = new TextureManager();
	window = new sf::RenderWindow(sf::VideoMode(800, 800, 32), "RPG");
	frameCounter = 0;
	frameCounter1 = .3;
    switchFrame = 100;
    frameSpeed = 3000;

	clock = new sf::Clock();

	if(!window)
		return false;

	LoadTextures();
	LoadLevel();
	camera = new Camera(800,800,.1);
	player1 = new Player();//texturemanager->GetTexture(2));


	return true;
}

void Engine::LoadTextures()
{
	sf::Texture texture;

	texture.loadFromFile("woodfloor.png");
	texturemanager->AddTexture(texture);

	texture.loadFromFile("water800.png");
	texturemanager->AddTexture(texture);

    texture.loadFromFile("megaman16.png");
	texturemanager->AddTexture(texture);

    texture.loadFromFile("tree_sheet.png");
	texturemanager->AddTexture(texture);

	texture.loadFromFile("treegrow.png");
	texturemanager->AddTexture(texture);

	texture.loadFromFile("glowingballs.png");
	texturemanager->AddTexture(texture);



}

void Engine::LoadLevel()
{
	//Temporary level for testing
    currentLevel = new Level(40, 40);

	Tile* tile;
	for(int y = 0; y < 40; y++)
	{
		for(int x = 0; x < 40; x++)
		{
			if(y % 2 == 0)
				tile = new Tile(texturemanager->GetTexture(1));
			else
				tile = new Tile(texturemanager->GetTexture(0));

			currentLevel->AddTile(x, y, tile);
		}
	}
}




void Engine::ProcessInput()
{
	sf::Event evt;
	 enum { Down, Left, Right, Up};

	//Loop through all window events
	while(window->pollEvent(evt))
	{

		if(evt.type == sf::Event::Closed)
			window->close();
//        if(player1->GetPosition() != player1->GetTarget())
//            break;
//        if((evt.type == sf::Event::MouseButtonPressed) )//&& (mouseDown == false))
//            {
//            int x = camera->GetPosition().x +  sf::Mouse::getPosition(*window).x;
//            int y = camera->GetPosition().y +  sf::Mouse::getPosition(*window).y;
//            camera->GoToCenter(x,y);
//       //   player1->Move(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y);
//           // mouseDown = true;
//            }
////            frameCounter += frameSpeed * clock->restart().asSeconds();
////     if(frameCounter >= switchFrame)
////     {
////          frameCounter = 0;
////            player1->SetRect(player1->Getrect().x + 1,player1->Getrect().y);
////            if(player1->Getrect().x * 57 >= player1->texture.getSize().x)
////                player1->SetRect(0,player1->Getrect().y);
////
////      }
	}

	//sprite movement
   // frameCounter1 += 1000 * clock->restart().asSeconds();

    if((player1->GetPosition() == player1->GetTarget()))// && frameCounter1 >=  .3 )
    {
      //  frameCounter1 =0;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      {

        player1->magicAnimation(texturemanager);
      }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            // left key is pressed: move our character
            //  player1->playerSprite.move(4,0);
           //   player1->SetRect(,player1->Getrect().y);
            player1->GoTo(player1->GetPosition().x+10,player1->GetPosition().y);

//                    int x = camera->GetPosition().x+800;
//                   int y = camera->GetPosition().y;
//                   camera->GoTo(x,y);


            {

                player1->SetRect(player1->Getrect().x + 1,Right);

            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            // left key is pressed: move our character
            player1->GoTo(player1->GetPosition().x,player1->GetPosition().y+10);
//                    int x = camera->GetPosition().x;
//                   int y = camera->GetPosition().y+800;
//                    camera->GoTo(x,y);
            player1->SetRect(player1->Getrect().x + 1,Down);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            // left key is pressed: move our character
            player1->GoTo(player1->GetPosition().x-10,player1->GetPosition().y);
//            int x = camera->GetPosition().x-800;
//            int y = camera->GetPosition().y;
//            camera->GoTo(x,y)}
                player1->SetRect(player1->Getrect().x + 1,Left);


        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {

            // left key is pressed: move our character
            player1->GoTo(player1->GetPosition().x,player1->GetPosition().y-10);
//           int x = camera->GetPosition().x;
//            int y = camera->GetPosition().y-800;
//            camera->GoTo(x,y);
            player1->SetRect(player1->Getrect().x + 1,Up);
        }
}
 /////////check if player is by wall, if by wall slide camera to next tile///////////////////////
        if(player1->GetPosition().x > 700)
        {
            int x = camera->GetPosition().x+800;
            int y = camera->GetPosition().y;
            camera->GoTo(x,y);

            player1->GoTo(2,player1->GetPosition().y);


        }
        if(player1->GetPosition().y < 1)
        {
            int x = camera->GetPosition().x;
            int y = camera->GetPosition().y-800;
            camera->GoTo(x,y);

            player1->GoTo(player1->GetPosition().x,700);
        }
        if(player1->GetPosition().y > 700)
        {
            int x = camera->GetPosition().x;
            int y = camera->GetPosition().y+800;
            camera->GoTo(x,y);

            player1->GoTo(player1->GetPosition().x,102);
        }
        if(player1->GetPosition().x < 1)
        {
            int x = camera->GetPosition().x-800;
            int y = camera->GetPosition().y;
            camera->GoTo(x,y);

            player1->GoTo(700,player1->GetPosition().y);
        }
      //  if(evt.type == sf::Event::MouseButtonReleased)
      //      mouseDown = false;


}


void Engine::Update()
{

 player1->Update();
 camera->Update();

}

void Engine::RenderFrame()
{
	//Camera offsets
	int camOffsetX, camOffsetY;


	//tile
	Tile* tile;
	Tile* currentTile;
    int tileSize = 800;
	window->clear();


	//Get the tile bounds we need to draw and Camera bounds
	sf::IntRect bounds = camera->GetTileBounds(tileSize);

	//Figure out how much to offset each tile
	camOffsetX = camera->GetTileOffset(tileSize).x;
	camOffsetY = camera->GetTileOffset(tileSize).y;


	//Loop through and draw each tile
	//We're keeping track of two variables in each loop. How many tiles
	//we've drawn (x and y), and which tile on the map we're drawing (tileX
	//and tileY)
	for(int y = 0, tileY = bounds.top; y < bounds.height; y++, tileY++)
	{
		for(int x = 0, tileX = bounds.left; x < bounds.width; x++, tileX++)
		{
			//Get the tile we're drawing
			tile = currentLevel->GetTile(tileX, tileY);

			//set tile sprite animations, use clock to time animations
            tile->source.x++;
            if((tile->source.x == 7 )&& (tile->source.y == 10))
                tile->source.x-- ;

            if(tile->source.x >= 12)//texturemanager->GetTexture(4).getSize().x)
                {

                    tile->source.x = 0;
                    tile->source.y++;
             //        tile->source.x = 5;
              //      tile->source.y = 10;
                }
            //draw tile
			tile->Draw((x * tileSize) - camOffsetX, (y * tileSize) - camOffsetY, window,texturemanager);
		}
	}




            if(player1->Getrect().x * 56 >= player1->texture.getSize().x)
                player1->SetRect(0,player1->Getrect().y);

        //magicanimation increment
 //if((frameCounter >= 200) )
 {


            player1->source.x++;
        if(player1->source.x >=7)//* 32 >= 384)
       {
              player1->source.x = 0;
              player1->source.y++;
       }
        if(player1->source.y >= 5)
        {
            player1->source.y = 0;
            player1->source.x = 0;
        }

 }

    player1->Draw(sf::IntRect(player1->Getrect().x * 56,player1->Getrect().y * 56,56,56),window);
	window->display();
}


void Engine::MainLoop()
{
    cout << "test" << endl;
	//Loop until our window is closed
	while(window->isOpen())
	{
	     frameCounter += frameSpeed * clock->restart().asSeconds();

    if((frameCounter >= switchFrame) )//& (player1->GetPosition() == player1->GetTarget()))
    {

        ProcessInput();

		Update();
		RenderFrame();
		frameCounter = 0;
    }
	}
}

void Engine::Go()
{
	if(!Init())
		throw "Could not initialize Engine";
	MainLoop();
}

