#include <iostream>
#include <memory>
#include "graphics.h"
#include <cmath>
#include <fstream>

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;
using namespace mssm;

void drawShip(Graphics& g, Vec2d position, double scale, double angle, vector<Vec2d>& Lines){

    Lines.clear();
    vector<Vec2d> points {
        {-20,-20},
        {0,-10},
        {20,-20},
        {0,30}
    };

    for (int i = 0; i < points.size(); i++) {
        points[i].rotate(angle);
        points[i] = points[i] * scale;
        points[i] = points[i] + position;
    }
    for(int x=0;x<points.size();x++){
    Lines.push_back(points[x]);
   }
    g.polygon(points, WHITE,RED);

}
void asterpoints(Graphics&g, Vec2d AsStart, double Astangle, double Asterscale){
    vector<Vec2d> Asterpoints{
        {0,13.065},
        {-9.2383500962,9.2383500962},
        {-13.065,0},
        {-9.2383500962,-9.2383500962},
        {0,-13.065},
        {9.2383500962,-9.2383500962},
        {13.065,0},
        {9.2383500962,9.2383500962}

};
    for (int i = 0; i < Asterpoints.size(); i++) {
        Asterpoints[i].rotate(Astangle);
        Asterpoints[i] = Asterpoints[i] * Asterscale;
        Asterpoints[i] = Asterpoints[i] + AsStart;
    }
    g.polygon(Asterpoints,WHITE, {210,105,30});
}

class Ship{
public:
    Vec2d pos;
    Vec2d CheeseVel;
    Vec2d CheeseAcc;
    double angle=angle;
    double AngularVel;
    Vec2d CheeseDirection;
};
bool AsteroidCollision(vector<vector<Vec2d>> Asteroids, vector<vector<Vec2d>> SwissCheese, Ship ship,Graphics& g){

    for(int i=0;i<Asteroids.size();i++){
        if(sqrt(pow(Asteroids[i][0].x-ship.pos.x,2)+ pow(Asteroids[i][0].y-ship.pos.y,2))<28.065){
            return false;
        }
    }
    for(int x=0;x<SwissCheese.size();x++){
        if(sqrt(pow(SwissCheese[x][0].x-ship.pos.x,2)+ pow(SwissCheese[x][0].y-ship.pos.y,2))<28.065){
            return false;
        }
    }
    return true;

}

void CalcAsteroids(vector<vector<Vec2d>>& Asteroids, vector<vector<Vec2d>>& Bullet, Graphics& g, vector<vector<Vec2d>>& SwissCheese, int& score){
    int plusminus=rand()%2+1;
    for(int x=0; x< Asteroids.size(); x++){
     for(int i=0; i< Bullet.size(); i++){
         if(sqrt(pow((Asteroids[x][0].y-Bullet[i][0].y),2)+(pow((Asteroids[x][0].x-Bullet[i][0].x),2))) < 23.065){
             Bullet.erase(Bullet.begin()+i);
             score=score+25;
             SwissCheese.push_back({Asteroids[x][0],Asteroids[x][1]});
             if(plusminus==1){
             SwissCheese.push_back({Asteroids[x][0],Asteroids[x][1]+Vec2d{rand()%13-3,rand()%13+3}});
             }
             else if(plusminus==2){
                 SwissCheese.push_back({Asteroids[x][0],Asteroids[x][1]-Vec2d{rand()%13-3,rand()%13+3}});
             }
             Asteroids.erase(Asteroids.begin()+x);
         }
     }
    }
     for(int x=0; x< SwissCheese.size(); x++){
      for(int i=0; i< Bullet.size(); i++){
          if(sqrt(pow((SwissCheese[x][0].y-Bullet[i][0].y),2)+(pow((SwissCheese[x][0].x-Bullet[i][0].x),2))) < 16.0325){
              score=score+50;
              Bullet.erase(Bullet.begin()+i);
               SwissCheese. erase(SwissCheese.begin()+x);
     }
     }
     }
   for(int z=0;z<Asteroids.size();z++){
       Asteroids[z][0]=Asteroids[z][0]+Asteroids[z][1];

   if(Asteroids[z][0].y<-13.065){
       Asteroids[z][0].y=g.height();
   }
   if(Asteroids[z][0].y>g.height()+13.065){
       Asteroids[z][0].y=-13.065;
   }
if(Asteroids[z][0].x<-13.065){
    Asteroids[z][0].x=g.width()+13.065;
}
if(Asteroids[z][0].x>g.width()+13.065){
    Asteroids[z][0].x=-13.065;
}
}
   for(int z=0;z<SwissCheese.size();z++){

   if(SwissCheese[z][0].y<-6.5325){
       SwissCheese[z][0].y=g.height();
   }
   if(SwissCheese[z][0].y>g.height()+6.5325){
       SwissCheese[z][0].y=-6.5325;
   }
if(SwissCheese[z][0].x<-6.5325){
    SwissCheese[z][0].x=g.width()+6.5325;
}
if(SwissCheese[z][0].x>g.width()+6.5325){
    SwissCheese[z][0].x=-6.5325;
}
}
   }



void drawbullets(vector<vector<Vec2d>> Bullet, Graphics& g){

    for(int x=0; x<Bullet.size();x++){
        g.ellipseC(Bullet[x][0], 10,10,WHITE,WHITE);
    }
    g.clear();
}
void Calc(vector<vector<Vec2d>>& Bullet,Graphics& g){
for(int x=0;x<Bullet.size();x++){
    Bullet[x][0]=Bullet[x][1]+Bullet[x][0];
    if(Bullet[x][0].x<0 || Bullet[x][0].x>g.width() || Bullet[x][0].y>g.height() || Bullet[x][0].y<0){
        Bullet.erase(Bullet.begin()+x);
    }
}
}
void graphicsMain(Graphics& g)
{

    int AmntBullets=0;
    int moving=0;
    double Astangle=0;
    double Asterscale=2;
    int frames=0;
    int score;
   vector<vector<Vec2d>> SwissCheese;
    vector<Vec2d> posvel;
    Ship ship{{500,500},{0,0},{0,0},0,0,{0,0}};
    vector<vector<Vec2d>> Bullet;
    vector<vector<Vec2d>> Asteroids;
    vector<Vec2d> roids;
    vector<Vec2d> Lines;

while (g.draw()) {

    while(Asteroids.size()<5){
    int x=rand()%4;
    switch(x){
    case 1:
        roids={{rand()%g.width()+13.065,-13.065},{rand()%10,rand()%10+3}};
        break;
    case 2:
        roids={{-13.065, rand()%g.height()+13.065},{rand()%10+3,rand()%10}};
        break;
    case 3:
        roids={{g.width()+13.065,rand()%g.height()+13.065},{-rand()%10,rand()%10+3}};
        break;
    case 4:
        roids={{rand()%g.width()+13.065,g.height()+13.065},{rand()%10+3,-rand()%10}};
        break;
    default:
        break;
    }


    Asteroids.push_back(roids);

    }
        Vec2d CheeseDirection={cos(ship.angle + M_PI/2),sin(ship.angle + M_PI/2)};
    g.clear();

    if(g.isKeyPressed(Key::Right)){
    moving=1;
    }
    else if (g.isKeyPressed(Key::Left)){
    moving=2;
    }
    else{
    moving=0;
    }
    if(g.isKeyPressed(Key::Up)){
        ship.CheeseAcc=CheeseDirection;
    }
    else{
        ship.CheeseAcc={0,0};
        ship.CheeseVel={ship.CheeseVel.x-ship.CheeseVel.x/50,ship.CheeseVel.y-ship.CheeseVel.y/50};
    }

    switch(moving){
    case 1:
        ship.AngularVel=-0.2;
        break;
    case 2:
        ship.AngularVel=0.2;
        break;
    case 0:
        ship.AngularVel=0;
        break;
    }
for(int x=0;x<Asteroids.size();x++){
    asterpoints(g,Asteroids[x][0],Astangle,Asterscale);
}
//    AsStart=AsStart+roidvel;
CalcAsteroids(Asteroids,Bullet,g,SwissCheese,score);

for(int r=0;r<SwissCheese.size();r++){
asterpoints(g,SwissCheese[r][0],Astangle,1);
SwissCheese[r][0]=SwissCheese[r][0]+SwissCheese[r][1];
}

        ship.angle=ship.angle+ship.AngularVel;
        ship.CheeseVel=ship.CheeseVel+ship.CheeseAcc;
        ship.pos=ship.pos+ship.CheeseVel;
        drawShip(g,ship.pos,1,ship.angle, Lines);

        if(ship.pos.x>g.width()){
            ship.pos.x=0;
        }
        if(ship.pos.y>g.height()){
            ship.pos.y=0;
        }
        if(ship.pos.x<0){
            ship.pos.x=g.width();
        }
        if(ship.pos.y<0){
            ship.pos.y=g.height();
        }

        if(AsteroidCollision(Asteroids,SwissCheese,ship,g)==false){
            score=score;
            break;
        }
        if(g.isKeyPressed(' ') &&   frames%2==0){
            AmntBullets++;
            posvel={ship.pos,CheeseDirection * 10};
            Bullet.push_back(posvel);
            posvel.clear();
        }

        Calc(Bullet,g);
         drawbullets(Bullet,g);
        frames=frames+1;
         g.text(g.width()/2,g.height()-100,25,"Score: "+to_string(score),BLUE);
 }

    while(g.draw()){
        g.clear();
        g.text(g.width()/2-300,g.height()/2,50,"Good Game, Final-score:"+to_string(score),GREEN);
    }
}
int main(int /*argc*/, char** /*argv*/)
{
    srand(time(NULL));
    Graphics g("Graphics", 600, 600, graphicsMain);
    return 0;
}
