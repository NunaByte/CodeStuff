#include <iostream>
#include <cstring>
#include "Utils.h"
#include "Utils2.h"

using namespace std;


const char * INPUT_ERROR_STRING = "Input error! Please try again.";


enum
{
    AIRCRAFT_CARRIER_SIZE = 5,
    BATTLESHIP_SIZE = 4,
    CRUISER_SIZE = 3,
    DESTROYER_SIZE = 3,
    SUBMARINE_SIZE = 2,

    BOARD_SIZE = 10,
    NUM_SHIPS = 5,
    PLAYER_NAME_SIZE = 8, //Player1, Player2
    MAX_SHIP_SIZE = AIRCRAFT_CARRIER_SIZE
};


enum ShipType
{
    ST_NONE = 0,
    ST_AIRCRAFT_CARRIER,
    ST_BATTLESHIP,
    ST_CRUISER,
    ST_DESTROYER,
    ST_SUBMARINE
};

enum ShipOrientationType
{
    SO_HORIZONTAL = 0,
    SO_VERTICAL
};

struct ShipPositionType
{
    int row;
    int col;
};

struct Ship
{
    ShipType shipType;
    int shipSize;
    ShipOrientationType orientation;
    ShipPositionType position;
};

enum GuessType
{
    GT_NONE = 0,
    GT_MISSED,
    GT_HIT
};

struct ShipPartType
{
    ShipType shipType;
    bool isHit;
};

struct Player
{
    char playerName[PLAYER_NAME_SIZE];
    Ship ships[NUM_SHIPS];
    GuessType guessBoard[BOARD_SIZE][BOARD_SIZE];
    ShipPartType shipBoard[BOARD_SIZE][BOARD_SIZE];
};

/*
    Step 1

    InitPlayer(player1, "Player1");
    InitPlayer(player2, "Player2");

    do
    {
        PlayGame(player1, player2);

    }while(WantToPlayAgain());

    PlayGame
    --------

    SetupBoard(player1);
    SetupBoard(player2);

    do
    {
        DrawBoards(currentPlayer);

        do
        {
            Prompt the current player for a guess
            guess = GetGuess();

        }while(!IsGuessIsValid(guess, currentPlayer));

        UpdateBoards(guess, currentPlayer, otherPlayer);
        DrawBoard(currentPlayer); //to see the result of the guess

        if(a ship was sunk on currentPlayer's turn)
        {
            output that the current player sunk that ship
        }
        WaitForKeyPress

        SwitchPlayers();

    }while(!GameIsOver());

    DisplayWinner();


    SetupBoards(player)
    -----------------------

    ClearBoards(player)

    for(all the ships)
    {
        DrawBoards(player)

        currentShip = Get the current ship

        do
        {
            position = Get Board Position for the head of the ship
            orientation = Get the ship orientation

            isValidPlacement = IsValidPlacement(currentShip, position, orientation, player);
            if(!isValidPlacement)
            {
                output to the player that it was not a valid placement
            }
        }while(!isValidPlacement)

        PlaceShipOnBoard(player, currentShip, position, orientation)
    }

    IsValidPlacement(player, currentShip, position, orientation)
    ------------------------------------------------------

    if(orientation == HORIZONTAL)
    {
        for(all the columns the currentShip would take up)
        {
            if(ship will overlap another ship or the ship will be off the board horizontally)
            {
                return false;
            }
        }
    }
    else
    {
        for(all the rows the currentShip would take up)
        {
            if(ship will overlap another ship or the ship will be off the board vertically)
            {
                return false;
            }
        }
    }

    return true;

    PlaceShipOnBoard(player, ship, position, orientation)
    -----------------------------------------

    ship.position = position
    ship.orientation = orientation

    if(orientation == HORIZONTAL)
    {
        for(all the colums the ship would take up)
        {
            set the ship part on the board at position.row and current column
        }
    }
    else
    {
        for(all the rows that the ship would take up)
        {
            set the ship part on the board at current row and position.col
        }
    }

    UpdateBoards(guess, currentPlayer, otherPlayer)
    ----------------------------------------

    if(otherplayer's ship board at guess is a ship)
    {
        //hit
        * set hit on the currentPlayer's guess board
        apply damage to the otherPlayer's shipBoard
        return shipType

    }
    else
    {
        set miss on the currentPlayer's guess board

        return ST_NONE
    }

    IsGameOver(player1, player2)
    ----------------------------

    return AreAllShipsSunk(player1) || AreAllShipsSunk(player2)

    AreAllShipsSunk(player)
    -----------------------------

    for(all the player's ships)
    {
        if(!IsSunk(player, currentShip))
        {
            return false;
        }
    }
    return true;


    IsSunk(player, ship)
    -----------------------

    if(ship.orientation == HORIZONTAL)
    {
        for(columns that ship takes up)
        {
            if(currentPosition on the shipBoard is not hit)
            {
                return false;
            }
        }
    }
    else
    {
        for(rows that the ship takes up)
        {
            if(currentPosition on the shipBoard is not hit)
            {
                return false
            }
        }
    }
    return true;

*/

void InitializePlayer(Player &player, const char *playerName);

void InitializeShip(Ship &ship, int shipSize, ShipType shiptype);

void PlayGame(Player &player1, Player &player2);

bool WantToPlayAgain();

void SetupBoards(Player &player);

void ClearBoards(Player &player);

void DrawBoards(const Player &player);

void DrawSeperatorLine();
void DrawColumnsRow();
void DrawShipBoardRow(const Player &player, int row);
void DrawGuessBoardRow(const Player &player, int row);
char GetGuessRepresentationAt(const Player &player, int row, int col);
char GetShipRepresentationAt(const Player &player, int row, int col);

ShipPositionType GetBoardPosition();
ShipPositionType MapBoardPosition(char rowInput, int colInput);
ShipOrientationType GetShipOrientation();

bool IsValidPlacement(const Player &player, const Ship &currentShip,const ShipPositionType &shipPosition, ShipOrientationType &orientation);


void PlaceShipOnBoard(Player &player,Ship &currentShip,const ShipPositionType &shipPosition, ShipOrientationType orientation);

int main()
{
    Player player1;
    Player player2;

    InitializePlayer(player1, "Player1");
    InitializePlayer(player2, "Player2");

    do
    {
        PlayGame(player1, player2);

    } while(WantToPlayAgain());
    

    return 0;
}


void InitializePlayer(Player &player, const char *playerName)
{
    if(playerName != nullptr && strlen(playerName) > 0)
    {
        strcpy(player.playerName, playerName);
    }

    InitializeShip(player.ships[0], AIRCRAFT_CARRIER_SIZE, ST_AIRCRAFT_CARRIER);

    InitializeShip(player.ships[1], BATTLESHIP_SIZE, ST_BATTLESHIP);

    InitializeShip(player.ships[2], CRUISER_SIZE, ST_CRUISER);

    InitializeShip(player.ships[3], DESTROYER_SIZE, ST_DESTROYER);

    InitializeShip(player.ships[4], SUBMARINE_SIZE, ST_SUBMARINE);
}

void InitializeShip(Ship &ship, int shipSize, ShipType shipType)
{

    ship.shipType = shipType;
    ship.shipSize = shipSize;
    ship.position.row = 0;
    ship.position.col = 0;
    ship.orientation = SO_HORIZONTAL;
}

void PlayGame(Player &player1, Player &player2)
{
    SetupBoards(player1);
    SetupBoards(player2);
}

bool WantToPlayAgain()
{
    char input;

    const char validInput[2] = {'y', 'n'};
    

    input = GetCharacter("Would you like to play again? (y/n): ", INPUT_ERROR_STRING, validInput, 2, CC_LOWER_CASE);

    return input == 'y';
}

const char *GetShipNameForShipType(ShipType shipType)
{
    if(shipType == ST_AIRCRAFT_CARRIER)
    {
        return "Aircraft Carrier";
    }
    else if(shipType == ST_BATTLESHIP)
    {
        return "Battleship";
    }
    else if(shipType == ST_CRUISER)
    {
        return "Cruiser";
    }
    else if(shipType == ST_DESTROYER)
    {
        return "Destroyer";
    }
    else if(shipType == ST_SUBMARINE)
    {
        return "Submarine";
    }

    return "None";
}

void SetupBoards(Player &player)
{
    ClearBoards(player);

    for(int i = 0; i < NUM_SHIPS; i++)
    {
        DrawBoards(player);

        Ship &currentShip = player.ships[i];

        ShipPositionType shipPosition;
        ShipOrientationType orientation;

        bool isValidPlacement = false;

        do
        {
            cout << player.playerName << " Please set the position and orientation for your " << GetShipNameForShipType(currentShip.shipType) << endl;

            shipPosition = GetBoardPosition();
            orientation = GetShipOrientation();

            isValidPlacement = IsValidPlacement(player, currentShip, shipPosition, orientation);

            if(!isValidPlacement)
            {
                cout << "That was not a valid placement. Please try again." << endl;
            }

        } while(!isValidPlacement);

        PlaceShipOnBoard(player, currentShip, shipPosition, orientation);
        
    }

    DrawBoards(player);
}

bool IsValidPlacement(const Player &player, const Ship &currentShip,const ShipPositionType &shipPosition, ShipOrientationType &orientation)
{
    if(orientation == SO_HORIZONTAL)
    {
        for(int c = shipPosition.col; c < (shipPosition.col + currentShip.shipSize); c++)
        {
            if(player.shipBoard[shipPosition.row][c].shipType != ST_NONE || c>= BOARD_SIZE)
            {
                return false;
            }
        }
    }
    else
    {
        for(int r = shipPosition.row; r < (shipPosition.row + currentShip.shipSize); r++)
        {
            if(player.shipBoard[r][shipPosition.col].shipType != ST_NONE || r >= BOARD_SIZE)
            {
                return false;
            }
        }
    }
    return true;
}

void PlaceShipOnBoard(Player &player,Ship &currentShip,const ShipPositionType &shipPosition, ShipOrientationType orientation)
{
    currentShip.position = shipPosition;
    currentShip.orientation = orientation;

    if(orientation == SO_HORIZONTAL)
    {
        for(int c = shipPosition.col; c < (shipPosition.col + currentShip.shipSize); c++)
        {
            player.shipBoard[shipPosition.row][c].shipType = currentShip.shipType;
            player.shipBoard[shipPosition.row][c].isHit = false;
        }
    }
    else
    {
        for(int r = shipPosition.row; r < (shipPosition.row + currentShip.shipSize); r++)
        {
            player.shipBoard[r][shipPosition.col].shipType = currentShip.shipType;
            player.shipBoard[r][shipPosition.col].isHit = false;
        }
    }
}

ShipPositionType MapBoardPosition(char rowInput, int colInput)
{
    int realRow = rowInput - 'A';
    int realCol = colInput - 1;

    ShipPositionType boardPosition;

    boardPosition.row = realRow;
    boardPosition.col = realCol;

    return boardPosition;
}

ShipPositionType GetBoardPosition()
{
    char rowInput;
    int colInput;

    const char validRowsInput[] = {'A','B','C','D','E','F','G','H','I','J'};
    const int validColumnsInput[] = {1,2,3,4,5,6,7,8,9,10};

    rowInput = GetCharacter("Please input a row (A - J): ", INPUT_ERROR_STRING, validRowsInput, BOARD_SIZE, CC_UPPER_CASE);
    colInput = GetInteger("Please input a row (1 - 10): ", INPUT_ERROR_STRING, validColumnsInput, BOARD_SIZE);


    return MapBoardPosition(rowInput, colInput);
}

ShipOrientationType GetShipOrientation()
{

    const char validInput[2] = {'H','V'};

    char input = GetCharacter("Please choose an orientation (H) for Horizontal or (V) for Vertical: ", INPUT_ERROR_STRING, validInput, 2, CC_UPPER_CASE);
    if(input == validInput[0])
    {
        return SO_HORIZONTAL;
    }
    else
    {
        return SO_VERTICAL;
    }
}


void ClearBoards(Player &player)
{
    for(int r = 0; r < BOARD_SIZE; r++)
    {
        for(int c = 0; c < BOARD_SIZE; c++)
        {
            player.guessBoard[r][c] = GT_NONE;
            player.shipBoard[r][c].shipType = ST_NONE; //no ship here
            player.shipBoard[r][c].isHit = false;
        }
    }
}


void DrawSeperatorLine()
{
    cout << " ";

    for(int c = 0; c < BOARD_SIZE; c++)
    {
        cout << "+---";
    }

    cout << "+";
}

void DrawColumsRow()
{
    cout << "  ";

    for(int c = 0; c < BOARD_SIZE; c++)
    {
        int columnName = c + 1;

        cout << " " << columnName << "  ";
    }
}

char GetGuessRepresentationAt(const Player &player, int row, int col)
{
    if(player.guessBoard[row][col] == GT_HIT)
    {
        return '*';
    }
    else if(player.guessBoard[row][col] == GT_MISSED)
    {
        return 'o';
    }
    else
    {
        return ' ';
    }
}


char GetShipRepresentationAt(const Player &player, int row, int col)
{
    if(player.shipBoard[row][col].isHit)
    {
        return '*'; //represents hit
    }

    if(player.shipBoard[row][col].shipType == ST_AIRCRAFT_CARRIER)
    {
        return 'A';
    }
    else if(player.shipBoard[row][col].shipType == ST_BATTLESHIP)
    {
        return 'B';
    }
    else if(player.shipBoard[row][col].shipType == ST_CRUISER)
    {
        return 'C';
    }
    else if(player.shipBoard[row][col].shipType == ST_DESTROYER)
    {
        return 'D';
    }
    else if(player.shipBoard[row][col].shipType == ST_SUBMARINE)
    {
        return 'S';
    }
    else
    {
        return ' ';
    }
}

void DrawShipBoardRow(const Player &player, int row)
{
    char rowName = row + 'A';
    cout << rowName << "|";

    for(int c = 0; c < BOARD_SIZE; c++)
    {
        cout << " " << GetShipRepresentationAt(player, row, c) << " |";
    }
}

void DrawGuessBoardRow(const Player &player, int row)
{
    char rowName = row + 'A';
    cout << rowName << "|";

    for(int c = 0; c < BOARD_SIZE; c++)
    {
        cout << " " << GetGuessRepresentationAt(player, row, c) << " |";
    }
}

void DrawBoards(const Player &player)
{
    DrawColumsRow();

    DrawColumsRow();

    cout << endl;

    for(int r = 0; r < BOARD_SIZE; r++)
    {
        DrawSeperatorLine();

        cout << " ";

        DrawSeperatorLine();

        cout << endl;

        DrawShipBoardRow(player, r);

        cout << " ";

        DrawGuessBoardRow(player, r);

        cout << endl;
    }

    DrawSeperatorLine();

    cout << " ";

    DrawSeperatorLine();

    cout << endl;
}
