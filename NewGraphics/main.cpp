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



void graphicsMain(Graphics& g){

    complex<double> cheese1;
    complex<double> cheese2;
    complex<double> cheese3;
    complex<double> cheese4;
    complex<double> cheese5;
    complex<double> cheese6;
    complex<double> cheese7;
    complex<double> cheese8;
    double m;
    double b;
    vector<Vec2d> Points{
        {-20,-20},
        {0,-10},
        {20,-20},
        {0,30}
    };
    for(int i=0;i<Points.size();i++){
        Points[i]=Points[i]+Vec2d{(g.width()/2),(g.height()/2)};
    }


    while (g.draw()) {
        g.clear();
        Vec2d pos=g.mousePos();
        g.polygon(Points,GREEN);
        g.ellipseC(pos,26.13,26.13,WHITE,BLUE);



    }
}


int main(int /*argc*/, char** /*argv*/)
{
    // main should be empty except for the following line:
    Graphics g("Graphics", 600, 600, graphicsMain);
    return 0;
}



