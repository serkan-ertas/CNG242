///*** Serkan Ertas ***///

#ifndef ELEMENTSUBCLASSES_H
#define ELEMENTSUBCLASSES_H
#include "Element.h"

// Subclass for Food
class Food : public Element {
public:
    Food();

    char getRepresentation() const override;

    std::string getName() const override;

    Food *clone() const override;

    int getHpEffect(int) const override;

    bool isFood() const override;
};

// Subclass for Wood
class Wood : public Element {
public:
    Wood();

    char getRepresentation() const override;

    std::string getName() const override;

    Wood *clone() const override;

    int getHpEffect(int) const override;

    bool isWood() const override;
};

// Subclass for Medical Supply
class MedSup : public Element {
public:
    MedSup();

    char getRepresentation() const override;

    std::string getName() const override;

    MedSup *clone() const override;

    int getHpEffect(int) const override;

    bool isMedSup() const override;
};

// Subclass for Gold
class Gold : public Element {
public:
    Gold();

    char getRepresentation() const override;

    std::string getName() const override;

    Gold *clone() const override;

    int getHpEffect(int) const override;

    bool isGold() const override;
};

// Subclass for Empty
class Empty : public Element {
public:
    Empty();

    char getRepresentation() const override;

    std::string getName() const override;

    Empty *clone() const override;

    int getHpEffect(int) const override;

    bool isEmpty() const;
};

// Subclass for Wild Animals
class WildAnimal : public Element {
    bool isWild() const override;
};

#endif ELEMENTSUBCLASSES_H
