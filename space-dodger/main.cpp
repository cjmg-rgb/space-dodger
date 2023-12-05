#include <SFML/Graphics.hpp>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;


int main()
{
    //------------------------------- INITIALIZE -----------------------------------
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My Window");


    //------------------------------- INITIALIZE -----------------------------------

    //------------------------------- LOAD -----------------------------------------

    int xIndex = 0;
    int yIndex = 0;

    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    playerTexture.loadFromFile("assets/textures/player/spritesheet.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect(32*xIndex, 32*yIndex, 32, 32));
    playerSprite.scale(3, 3);
    playerSprite.setRotation(180);
    playerSprite.setPosition(sf::Vector2f(400, 550));

    //------------------------------- LOAD ------------------------------------------
 
    while (window.isOpen()) {


        //------------------------------- Event Loop -----------------------------------
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) 
                window.close();
        }
        sf::Vector2f playerPos = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(playerPos + sf::Vector2f(1, 0));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(playerPos + sf::Vector2f(-1, 0));

        //------------------------------- Event Loop -----------------------------------

        

        
        //------------------------------- UPDATE -----------------------------------

        window.clear();

        window.draw(playerSprite);

        window.display();
        window.setFramerateLimit(60);

        //------------------------------- UPDATE -----------------------------------

    }

    return 0;
}