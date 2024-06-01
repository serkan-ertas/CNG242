///*** Serkan Ertas ***///

#ifndef OFFICE_H
#define OFFICE_H
#include "Room.h"


class Office : public Room {
private:
    officeType offType;
    int peopleNumber;

public:
    Office();

    Office(const char *, int, officeType, int);

    virtual officeType getOffType() const;

    virtual int getPeopleNumber() const;

    void setOffType(officeType);

    void setPeopleNumber(int);

    bool isFull() const;

    int getCapacity() const;

    virtual void printRoom() const;

    virtual char getType() const;

    virtual bool isAvailable() const;

private:
    void printOffType() const;
};

#endif //OFFICE_H
