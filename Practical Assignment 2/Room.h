///*** Serkan Ertas ***///

#ifndef ROOM_H
#define ROOM_H

enum officeType {
    None,
    CoordinatorOffice,
    StandardOffice,
    SharedOfficeFor2People,
    SharedOfficeFor3People,
    SharedOfficeFor10People,
};

class Room {
protected:
    char *room;
    int floorNo;

public:
    Room();

    Room(const char *, int);

    Room(const Room &);

    Room &operator=(const Room &);

    virtual ~Room();

    char *getRoom() const;

    int getFloorNo() const;

    // Helper for class
    virtual int getCapacity() const;
    //

    // Helper for Office
    virtual officeType getOffType() const;

    virtual int getPeopleNumber() const;
    //

    void setRoom(const char *);

    void setFloorNo(int otherFloorNo);

    virtual void printRoom() const;

    virtual char getType() const;

    virtual bool isAvailable() const;

    virtual bool isAvailable(int) const;
};

#endif //ROOM_H
