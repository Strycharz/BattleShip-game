#include <SFML/Graphics.hpp>
#include <iostream>

#include "Rozgrywka.h"



int main()
{

    Rozgrywka gra; //Gameplay game
    gra.ustawPlansze(); //game.initBoard()
    gra.losujStatki(); //game.randomShip //sets computer ships in random places

    sf::Font font;
    font.loadFromFile("C:/Users/Admin/Desktop/Statki/statki-2022-strycharz-263729/ARIAL.TTF");
    sf::Text tekst[2];
    tekst[0].setFont(font);
    tekst[1].setFont(font);
    tekst[0].setString( L"Wygrales" ); //win
    tekst[1].setString( L"Przegrałes" ); //lose



    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        //         //check mouse
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            gra.mysz(window); //game.mouse(window)

        if(gra.czyKoniec() == true) //game.check_Who_Win
            window.draw(tekst[0]); //window.draw(victory)


        // draw everything here...
        gra.rysujPlansze(window); //game.drawBoard


        // end the current frame
        window.display();
    }

    return 0;
}

