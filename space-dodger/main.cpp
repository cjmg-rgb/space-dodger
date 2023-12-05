#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <vector>

const int WIDTH = 800;
const int HEIGHT = 600;


int main()
{
    //------------------------------- INITIALIZE -----------------------------------
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My Window");
    srand(time(NULL));


    //------------------------------- INITIALIZE -----------------------------------

    //------------------------------- LOAD -----------------------------------------


    // Player
    int xIndex = 0;
    int yIndex = 0;

    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    playerTexture.loadFromFile("assets/textures/player/spritesheet.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect(32*xIndex, 32*yIndex, 32, 32));
    playerSprite.scale(2, 2);
    playerSprite.setRotation(180);
    playerSprite.setPosition(sf::Vector2f(400, 550));

    // Enemy
    int enemyList[5][2] = {
        {3, 0}, {6, 0}, {9, 0},
        {0, 4}, {6, 4}
    };
    int enemyIndex = rand() % 4;
    int enemySpeed = (rand() % 5) + 1;
    int enemy[2] = { enemyList[enemyIndex][0], enemyList[enemyIndex][1] };

    sf::Texture enemyTexture;
    sf::Sprite enemySprite;
    enemyTexture.loadFromFile("assets/textures/enemy/spritesheet.png");
    enemySprite.setTexture(enemyTexture);
    enemySprite.setTextureRect(sf::IntRect(32*enemy[0], 32*enemy[1], 32, 32));
    enemySprite.scale(2, 2);
    enemySprite.setPosition(sf::Vector2f(rand() % WIDTH-64, 0));

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

        //------------------------------- AI movement ----------------------------------
        sf::Vector2f enemyPos = enemySprite.getPosition();
        enemySprite.setPosition(enemyPos + sf::Vector2f(0, enemySpeed));

        if (enemyPos.y >= HEIGHT) {
            enemyIndex = rand() % 4;
            enemySpeed = (rand() % 5) + 1;
            enemy[0] = enemyList[enemyIndex][0];
            enemy[1] = enemyList[enemyIndex][1];
            enemySprite.setTextureRect(sf::IntRect(32 * enemy[0], 32 * enemy[1], 32, 32));
            enemySprite.setPosition(sf::Vector2f(rand() % WIDTH - 64, 0));
        }

        //------------------------------- AI movement ----------------------------------


        //------------------------------- UPDATE -----------------------------------

        window.clear();

        window.draw(playerSprite);
        window.draw(enemySprite);

        window.display();
        window.setFramerateLimit(60);

        //------------------------------- UPDATE -----------------------------------

    }

    return 0;
}