#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <vector>
#include <items.h>

using namespace std;

class Room
{
public:
    string description;
    string name;
    vector<items> item;
    vector<Room> adjacentrooms;
    bool CurrentRoom;
public:
    void printRoom();
};

#endif // ROOM_H
