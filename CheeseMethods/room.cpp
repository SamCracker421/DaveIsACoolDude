#include "room.h"
#include <iostream>
#include <vector>
#include <items.h>

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;

void Room::printRoom(){
    cout<<name<<'\n'<<'\n';
    cout<<description<<'\n';
    cout<<"Adjacentrooms:"<<'\n';
    for(int x=0; x<adjacentrooms.size();x++){
        cout<<adjacentrooms[x].name<<'\n';
    }
    cout<<"Items:"<<'\n';
    for(int x=0;x<item.size();x++){
        cout<<item[x].name<<'\n';
    }
}
