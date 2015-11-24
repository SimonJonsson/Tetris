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

private:

};

#endif
