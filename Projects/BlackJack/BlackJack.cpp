#include <iostream>
#include <string>
using namespace std;

struct CardType
{
    string cardType;
    int value;
};

struct Dealer
{
    string name;
    CardType cards[52];
    CardType *holding = new CardType[cardCount];
    int cardCount;
    int balance;
};

struct Player
{
    string name;
    int balance;
    CardType *holding = new CardType[cardCount];
    int cardCount;
    int balance;
};

enum PlayerState
{
    PS_BUST = 0,
    PS_STAY,
    PS_HIT
};

enum PlayerGameState
{
    PGM_WIN = 0,
    PGM_LOSE,
    PGM_PUSH
};


int main()
{


    return 0;
}