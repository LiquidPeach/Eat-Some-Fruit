/**
MATRIX MANIPULATION TO MAKE A SNAKE GAME
**/

#include <iostream>
#include <stdlib.h> //for system("CLS") and rand()
#include<conio.h> //for _kbhit() and _getch
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    //center snake head
    x = width/2;
    y = height/2;

    //randomly placed fruit
    fruitX = rand()% width;
    fruitY = rand()% height;
    score = 0;

}

void Draw()
{
    system("CLS"); //clear screen, or else get an endless matrix of the board

    //top row of #
    for(int i=0; i<width+2; i++)
        cout<<"#";
        cout<<endl;

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
    //left wall of #
            if (j == 0)
                cout<<"#";

            if (i == y && j == x)
            cout<<"O";
                else if (i == fruitY && j == fruitX)
                cout<<"@";
                    else
                    cout<<" ";
    //right wall of #
        if (j == width - 1)
            cout<<"#";
        }
        cout<<endl;
    }
    //bottom row of #
    for(int i=0; i<width+2; i++)
        cout<<"#";
        cout<<endl;

    cout<<"Score: "<<score;
}

void Input()
{
    if (_kbhit()) //keyboard input
    {
        switch (_getch()) //_getch is a Windows specific solution
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'w':
            dir = UP;
            break;

        //to exit game
        case 'x':
            gameOver = true;
        }
    }

}

void Logic()
{
    switch(dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case DOWN:
            y++;
            break;
        case UP:
            y--;
            break;
        default:
            break;
    }
    if (x > width || x < 0 || y > height || y < 0 && score > 0)
    {
        //reset the snake back to center and remove 10 points
        x = width/2;
        y = height/2;
        score -=10;
    }
    if (score < 0)
    {
        gameOver = true;
        cout<<" GAME OVER"<<endl;
    }
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand()% width;
        fruitY = rand()% height;
    }
}

int main ()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
    return 0;
}
