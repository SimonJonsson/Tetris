/*
 * TDDC76 - MAT3 - Group 5
 *
 * IDENTIFIERING
 *
 * Filnamn:    UpdateView.h
 * Enhetsnamn: UpdateView
 * Typ:        Moduldeklaration
 * Revision:   1
 * Skriven av: Simon Jönsson
 *
 *
 * BESKRIVNING
 *
 * Abstract class for all 'Views'
 *
 * REVISIONSBERÄTTELSE
 *
 * Revision     Datum   Förändringar
 *
 * 1            940319  Ursprungsversion
 */
#ifndef UPDATEVIEW_H
#define UPDATEVIEW_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Color.hpp>

class UpdateView
{
public:
    UpdateView();
    ~UpdateView() = default;

    virtual void update() = 0;

    virtual void leftClick()    = 0;
    virtual void rightClick()   = 0;
    virtual void upClick()      = 0;
    virtual void downClick()    = 0;

    sf::Color background{120,120,120};
    sf::Color highlight{180,180,180};
    sf::Color textcolor{255,0,0};

private:

};

#endif
