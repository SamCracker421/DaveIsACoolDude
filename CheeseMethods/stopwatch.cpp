#include "stopwatch.h"
#include <time.h>
#include <iostream>
#include <cmath>

void Stopwatch::startwatch(){
   start=time(NULL);
}
void Stopwatch::stopwatch(){
    stop=time(NULL);
}
int Stopwatch::calculation(){
    totaltime=stop-start;
    return totaltime;
}
