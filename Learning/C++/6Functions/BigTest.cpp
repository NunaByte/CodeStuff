//Testing a 70% chance
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

int main()
{
    enum class GameState : unsigned int {Running, GAMEOVER};
    GameState::Running;

    unsigned int frequency1{0};
    unsigned int frequency2{0};
    int roll;
    srand(static_cast<unsigned int>(time(0)));

    for(unsigned int j{1}; j <= 20; ++j)
    {
        roll = 1 + rand() % 10;

        if(roll <= 7)
            frequency1++;
        if(roll > 7)
            frequency2++;
    }

    cout << "Upgrade Succeded: " << frequency1 << " times" << endl;
    cout << "Upgrade Failed: " << frequency2 << " times" << endl;
}