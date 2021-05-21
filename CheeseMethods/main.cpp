#include <iostream>
#include <vector>
#include <room.h>
#include <world.h>
#include <items.h>
#include <windows.h>
#include <cctype>
#include <algorithm>
#include <stopwatch.h>
#include <time.h>

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;

void toupper(string& str)
{
transform(str.begin(), str.end(), str.begin(), [](string::value_type c) { return toupper(c); });
}

void tolower(string& str)
{
  transform(str.begin(), str.end(), str.begin(), [](string::value_type c) { return tolower(c); });
}
class World
{
public:
    vector<items> inventory;
    vector<Room> listofrooms;
    Room currentroom;
public:
    void printCurrentRoom();
    void handleUserInput(vector<Room>& cheese, bool& win);

};

void World::handleUserInput(vector<Room>& cheese, bool& win){
    string action;
    string target;
    Room Current;
    cin>>action;
    tolower(action);

    if(action=="combine"){
        string target1;
        string target2;
        cout<<"First Item: ";
        cin>>target1;
        tolower(target1);
        cout<<'\n'<<"Second Item: ";
        cin>>target2;
        tolower(target2);

        for(int x=0;x<inventory.size();x++){
            for(int i=0;i<inventory.size();i++){
                if((target1=="saw" && target2=="table") || (target1=="table" && target2=="saw")){
                    if((target1==inventory[x].name) && (target2==inventory[i].name)){
                        items Half1{"halftable", "Why did you cut the table in half?",false};
                        items Half2{"secondhalf","Why did you cut the table in half?",false};
                        inventory.push_back(Half1);
                        inventory.push_back(Half2);
                        for(int z=0;z<inventory.size();z++){
                            if(inventory[z].name=="table"){
                                inventory.erase(inventory.begin()+z);
                            }
                        }
                    }
                }
                if((target1=="halftable" && target2=="secondhalf") || (target1=="secondhalf" && target2=="halftable")){
                    if(target1==inventory[x].name && target2==inventory[i].name){
                        items TwoHalves{"two-halves", "The Two Halves in one place.",false};
                        inventory.push_back(TwoHalves);
                        for(int z=0;z<inventory.size();z++){
                            if(inventory[z].name=="halftable"){
                                inventory.erase(inventory.begin()+z);
                            }
                            if(inventory[z].name=="secondhalf"){
                                inventory.erase(inventory.begin()+z);
                            }
                        }
                    }
                }
                if((target1=="two-halves" && target2=="duct-tape") || (target1=="duct-tape" && target2=="two-halves")){
                    if(target1==inventory[x].name && target2==inventory[i].name){
                        items Whole{"whole", "A Whole",false};
                        inventory.push_back(Whole);
                        for(int z=0;z<inventory.size();z++){
                            if(inventory[z].name=="two-halves"){
                                inventory.erase(inventory.begin()+z);
                            }
                            else if(inventory[z].name=="duct-tape"){
                                inventory.erase(inventory.begin()+z);
                            }
                        }
                    }
                }
            }
        }
        return;
    }
    if(action=="help"){
    cout<<'\n';
    }
        cin.ignore();
        cin>>target;
        tolower(target);
        if(action=="use"){
            for(int x=0; x<inventory.size();x++){
                if(target=="whole" && target==inventory[x].name){
                    win=true;
                }
            }
        }
        if(action=="go"){
            for(int i=0; i<cheese.size();i++){
                if(cheese[i].CurrentRoom==true){
                    Current=cheese[i];
                    cheese[i].CurrentRoom=false;
                }
                else{
                    cheese[i].CurrentRoom=false;
                }
            }

             for(int z=0;z<cheese.size();z++){
                for(int x=0;x<cheese[z].adjacentrooms.size()+1;x++){
                    if(Current.adjacentrooms[x].name==target){
                        if(target==cheese[z].name){
                        cheese[z].CurrentRoom=true;
                        }
                    }
                }
            }
                 }
        if(action=="grab"){
            for(int x=0;x<cheese.size();x++){
                if(cheese[x].CurrentRoom==true){
                    for(int i=0;i<cheese[x].item.size();i++){
                        if(cheese[x].item[i].name==target){
                            inventory.push_back(cheese[x].item[i]);
                            cheese[x].item.erase(cheese[x].item.begin()+i);
                        }
                    }
                }
            }
        }
        if(action=="drop"){
            for(int x=0;x<inventory.size();x++){
                if(inventory[x].name==target){
                    for(int i=0;i<cheese.size();i++){
                        if(cheese[i].CurrentRoom==true){
                            cheese[i].item.push_back(inventory[x]);
                            inventory.erase(inventory.begin()+x);
                        }
                    }
                }
            }
        }
        if(action=="investigate"){
            for(int x=0;x<cheese.size();x++){
                if(cheese[x].CurrentRoom==true){
                    for(int i=0;i<cheese[x].item.size();i++){
                        if(target==cheese[x].item[i].name){
                            cout<<cheese[x].item[i].use;
                            Sleep(5000);
                        }
                    }
                }
            }
        }
    }
int main(){

    items saw{"saw","Used to cut bread",false};
    items table{"table","Used to eat food upon",false};
    items DuctTape{"educt-tape","Roll of green and brown duct tape",false};
    items duck{"duck","A live duck",false};
    vector<Room> cheese;
    bool win=false;
    Room LivingRoom{"Bare with white walls, Low hanging ceiling almost touches the floor.", "living-room",{saw}, {},false};
    Room Kitchen{"Standard 1940's kitchen with small barred window out of which is a poplar tree. Clean and well maintained.", "kitchen",{DuctTape},{},false};
    Room Diningroom{"Brown colored walls make up most of the interior of the room", "dining-room", {table},{},true};
    Room MudRoom{"Large room. Seemingly empty with nothing in it. No shoes lay scattered across the entryway. The Door is locked and renforced. Way to leave.","mudroom", {duck},{},false};
    LivingRoom.adjacentrooms.push_back(Kitchen);
    LivingRoom.adjacentrooms.push_back(Diningroom);
    Kitchen.adjacentrooms.push_back(MudRoom);
    Kitchen.adjacentrooms.push_back(LivingRoom);
    Diningroom.adjacentrooms={LivingRoom};
    MudRoom.adjacentrooms={Kitchen};
    cheese.push_back(LivingRoom);
    cheese.push_back(Kitchen);
    cheese.push_back(Diningroom);
    cheese.push_back(MudRoom);
    Stopwatch Shop{};
    Shop.startwatch();

    World world{{},cheese};
    while(true){
        for(int x=0; x<cheese.size();x++){
            if(cheese[x].CurrentRoom==true){
                cheese[x].printRoom();
            }
        }
        cout<<"Inventory: "<<'\n';
        for(int i=0;i<world.inventory.size();i++){
            cout<<world.inventory[i].name<<'\n';
        }

        cout<<'\n'<<'\n';
        world.handleUserInput(cheese,win);
        system("cls");
        if(win==true){
            Shop.stopwatch();
            break;
        }
    }
    cout<<"You won, Congratulations. Your time: "<<Shop.calculation()<<'\n';
}
