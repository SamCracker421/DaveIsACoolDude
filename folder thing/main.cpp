#include <iostream>
#include <memory>
#include "graphics.h"
#include <cmath>
#include <fstream>
#include <Windows.h>

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;
using namespace mssm;

void graphicsMain(Graphics& g)
{
    Image Worm("Sprite.png");
int x=0;
int i=0;
Vec2d Pos={0,0};
Vec2d vel={0,0};
    while (g.draw()) {
        g.clear();

        if(g.isKeyPressed(Key::Left)){
        vel.x=-20;
        }
        else if(g.isKeyPressed(Key::Right)){
        vel.x=20;
        }
        else if(g.isKeyPressed(Key::Up)){
        vel.y=20;
        }
        else if(g.isKeyPressed(Key::Down)){
        vel.y=-20;
        }
        else{
            vel={0,0};
        }
                Pos=Pos+vel;
        if(i==5){
             i=0;
        }
        if(x%3==0){
          if(x>0){
              i++;
          }
        g.image(Pos,100,45, Worm,0,i*45,100,45);
        }
        if(x%3==1){
                    g.image(Pos,100,45, Worm,100,i*45,100,45);
        }
        if(x%3==2){
                     g.image(Pos,100,45, Worm,200,i*45,100,45);
        }

x++;
Sleep(30);
            }
        }

int main(int /*argc*/, char** /*argv*/)
{
    // main should be empty except for the following line:
    Graphics g("Graphics", 600, 600, graphicsMain);
    return 0;
}



