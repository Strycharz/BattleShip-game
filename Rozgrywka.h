//
// Created by Wojtek on 06.05.2022.
//

#ifndef STATKI2_ROZGRYWKA_H
#define STATKI2_ROZGRYWKA_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Rozgrywka {

    bool statek[100]; //ship
    int czyUstawiony[100]; //is a ship in this field
    bool czy10[100]; //is a ship in this field
    bool Czy10[100]; //is a ship in this field

    sf::RectangleShape prostokat[100]; //Rectangle[100] // player board
    sf::RectangleShape prostokat2[100]; //Rectangle2[100] // computer board
public:
    Rozgrywka();


    //----------drawing in SFML---------//
    void mysz(sf::RenderWindow & window); //mouse
    void rysujPlansze(sf::RenderWindow & window); //drawBoard
    //---------------------------------------//

    void ustawPlansze(); //sets the color, size and position of each individual rectangle

    void losujStatki(); //randomShips //get 10 random place to set a computer ships //
    void ruchKomputera(); //ComputerOnMove draws a place where the computer wants to hit

    bool czyWszystkieStatki(); //hasTenShipsOnBoard //checks if the player has set all 10 ships
    bool czyKoniec(); // //check if all the player's ships are sunk






};


#endif //STATKI2_ROZGRYWKA_H
