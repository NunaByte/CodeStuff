#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;

//Function Prototypes
void gameStart();
void displayBoard(char *array);
void updateBoard1(int input, char *array);
void updateBoard2(int input, char *array);
void playerOneInput(int &input);
void playerTwoInput(int &input);
// Checker Prototypes
bool boardCheckHoriO(char *array);
bool boardCheckVertO(char *array);
bool boardCheckDiagO(char *array);
bool boardCheckVertX(char *array);
bool boardCheckHoriX(char *array);
bool boardCheckDiagX(char *array);
// Check X Check O Prototypes
bool boardCheckX(char *array);
bool boardCheckO(char *array);



//Main Function

int main()
{
    
    int playerOneIn{0};
    int playerTwoIn{0};
    bool playing = true;
    bool hasWon{false};
    
    while(playing)
    {
        system("CLS");
        char board[9] = {'*','*','*','*','*','*','*','*','*'};
        gameStart();

        while(hasWon != true)
        {
        displayBoard(board);
        //Input for first player
        playerOneInput(playerOneIn);
            
        system("CLS");
        gameStart();
        updateBoard1(playerOneIn,board);
        displayBoard(board);
        if(boardCheckX(board))
            {
                cout << "Player 1 has won!!" << endl;
                break;
            }
        //Input for second player
        playerTwoInput(playerTwoIn);
            
        system("CLS");
        gameStart();
        updateBoard2(playerTwoIn,board);
            if(boardCheckO(board))
            {
                cout << "Player 2 has won!!" << endl;
                break;
            }
        }
        int end;
        cout << "Would you like to play again(-1 for no, 1 for yes): ";
        cin >> end;
        if(end == -1)
        {
            hasWon = true;
            playing = false;

        }
        if(end == 1)
        {
            hasWon = false;
        }

    }  
}

//Functions

void gameStart()
{
    cout << "######################" << endl;
    cout << "TIC TAC TOE" << endl;
    cout << "######################" << endl;
    
}

void displayBoard(char *array)
{

    for(int i = 0; i < 9; i++)
    {
        cout << array[i] << " ";
        if(i == 2 || i == 5)
        {
            cout << endl;
        }
    }

    cout << "\nPlayer One: X  Player Two: O\n" << endl;
}

void playerOneInput(int &input)
{
    cout << "Player 1 Entry(1-8): ";
    cin >> input;
    cout << endl;
    
}

void playerTwoInput(int &input)
{
    cout << "Player 2 Entry(1-8): ";
    cin >> input;
    cout << endl;
    
}

void updateBoard1(int input, char *array)
{
    array[input] = 'X';
}

void updateBoard2(int input, char *array)
{
    array[input] = 'O';
}


//Check if X has won
bool boardCheckX(char *array)
{
    bool horizontal = boardCheckHoriX(array);
    bool vertical = boardCheckVertX(array);
    bool diagonal = boardCheckDiagX(array);

    if(horizontal || vertical || diagonal)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Check if O has won
bool boardCheckO(char *array)
{
    bool horizontal = boardCheckHoriO(array);
    bool vertical = boardCheckVertO(array);
    bool diagonal = boardCheckDiagO(array);

    if(horizontal || vertical || diagonal)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//Check for any horizontal wins for X
bool boardCheckHoriX(char *array)
{
    int horiCheck1{0};
    int horiCheck2{0};
    int horiCheck3{0};
    for(int i = 0; i < 9; i++)
    {
        if(i <= 2)
        {
            if(array[i] == 'X')
            {
                horiCheck1++;
            }  
        }
        if(i <= 5 && i > 2)
        {
            if(array[i] == 'X')
            {
                horiCheck2++;
            }  
        }
        if(i <= 8 && i > 5)
        {
            if(array[i] == 'X')
            {
                horiCheck3++;
            }  
        }
    }
    if((horiCheck1 == 3) || (horiCheck2 == 3) || (horiCheck3 == 3))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Check for any horizontal wins for O
bool boardCheckHoriO(char *array)
{
    int horiCheck1{0};
    int horiCheck2{0};
    int horiCheck3{0};
    for(int i = 0; i < 9; i++)
    {
        if(i <= 2)
        {
            if(array[i] == 'O')
            {
                horiCheck1++;
            }  
        }
        if(i <= 5 && i > 2)
        {
            if(array[i] == 'O')
            {
                horiCheck2++;
            }  
        }
        if(i <= 8 && i > 5)
        {
            if(array[i] == 'O')
            {
                horiCheck3++;
            }  
        }
    }
    if((horiCheck1 == 3) || (horiCheck2 == 3) || (horiCheck3 == 3))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Check for any vertical wins for X
bool boardCheckVertX(char *array)
{
    int vertCheck1{0};
    int vertCheck2{0};
    int vertCheck3{0};
    for(int i = 0; i < 9; i++)
    {
        if((i == 0) || (i == 3) || (i == 6)  )
        {
            if(array[i] == 'X')
            {
                vertCheck1++;
            }
        }
        if((i == 1) || (i == 4) || (i == 7)  )
        {
            if(array[i] == 'X')
            {
                vertCheck2++;
            }
        }
        if((i == 2) || (i == 5) || (i == 8)  )
        {
            if(array[i] == 'X')
            {
                vertCheck2++;
            }
        }
    }
    if((vertCheck1 == 3) || (vertCheck2 == 3) || (vertCheck3 == 3))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Check for any vertical wins for O
bool boardCheckVertO(char *array)
{
    int vertCheck1{0};
    int vertCheck2{0};
    int vertCheck3{0};
    for(int i = 0; i < 9; i++)
    {
        if((i == 0) || (i == 3) || (i == 6)  )
        {
            if(array[i] == 'O')
            {
                vertCheck1++;
            }
        }
        if((i == 1) || (i == 4) || (i == 7)  )
        {
            if(array[i] == 'O')
            {
                vertCheck2++;
            }
        }
        if((i == 2) || (i == 5) || (i == 8)  )
        {
            if(array[i] == 'O')
            {
                vertCheck2++;
            }
        }
    }
    if((vertCheck1 == 3) || (vertCheck2 == 3) || (vertCheck3 == 3))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Check for any diagonal wins for X
bool boardCheckDiagX(char *array)
{
    int diagCheck1{0};
    int diagCheck2{0};

    for(int i = 0; i < 9; i++)
    {
        if((i == 0) || (i == 4) || (i == 8))
        {
            if(array[i] == 'X')
            {
                diagCheck1++;
            }
        }
        if((i == 2) || (i == 4) || (i == 6))
        {
            if(array[i] == 'X')
            {
                diagCheck2++;
            }
        }
    }
    if((diagCheck1 == 3) || (diagCheck2 == 3))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Check for any diagonal wins for O
bool boardCheckDiagO(char *array)
{
    int diagCheck1{0};
    int diagCheck2{0};

    for(int i = 0; i < 9; i++)
    {
        if((i == 0) || (i == 4) || (i == 8))
        {
            if(array[i] == 'O')
            {
                diagCheck1++;
            }
        }
        if((i == 2) || (i == 4) || (i == 6))
        {
            if(array[i] == 'O')
            {
                diagCheck2++;
            }
        }
    }
    if((diagCheck1 == 3) || (diagCheck2 == 3))
    {
        return true;
    }
    else
    {
        return false;
    }
}