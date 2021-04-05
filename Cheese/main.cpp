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

    Vec2d MouseThingy(Graphics& g, int BHeight,int BWidth, Vec2d pos, Vec2d& Mice){
        double row=round((pos.y-g.height()+BHeight+2)/-(BHeight+2));
        double column=round(pos.x-2)/(BWidth+2);
        Mice={column, row};
        return Mice;
    }

    void Incolor(Graphics& g, vector<vector<int>>& Lights, Vec2d Mice,int& x, vector<vector<bool>>& BroTrustMe){
                  int i =0;
        for (const Event& e : g.events())
            {
          switch (e.evtType)
                {
                case EvtType::MousePress:
              if(x%2==1){
                  while(i+1<=5 && BroTrustMe[i+1][Mice.x]==false){
                 i=i+1;
                }
                if(Lights[0][Mice.x]!=0){
                }
                else{
                      Lights[i][Mice.x]=1;
                      BroTrustMe[i][Mice.x]=true;
                }
              }
              if(x%2==0){
                  while(i+1<=5 && BroTrustMe[i+1][Mice.x]==false){
                 i=i+1;
                }
                  if(Lights[0][Mice.x]!=0){}
                  else{
                      Lights[i][Mice.x]=2;
                      BroTrustMe[i][Mice.x]=true;
                  }
              }
              if(i>=1){
               x=x+1;
              }
                    break;
          default:
              break;
            }
          break;
    }
    }
    Vec2d CallToXY(Graphics& g, int BWidth, int BHeight, int row, int column){
                int CWidth = BWidth+2;
                int Rheight = BHeight+2;
                int LM = 2;
                int TM = 2;
                int y = (g.height()-(BHeight + TM + row * Rheight));
                int x = (column*CWidth + LM);
                return {x+2,y+3};
    }
    bool Win(vector<vector<int>>& Lights, bool& win){
        for(int y=5;y>=0;y--){
            for(int i=6;i>=0;i--){
                if(Lights[y][i]!=0){
                    if(y+3<=5 &&((Lights[y][i]==Lights[y+1][i]) && (Lights[y+1][i]==Lights[y+2][i]) && (Lights[y+2][i]==Lights[y+3][i]))){

                        win=true;
                        Lights[y][i]=3;
                        Lights[y+1][i]=3;
                        Lights[y+1][i]=3;
                        Lights[y+1][i]=3;
                        return win;
                    }
                    else if(y-3>=0 &&(Lights[y][i]==Lights[y-1][i] && Lights[y-1][i]==Lights[y-2][i] && Lights[y-2][i]==Lights[y-3][i]) ){
                                            win=true;
                                            Lights[y][i]=3;
                                            Lights[y-1][i]=3;
                                            Lights[y-2][i]=3;
                                            Lights[y-3][i]=3;
                        return win;
                    }
                    else if(i+3<=6 &&(Lights[y][i]==Lights[y][i+1] && Lights[y][i+1]==Lights[y][i+2] && Lights[y][i+2]==Lights[y][i+3])){
                                            win=true;
                                            Lights[y][i]=3;
                                            Lights[y][i+1]=3;
                                            Lights[y][i+2]=3;
                                            Lights[y][i+3]=3;
                        return win;
                    }
                    else if(i-3>=0 &&(Lights[y][i]==Lights[y][i-1] && Lights[y][i-1]==Lights[y][i-2] && Lights[y][i-2]==Lights[y][i-3])){
                                            win=true;
                                            Lights[y][i]=3;
                                            Lights[y][i-1]=3;
                                            Lights[y][i-2]=3;
                                            Lights[y][i-3]=3;
                        return win;
                    }
                    else if(y+3<=5 && i+3<=6 &&(Lights[y][i]==Lights[y+1][i+1] && Lights[y+1][i+1]==Lights[y+2][i+2] && Lights[y+2][i+2]==Lights[y+3][i+3])){
                                            win=true;
                                            Lights[y][i]=3;
                                            Lights[y+1][i+1]=3;
                                            Lights[y+2][i+2]=3;
                                            Lights[y+3][i+3]=3;
                        return win;
                    }
                    else if(y-3>=0 && i+3<=6 &&(Lights[y][i]==Lights[y-1][i+1] && Lights[y-1][i+1]==Lights[y-2][i+2] && Lights[y-2][i+2]==Lights[y-3][i+3])){
                                            win=true;
                                            Lights[y][i]=3;
                                            Lights[y-1][i+1]=3;
                                            Lights[y-2][i+2]=3;
                                            Lights[y-3][i+3]=3;
                        return win;
                    }
                    else if(y+3<=5 && i-3>=0 &&(Lights[y][i]==Lights[y+1][i-1] && Lights[y+1][i-1]==Lights[y+2][i-2] && Lights[y+2][i-2]==Lights[y+3][i-3])){
                                            win=true;
                                            Lights[y][i]=3;
                                            Lights[y+1][i-1]=3;
                                            Lights[y+2][i-2]=3;
                                            Lights[y+3][i-3]=3;
                        return win;
                    }
                    else if(y-3>=0 &&i-3>=0 &&(Lights[y][i]==Lights[y-1][i-1] && Lights[y-1][i-1]==Lights[y-2][i-2] && Lights[y-2][i-2]==Lights[y-3][i-3])){
                                            win=true;
                                            Lights[y][i]=3;
                                            Lights[y-1][i-1]=3;
                                            Lights[y-2][i-2]=3;
                                            Lights[y-3][i-3]=3;
                        return win;
                    }
                }
            }
        }
    }
    void graphicsMain(Graphics& g)
    {
                int BWidth = 40;
                int BHeight = 40;
                        int numColumns = 7;
                        int numRows = 6;
        int x=0;
                 vector<vector<int>> Lights(numRows, vector<int>(numColumns,0));
                 bool win=false;
                 vector<vector<bool>> BroTrustMe(numRows,vector<bool>(numColumns,false));
     while(g.draw()){
         g.clear();
         Color blue= Color(68,68,68);
                Vec2d  pos=g.mousePos();
                Vec2d Mice;
                 Vec2d Cheese=MouseThingy(g,BHeight,BWidth,pos,Mice);
                 Incolor(g, Lights, Mice,x,BroTrustMe);
                 g.text(g.width()/2,0,100,to_string(Cheese.x)+" : "+to_string(Cheese.y),WHITE);
                 Win(Lights,win);

                 for (int row=0;row < numRows; row++) {
                     for (int column=0;column < numColumns; column++) {


                         if(Lights[row][column]==1){
                             blue=RED;
                         }
                         else if(Lights[row][column]==2){
                             blue=YELLOW;
                         }
                         else if(Lights[row][column]==3){
                             blue=Color(251,72,196);
                         }
                         else{
                             blue=Color(0,255,0);
                         }
                             g.rect(CallToXY(g,BWidth, BHeight, row, column), BWidth, BHeight, BLUE, blue);
                 }
                 }

                 if(Win(Lights,win)==true){

                     break;
                                      Sleep(1000);
                 }
     }
     while(g.draw()){
         if(x%2==1){
         g.text(g.width()/2,g.height()-100,100,"Yellow Wins",BLUE);
         }
         else{
         g.text(g.width()/2,g.height()-100,100,"Red Wins",BLUE);
         }
     }
     }

    int main(int /*argc*/, char** /*argv*/)
    {
        srand(time(NULL));
        Graphics g("Graphics", 1200, 800, graphicsMain);
        return 0;
    }
