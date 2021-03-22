#include <iostream>
#include <memory>
#include "graphics.h"
#include <cmath>
#include <Windows.h>
#include <fstream>
#include <string>
#include <algorithm>

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;
using namespace mssm;
void graphicsMain(Graphics& g)
{
    bool Chimp=true;
    bool Chomp=true;
    int Powx=rand()%(g.width()-10)+10;
    int xvel=rand()%10+1;
    int yvel=rand()%10+1;
    int Fun=rand()%2000+1000;
    int x=1;
    int frames=0;
    int score=0;
    int Lives=3;
    int ballH=30;
    int ballW=30;
    int maxX=0;
    int dividing=0;
    int maxsize=0;
    int randPosx=rand()%g.width()-ballH;
    int randPosy=rand()%g.height()+(150+ballW);
    int recW=200;
    Vec2d BallPos={randPosx,randPosy};
    Vec2d BallVelocity;
    Vec2d RecCor={100,100};
    Vec2d RecVel={0,0};
    Vec2d PowCor={Powx,g.height()};
    while(g.draw()){
     g.clear();
    g.text((g.width()/2)-(12*25),g.height()-100,50,"Choose A Level, {1,2,3}",GREEN);

    if(g.isKeyPressed('1')){
        maxX=10;
        dividing=10;
        maxsize=10;
        break;
    }
    if(g.isKeyPressed('2')){
        maxX=15;
        dividing=6;
        maxsize=5;
        break;
    }
    if(g.isKeyPressed('3')){
        maxX=20;
        dividing=2;
        maxsize=3;
        break;
    }

    }
    while (g.draw()) {

        g.clear();
        if(Lives>0){
            RecCor=RecCor+RecVel;
            PowCor=PowCor+Vec2d{0,-5};
            g.ellipseC(BallPos,ballW,ballH,RED,PURPLE);
            g.rect(RecCor,recW,20, YELLOW,{255,110,199});
            if(score<3){
                g.text((g.width()/2)-300,g.height()-100,100,"0 || "+ to_string(Lives),WHITE);
            }
            else{
                if(score/10>=1){
                    g.text((g.width()/2)-300,g.height()-100,100,to_string(score-3)+" || "+ to_string(Lives),WHITE);
                }
                else if(score/10>=10){
                    g.text((g.width()/2)-450,g.height()-100,100,to_string(score-3)+" || "+ to_string(Lives),WHITE);
                }
                else{
                    g.text((g.width()/2)-250,g.height()-100,100,to_string(score-3)+" || "+ to_string(Lives),WHITE);
                }
            }
            if(g.isKeyPressed(Key::Left) && 0<RecCor.x){
                RecVel.x=-50;
            }
            else if(g.isKeyPressed(Key::Right) && g.width()>RecCor.x+recW){
                RecVel.x=50;
            }
            else{
                RecVel.x=0;
            }
            BallVelocity={xvel,yvel};
            if(PowCor.x>=RecCor.x-10 && PowCor.x<=RecCor.x+recW+10 && PowCor.y>=RecCor.y && PowCor.y <=RecCor.y+30 ){
                ballW=ballW+5;
                ballH=ballH+5;
                recW=recW+10;
                x=0;
            }
            if(x!=0){
                g.ellipseC(PowCor,20,20,RED,WHITE);
            }
            if(x==0){
                frames=frames+1;
            }
            if(PowCor.y<0 && frames>=Fun){
                x=1;
                frames=0;
                PowCor.y=g.height();
                PowCor.x=rand()%(g.width()-20)+20;

            }
            if(BallPos.x>=RecCor.x-ballH/2 && BallPos.x<=RecCor.x +recW+ballH/2 && BallPos.y>= RecCor.y && BallPos.y <= RecCor.y+20+ballH/2){
                Chomp=true;
                recW=recW-recW/dividing;
                ballH=ballH-ballH/dividing;
                ballW=ballW-ballW/dividing;
                if(ballW<=maxsize){
                    ballW=maxsize;
                }
                if(ballH<=maxsize){
                    ballH=maxsize;
                }
                if(recW<=maxsize*4){
                    recW=(maxsize*4);
                }
            }
            if(BallPos.x>=g.width()-ballH/2){
                Chimp=false;
                if(yvel<maxX){
                    yvel=yvel+2;}
            }
            if(BallPos.y>=g.height()-ballH/2){
                Chomp=false;
                if(xvel<maxX){
                    xvel=xvel+2;
                }
                score++;
            }
            if(BallPos.x<=ballH/2){
                Chimp=true;
                if(yvel<maxX){
                    yvel=yvel+2;}
            }
            if(BallPos.y<=ballH/2){
                Chomp=true;
                Lives--;
            }
            if(Chimp==false){
                BallVelocity.x=-xvel;
            }
            if(Chomp==false){
                BallVelocity.y=-yvel;
            }
            if(Chimp==true){
                BallVelocity.x=xvel;
            }
            if(Chomp==true){
                BallVelocity.y=yvel;
            }
            BallPos=BallPos+BallVelocity;
            frames=frames+1;
        }
        else{
            g.text((g.width()/2)-450,g.height()-100,100,"Final Score: "+ to_string(score-3),WHITE);
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



