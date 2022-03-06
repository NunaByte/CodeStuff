#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Card
{
    char cardBuild[10][5];
    int value;
};

struct CardType
{
    Card cards[4];
};

enum PlayerState
{
    PS_BUST = 0,
    PS_STAY,
    PS_HIT,
    PS_NONE
};

enum PlayerGameState
{
    PGM_WIN = 0,
    PGM_LOSE,
    PGM_PUSH
};

struct Dealer
{
    char name;
    Card cards[52];
    Card *holding = new Card[cardCount];
    int cardCount;
    int cardValue;
    PlayerState playerState;
    PlayerGameState state;
    int balance;
};

struct Player
{
    char name;
    CardType *holding = new CardType[cardCount];
    int cardCount;
    int cardValue;
    PlayerState playerState;
    PlayerGameState state;
    int balance;
};


/*
    Step 1
    setDealer();
    setPlayer();
    
    do
    {
        PlayGame();

    }while(stillPlaying)

    PlayGame
    -----------------------------

    DealCards(player, PlayerState);
    DealCards(dealer, PlayerState);
    calculateTotal(player);
    DisplayCards(player, dealer);


    hasLost(player);
    hasWon(player);

    while(no one has won or lost)
    {
        Prompt player with option to hit

        if(player hits)
        {
            DealCards(player, PlayerState);
        }
        else
        {
            player.playerState = PS_STAY;
        }


        do
        {
            Deal cards to the dealer
            bool lost = hasLost(dealer);
            bool won = hasWon(dealer);

            if(lost)
            {
                dealer.state = PGM_LOST;
                player.state = PGM_WON;
            }
            else if(won)
            {
                dealer.state = PGM_WON;
                player.state = PGM_LOST;
            }

        }while(The dealer has not won or lost and their card total is not greater than or equal to 17);

        if(dealer.state = PGM_LOST)
        {
            Player has won the round
        }
        else
        {
            Dealer has won the round
        }

      stillPlaying();
    }
*/


int main()
{

    for(int r = 0; r < 5; r++)
    {
        for(int c = 0; c < 5; c++)
        {
            if(r == 1 && c == 1)
            {
                cout << "1";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }


    return 0;
}