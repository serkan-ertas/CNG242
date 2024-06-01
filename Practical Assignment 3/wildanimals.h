///*** Serkan Ertas ***///

#ifndef WILDANIMALS_H
#define WILDANIMALS_H

#include "elementsubclasses.h"

// Subclass for Wolf
class Wolf : public WildAnimal {
public:
    Wolf();

    char getRepresentation() const override;

    std::string getName() const override;

    Wolf *clone() const override;

    int getHpEffect(int) const override;
};

// Subclass for Bear
class Bear : public WildAnimal {
public:
    Bear();

    char getRepresentation() const override;

    std::string getName() const override;

    Bear *clone() const override;

    int getHpEffect(int) const override;
};

#endif WILDANIMALS_H
