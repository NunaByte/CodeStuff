#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "Utils.h"
#include "Utils2.h"
using namespace std;

const char * INPUT_ERROR_STRING = "Input error! Please try again.";

struct Card
{
    string cardFace;
    int value;
    bool isUsed;
};

struct Selection
{
    int row;
    int col;
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
    PGS_WIN = 0,
    PGS_LOSE,
    PGS_PUSH,
    PGS_NONE
};

struct Dealer
{
    char name;
    Card holding[4];
    int cardCount = 0;
    int cardValue = 0;
    PlayerState playerState;
    PlayerGameState state;
    int balance;
};

struct Player
{
    char name;
    Card holding[4];
    int cardCount = 0;
    int cardValue = 0;
    bool stillPlaying = true;
    PlayerState playerState;
    PlayerGameState state;
    int balance;
};


/*
    Step 1

    initDealer(dealer);
    initPlayer(player);
    bool stillPlaying = true;

    do
    {
        PlayGame()

    }while(stillPlaying);

    Play Game
    ---------------------------
    SetCards(); //Set the values and the faces of the cards in an array
    DealCards(player, dealer);
    calcTotal();
    checkHasWon(player, dealer);

    ask player if they want to hit //Take another card
    if(player wants to hit)
    {
        DealCards(player)
        checkHasWon(player, dealer);
    }

    while(player and dealer has not won)
    {
        DealCards(dealer)
        checkHasWon(player, dealer);
    }

    Ask player if they want to play another round
    if(yes)
    {
        stillPlaying = true;
    }
    else
    {
        stillPlaying = false;
    }

    Check Has Won
    -----------------------------
    setPlayerGameState(player,dealer);

    if(player has won and the dealer has not)
    {
        Congrats player has won the round!
    }
    else if(dealer has won and the player has not)
    {
        The dealer has won the round :(
    }
    else if(dealer has won and the player has won)
    {
        There are no victors this round
    }
    -----------------------------------------
*/

void PlayGame(Player &player,Dealer &dealer,Card cards[4][13]);
void SetCards(Card cards[4][13]);
void DealCards(Player &player, Dealer &dealer, Card cards[4][13], int count);
void DealCards(Player &player, Card cards[4][13], int count);
void DealCards(Dealer &dealer, Card cards[4][13], int count);
void calcTotal(Player &player, Dealer &dealer);
bool allCardsUsed(Card cards[4][13]);
void displayLogo();
bool checkHasWon(Player &player);
bool checkHasWon(Dealer &dealer);
void setPlayerGameState(Player &player, Dealer &dealer);
void displayHand(Player &player);
void displayHand(Dealer &dealer);

int main()
{
    srand(time(NULL));

    Dealer dealer;
    Player player;
    Card cards[4][13];
    
    do
    {
        PlayGame(player, dealer, cards);

    }while(player.stillPlaying);

    return 0;
}



void PlayGame(Player &player,Dealer &dealer,Card cards[4][13])
{
    ClearScreen();
    displayLogo();
    SetCards(cards);
    DealCards(player, dealer, cards, 3);
    calcTotal(player, dealer);
    setPlayerGameState(player, dealer);

    displayHand(player);
    displayHand(dealer);

    if(checkHasWon(player))
    {
        cout << "Player has won with a BLACKJACK!";
    }
    else if(checkHasWon(dealer))
    {
        cout << "Dealer has won with a BLACKJACK :(";
    }
    else if(player.state == PGS_PUSH && dealer.state == PGS_PUSH)
    {
        cout << "There is a draw, no one wins this round";
    }

    while(!(checkHasWon(player)) && !(checkHasWon(dealer)))
    {
        char validInput[] = {'Y','N'};
        char playerChoice = GetCharacter("Player would you like to hit? (Y or N): ",INPUT_ERROR_STRING,validInput,1,CC_UPPER_CASE);
        if(playerChoice == 'Y')
        {
            DealCards(player, cards, 1);
            cout << "Player is dealt an extra card";
            setPlayerGameState(player, dealer);
            ClearScreen();
            displayLogo();
            displayHand(player);
            displayHand(dealer);
            WaitForKeyPress();
        }
        else
        {
            ClearScreen();
            displayLogo();
            cout << "Player decided to stay";
            WaitForKeyPress();
        }
        //Check for win after player hits
        if(checkHasWon(player))
        {
            cout << "Player has won!";
        }
        else if(checkHasWon(dealer))
        {
            cout << "Dealer has won, the player has bust :(";
        }
        else if(player.state == PGS_PUSH && dealer.state == PGS_PUSH)
        {
            cout << "There is a draw, no one wins this round";
            break;
        }
        //Dealer hits till win or lose
        while(!(checkHasWon(player)) && !(checkHasWon(dealer)))
        {
            DealCards(dealer, cards, 1);
            cout << "Dealer draws another card";
            setPlayerGameState(player, dealer);
            ClearScreen();
            displayLogo();
            displayHand(player);
            displayHand(dealer);
        }
        //Returns who has won or lost
        if(checkHasWon(dealer))
        {
            cout << "Dealer has won the round :(";
        }
        else if(checkHasWon(player))
        {
            cout << "Player has won!, the dealer has bust!";
        }
        else if(player.state == PGS_PUSH && dealer.state == PGS_PUSH)
        {
            cout << "There is a draw, no one wins this round";
            break;
        }
    }

    char playerRoundChoice;
    char validInput[] = {'Y','N'};
    playerRoundChoice = GetCharacter("Would you like to play another round? (Y or N): ",INPUT_ERROR_STRING,validInput,1,CC_UPPER_CASE);

    if(playerRoundChoice == 'Y')
    {
        player.stillPlaying = true;
    }
    else
    {
        player.stillPlaying = false;
        cout << "Thank you for playing Black Jack!";
        WaitForKeyPress();
    }


}


//Functions to deal cards to dealer or player
void DealCards(Player &player, Dealer &dealer, Card cards[4][13], int count)
{
    Selection deal;

    for(int i = 0; i < count; i++)
    {
        //Deal to player
        do
        {
            deal.row = rand() % 4;
            deal.col = rand() % 13;

            if(cards[deal.row][deal.col].isUsed != true)
            {
                player.holding[player.cardCount + i] = cards[deal.row][deal.col];
                cards[deal.row][deal.col].isUsed = true;
                player.cardCount++;
            }

            if(allCardsUsed(cards))
                break;

        }while(cards[deal.row][deal.col].isUsed == false);

        //Deal to dealer
        do
        {
            deal.row = rand() % 4;
            deal.col = rand() % 13;

            if(cards[deal.row][deal.col].isUsed != true)
            {
                dealer.holding[dealer.cardCount + i] = cards[deal.row][deal.col];
                cards[deal.row][deal.col].isUsed = true;
                dealer.cardCount++;
            }

            if(allCardsUsed(cards))
                break;

        }while(cards[deal.row][deal.col].isUsed == false);
     
     if(allCardsUsed(cards))
            break;
    }
}

void DealCards(Player &player, Card cards[4][13], int count)
{
    Selection deal;

    for(int i = 0; i < count; i++)
    {
        do
        {
            deal.row = rand() % 4;
            deal.col = rand() % 13;

            if(cards[deal.row][deal.col].isUsed != true)
            {
                player.holding[player.cardCount + i] = cards[deal.row][deal.col];
                cards[deal.row][deal.col].isUsed = true;
                player.cardCount++;
            }

            if(allCardsUsed(cards))
                break;

        }while(cards[deal.row][deal.col].isUsed == false);
     
     if(allCardsUsed(cards))
            break;
    }

}

void DealCards(Dealer &dealer, Card cards[4][13], int count)
{
    Selection deal;

    for(int i = 0; i < count; i++)
    {
        do
        {
            deal.row = rand() % 4;
            deal.col = rand() % 13;

            if(cards[deal.row][deal.col].isUsed != true)
            {
                dealer.holding[dealer.cardCount + i] = cards[deal.row][deal.col];
                cards[deal.row][deal.col].isUsed = true;
                dealer.cardCount++;
            }

            if(allCardsUsed(cards))
                break;

        }while(cards[deal.row][deal.col].isUsed == false);
     
     if(allCardsUsed(cards))
            break;
    }
}

bool allCardsUsed(Card cards[4][13])
{
    int used = 0;
    for(int r = 0; r < 4; r++)
    {
        for(int c = 0; c < 13; c++)
        {
            if(cards[r][c].isUsed == true)
            {
                used++;
            }
        }
    }
    if(used == 52)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void calcTotal(Player &player, Dealer &dealer)
{
    int sum1{0};
    int sum2{0};

    for(int i = 0; i < player.cardCount; i++)
    {
        sum1 += player.holding[i].value;
    }
    player.cardValue = sum1;

    for(int i = 0; i < dealer.cardCount; i++)
    {
        sum2 += dealer.holding[i].value;
    }
    dealer.cardValue = sum2;
}

void setPlayerGameState(Player &player, Dealer &dealer)
{
    player.state = PGS_NONE;
    dealer.state = PGS_NONE;

    int playerValue = player.cardValue;
    int dealerValue = dealer.cardValue;

    if((playerValue > dealerValue) && (playerValue == 21))
    {
       player.state = PGS_WIN;
    }
    else if((dealerValue > playerValue) && (dealerValue == 21))
    {
       dealer.state = PGS_WIN;
    }
    else if((dealerValue == 21) && (playerValue == 21))
    {
        dealer.state = PGS_PUSH;
        player.state = PGS_PUSH;
    }
    //////////////////////////////////////////////////
    if((playerValue > dealerValue) && (playerValue > 21))
    {
        player.state = PGS_LOSE;
    }
    else if((dealerValue > playerValue) && (dealerValue > 21))
    {
        dealer.state = PGS_LOSE;
    }
}

bool checkHasWon(Player &player)
{
    if(player.state == PGS_WIN)
    {
        return true;
    }
    else if(player.state == PGS_LOSE)
    {
        return false;
    }
    else
    {
        return false;
    }
}

void displayHand(Player &player)
{
    cout << "PLAYER HAND" << endl;
    cout << "_____________" << endl;

    for(int i = 0; i < player.cardCount; i++)
    {
        cout << player.holding[i].cardFace << " " << player.holding[i].value;
        cout << endl;
    }

    cout << "HAND TOTAL: " << player.cardValue;
    cout << endl;
    cout << "----------------------------------------";
    cout << endl;
    
}

void displayHand(Dealer &dealer)
{
    cout << "DEALER HAND" << endl;
    cout << "_____________" << endl;

    for(int i = 0; i < dealer.cardCount; i++)
    {
        cout << dealer.holding[i].cardFace << " " << dealer.holding[i].value;
        cout << endl;
    }

    cout << "HAND TOTAL: " << dealer.cardValue;
    cout << endl;
    cout << "----------------------------------------";
}

bool checkHasWon(Dealer &dealer)
{
    if(dealer.state == PGS_WIN)
    {
        return true;
    }
    else if(dealer.state == PGS_LOSE)
    {
        return false;
    }
    else
    {
        return false;
    }
}



void displayLogo()
{
    cout << " _     _            _    _            _ " << endl;
    cout << "| |   | |          | |  (_)          | |" << endl;
    cout << "| |__ | | __ _  ___| | ___  __ _  ___| | __" << endl;
    cout << "| '_ \\| |/ _` |/ __| |/ / |/ _` |/ __| |/ /" << endl;
    cout << "| |_) | | (_| | (__|   <| | (_| | (__|   < " << endl;
    cout << "|_.__/|_|\\__,_|\\___|_|\\_\\ |\\__,_|\\___|_|\\_\\" << endl;
    cout << "                       _/ |                " << endl;
    cout << "                      |__/                " << endl;
}

void SetCards(Card cards[4][13])
{
    for(int r = 0; r < 4; r++)
    {
        for(int c = 0; c < 13; c++)
        {
            if(r == 0)
            {
                cards[r][c].cardFace = "Clover";
                if((c < 10) && (c != 0))
                {
                    cards[r][c].value = c+1;
                }
                else if(c == 0)
                {
                    cards[r][c].value = 11;
                }
                else
                {
                    cards[r][c].value = 10;
                }
                cards[r][c].isUsed = false;
            }
            else if(r == 1)
            {
                cards[r][c].cardFace = "Spade";
                if((c < 10) && (c != 0))
                {
                    cards[r][c].value = c+1;
                }
                else if(c == 0)
                {
                    cards[r][c].value = 11;
                }
                else
                {
                    cards[r][c].value = 10;
                }
                cards[r][c].isUsed = false;
            }
            else if(r == 2)
            {
                cards[r][c].cardFace = "Heart";
                if((c < 10) && (c != 0))
                {
                    cards[r][c].value = c+1;
                }
                else if(c == 0)
                {
                    cards[r][c].value = 11;
                }
                else
                {
                    cards[r][c].value = 10;
                }
                cards[r][c].isUsed = false;
            }
            else if(r == 3)
            {
                cards[r][c].cardFace = "Daimond";
                if((c < 10) && (c != 0))
                {
                    cards[r][c].value = c+1;
                }
                else if(c == 0)
                {
                    cards[r][c].value = 11;
                }
                else
                {
                    cards[r][c].value = 10;
                }
                cards[r][c].isUsed = false;
            }
        }
    }
}
