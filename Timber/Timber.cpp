//Alpha script. Added in for language detection.


#include "pch.h"      //Proprocessors directives. These are files in our folder streucture.
#include <iostream>
#include <SFML/Graphics.hpp> //Adds code from the HPP file.

using namespace std;
using namespace sf; //Allows us to prevent typing sf::. /SFML data. 

int main()                //Execution of the entire program begins here. 
{
    string playerName;
    playerName = "Ryan";

    //Create a video mode object.
    VideoMode vm(1920, 1080);
    //Create and open a window for the game.
    RenderWindow window(vm, "Timber!!!", Style::Fullscreen);
    //Create a texture to hold a graphic on the GPU. It is a graphic stored in memory.
    Texture textureBackground;
    //Load a graphic into the texture.
    textureBackground.loadFromFile("graphics/background.png");
    //Create a sprite.
    Sprite spriteBackground;
    //Attach the texture to the sprite.
    spriteBackground.setTexture(textureBackground);
    //Set the spriteBackground to cover the screen.
    spriteBackground.setPosition(0, 0); //The background png is 1920 1080. Thus, putting it at 0,0 will cover the screen neatly.

    //OpenGl and Graphic Cards - Textures take up a finite memory. Furthrmore, the process of loading in a graphic into the GPU memory is very slow.
    //It is slow enough that you can't do it every frame. So it useful to use textureBackground for other processes to manipulate during the main loop.
    
    //Make a tree texture.
    Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    //Make a bee.
    Texture textureBee;
    textureBee.loadFromFile("graphics/insect.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);
    //Is the bee currently moving?
    bool beeActive = false;
    //How fast can the bee fly?
    float beeSpeed = 0.0f;

    //Make 3 cloud sprites from 1 texture.
    Texture textureCloud;
    //Load 1 new texture.
    textureCloud.loadFromFile("graphics/cloud.png");
    //3 new sprites with the same texture.
    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);
    //Position the clouds off screen.
    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 250);
    spriteCloud3.setPosition(0, 500);
    //Are the clouds currently on screen?
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;
    //How fast is each cloud?
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    //Variable to control the time.
    Clock clock;

    while (window.isOpen())
    {
        //Handles player input. 

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }


        //Clear everything from the last frame.
        window.clear();

        //Update the Scene.
        Time dt = clock.restart(); //Time how long each frame takes.
        //DeltaTime, amount of time elapsed since the last frame we started the clock.  

        //Setup the bee/
        if (!beeActive)
        {
            //How fast is the bee?
            srand((int)time(0) * 10);
            beeSpeed = (rand() % 200) + 200;

            //How high is the bee
            srand((int)time(0) * 10);
            float height = (rand() % 500) + 500;
            spriteBee.setPosition(2000, height);
            beeActive = true;
        }
        else
        {
            spriteBee.setPosition
            (spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
                spriteBee.getPosition().y);
            //Has the bee reached the right hand edge of the screen?
            if (spriteBee.getPosition().x < -100)
            {
                //Set it up ready to be a whole new cloud next frame. 
                beeActive = false;
            }
        }

        //Draw our game scene here. This is in sequence, else the ones earlier will be covered by the ones later. 
        window.draw(spriteBackground);

        //Draw the clouds.
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        
        //Draw the tree.
        window.draw(spriteTree);

        //Draw the insect.
        window.draw(spriteBee);

        //Show everything we just drew.
        window.display(); //When we draw something, we are drawing them to a hidden
        //surface to be displayed. The code flips from the previous displayed surface to the
        //newly updated previously hidden one. This way, players will never see the drawing process
        //on the game window itself. This is known as double buffering. This will ensure all drawing is complete before displaying to prevent
        //a glitch known as tearing. 
    }
    return 0;
}




