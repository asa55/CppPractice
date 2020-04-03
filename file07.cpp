#include <forward_list>
#include <chrono>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <numeric>
#include <random>


class Player
{
public:
    int x, y;
    Player()
    : x(0), y(0) {}
    ~Player() {}
};


int main(){
    
    Player me;

    std::cout << me.y << std::endl;
    
}