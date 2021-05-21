#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <time.h>
class Stopwatch
{
public:
    time_t start;
    time_t stop;
    int totaltime;
public:
    void startwatch();
    void stopwatch();
    int calculation();
};

#endif // STOPWATCH_H
