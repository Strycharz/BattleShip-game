//
// Created by Wojtek on 06.05.2022.
//

#include "Rozgrywka.h"
#include <time.h>
Rozgrywka::Rozgrywka() {
    for(int i=0; i<100; i++)
         czyUstawiony[i] = 0;
}


void Rozgrywka::mysz(sf::RenderWindow &window) {

    for (int i = 0; i < 100; i++) {
        int px = prostokat[i].getPosition().x + 10;
        int py = prostokat[i].getPosition().y + 10;

        int px2 = prostokat2[i].getPosition().x + 10;
        int py2 = prostokat2[i].getPosition().y + 10;

        int mx = sf::Mouse::getPosition(window).x;
        int my = sf::Mouse::getPosition(window).y;

        if ((px - mx) * (px - mx) + (py - my) * (py - my) < 100)
        {
            if(czyWszystkieStatki() == true) //hasTenShipsOnBoard //checks if the player has set all 10 ships
            {
                if(prostokat[i].getFillColor()==(sf::Color::White))
                    ruchKomputera(); //ComputerOnMove draws a place where the computer wants to hit
                if(statek[i] == true)
                    prostokat[i].setFillColor(sf::Color::Red);
                else
                    prostokat[i].setFillColor(sf::Color::Blue);
            }

        }

        if ((px2 - mx) * (px2 - mx) + (py2 - my) * (py2 - my) < 100)
        {
            if(czyWszystkieStatki() == false) //hasTenShipsOnBoard //checks if the player has set all 10 ships
                prostokat2[i].setFillColor(sf::Color::Green);
        }




    }
}

void Rozgrywka::ustawPlansze(){  //sets the color, size and position of each individual rectangle
    for(int i=0; i<100; i++)
    {
        prostokat[i].setSize(sf::Vector2f(20, 20));
        prostokat[i].setOutlineColor(sf::Color{ 254, 80, 0 });
        prostokat[i].setOutlineThickness(2.f);

        prostokat2[i].setSize(sf::Vector2f(20, 20));
        prostokat2[i].setOutlineColor(sf::Color{ 25, 20, 80 });
        prostokat2[i].setOutlineThickness(2.f);
    }

    for(int i=0; i<100; i++)
    {
        prostokat[i].setPosition((i % 10 +1) * 25 + 50, 50 + i/10 * 25);
        prostokat2[i].setPosition((i % 10 +1) * 25 + 400, 50 + i/10 * 25);
    }

}

void Rozgrywka::rysujPlansze(sf::RenderWindow &window){
    for(int i=0; i<100; i++)
    {
        window.draw(prostokat[i]);
        window.draw(prostokat2[i]);
    }
}

void Rozgrywka::losujStatki(){
    srand(time(NULL));

    for(int i=0; i<10; i++)
    {
        statek[rand()%100+1]=1;
    }
}

bool Rozgrywka::czyWszystkieStatki() {//hasTenShipsOnBoard //checks if the player has set all 10 ships

        for(int i=0; i<100; i++) {
            if (prostokat2[i].getFillColor() == (sf::Color::Green))
                czyUstawiony[i] = 1; //is a ship in this field
        }
        int x=0;
        for(int i=0; i<100; i++){
            x = x + czyUstawiony[i]; //get a amount of green fields
        }

        if(x==10)
        {
            return true;
        }
//        else
//            return false;

}


void Rozgrywka::ruchKomputera(){
    srand(time(NULL));

    int los;
    los=rand()%100+1;
    if(prostokat2[los].getFillColor()==(sf::Color::White))
        prostokat2[los].setFillColor(sf::Color::Blue);

    if(prostokat2[los].getFillColor()!=(sf::Color::White) && prostokat2[los].getFillColor()!=(sf::Color::Blue))
        prostokat2[los].setFillColor(sf::Color::Red);

}

bool Rozgrywka::czyKoniec() {
    for(int i=0; i<100; i++) {
        if (prostokat[i].getFillColor() == (sf::Color::Red))
            czy10[i] = 1;
    }
    int x=0;
    for(int i=0; i<100; i++)
        x = x + czy10[i];
    if(x==10)
        return true;
}

