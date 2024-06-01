///*** Serkan Ertas ***///

#ifndef CLASSROOM_H
#define CLASSROOM_H
#include "Room.h"


class Classroom : public Room {
private:
    int Capacity;

public:
    Classroom();

    Classroom(const char *, int, int);

    virtual int getCapacity() const;

    void setCapacity(int);

    bool checkSuitability(int) const;

    virtual void printRoom() const;

    virtual char getType() const;

    virtual bool isAvailable(int) const;
};

#endif //CLASSROOM_H
