#include <iostream>
#include <memory>
#include "graphics.h"
#include <cmath>
#include <Windows.h>

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;
using namespace mssm;

void graphicsMain(Graphics& g)
{
while(true){
    while(g.draw()){
        g.text(g.width()/2,g.height()-100,100,"Please go die",WHITE);
        if(g.isKeyPressed(' ')){
     break;
    }
        g.clear();}
    int randx=rand()%g.height()/2;
    int score=1;
    int randy=rand()%g.width()/2;
    Vec2d SnakePos={0,g.height()-30};
    Vec2d SnakeVel={0,0};
    Vec2d RandFruit={randx,randy};
    vector<Vec2d> cheese;
    while (g.draw()) {
        g.clear();
     int width=30;
     Vec2d Center={SnakePos.x+15,SnakePos.y+15};
    cheese.push_back(SnakePos);
    if(cheese.size()>score){
        cheese.erase(cheese.begin());
    }
    for(int i=0;i<cheese.size();i++){
        g.rect(cheese[i],30,30,GREEN,GREEN);
    }
     if(g.isKeyPressed(Key::Up)){
         SnakeVel={0,width};
     }
     else if(g.isKeyPressed(Key::Right)){
         SnakeVel={width,0};
     }
     else if(g.isKeyPressed(Key::Down)){
         SnakeVel={0,-width};
     }
     else if(g.isKeyPressed(Key::Left)){
         SnakeVel={-width,0};
     }
     if(SnakePos.x<0 || SnakePos.x>g.width()-30){
break;
     }
     if(SnakePos.y<0 || SnakePos.y>g.height()-30){
break;
     }
     for(int x=cheese.size()-2;x>=0;x--){
         if((cheese[cheese.size()-1].x==cheese[x].x) && (cheese[cheese.size()-1].y==cheese[x].y)){
             return;
         }
     }
     g.text(g.width()/2-50,g.height()-100,100,to_string(score-1),WHITE);
     if((Center.x<=RandFruit.x+45 && Center.x>=RandFruit.x-45)&&(Center.y<=RandFruit.y+45 && Center.y>=RandFruit.y-45)){
         RandFruit.x=(rand()%g.width()-60)+60;
         RandFruit.y=(rand()%g.height()-50)+60;
         score=score+1;
     }

      for(int Row=0;Row<g.width();Row+=width){

          for(int columns=g.height()-width;columns>0;columns-=width){
              g.rect(Row,columns,width,width,WHITE);
          }
}
     g.rect(SnakePos,width,width,{0,69,255},{0,69,255});
      g.ellipseC(RandFruit,30,30,RED,RED);
      SnakePos=SnakePos+SnakeVel;
    }
    g.text(g.width()/2,g.height()-100,100,"Press A",BLUE);
    if(g.isKeyPressed('a')){
        break;
    }
}
}
int main(int /*argc*/, char** /*argv*/)
{
    srand(time(NULL));
    Graphics g("Graphics", 1200, 800, graphicsMain);
    return 0;
}



