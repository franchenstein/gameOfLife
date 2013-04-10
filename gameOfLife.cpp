/* 
 * File:   gameOfLife.cpp
 * Author: Franch
 * 
 * Created on March 20, 2013, 8:36 PM
 */

#include "gameOfLife.h"
#include "cell.h"
#include <windows.h>

gameOfLife::gameOfLife() {
    
    //TODO: Turn this into a user input:
    bool hardCodedInit[WIDTH][HEIGHT] =
    {
        0, 1, 0, 0, 0, 0, 1, 0,
        0, 0, 1, 0, 0, 0, 1, 0,
        1, 1, 1, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 1,
        0, 0, 0, 0, 0, 0, 1, 1
    };
    
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            board[i][j].init(hardCodedInit[i][j], i, j);
            cout << board[i][j].getIsAlive() << " ";
        }
        
        cout << endl;
    }
    
    cout << endl;
    
    run();
}

gameOfLife::gameOfLife(const gameOfLife& orig) {
    
}

void gameOfLife::run(){
    
    char check;  //Dummy variable to store cin before going to next state.    
    
    while(!cin.eof())
    {
        //TODO: Turn this into a function storeState()
        //Store current state:
        for(int a = 0; a < WIDTH; a++){
            for(int b = 0; b < HEIGHT; b++){               
                boardCurrent[a][b].init(board[a][b].getIsAlive(), 
                                        board[a][b].getX(),
                                        board[a][b].getY());
            }
        }
        
        //TODO: Turn this into a function updateState()
        //Update state:
        for(int i = 0; i < WIDTH; i++){
            for(int j = 0; j < HEIGHT; j++){
                
                board[i][j].setNumLiveNeighbors(0);
                
                checkNeighborhood(board[i][j]);
                
                board[i][j].deadOrAlive();
                
                cout << board[i][j].getIsAlive() << " ";
                
            }
            
            cout << endl;
            
        }
        cout << endl;
        
        cin.ignore();
    }
    
}

void gameOfLife::checkNeighborhood(cell& center)
{
    //Stores the coordinates of center:
    int x = center.getX();
    int y = center.getY();
    
    //Neighbors:
    //-----------------------------
    //(x-1,y-1) (x, y-1) (x+1, y-1)
    //(x-1, y)  (center) (x+1,y)
    //(x-1,y+1) (x, y+1) (x+1,y+1)
    //-----------------------------
    //The following loops sweeps all those positions around center:
    for (int i = (x-1); i <= (x+1); i++){
        if((i >= 0) && (i < WIDTH)){
            for(int j = (y-1); j <= (y+1); j++){
                if ((j >= 0) && (j < HEIGHT)){
                    //Checks if center is not being evaluated as its own
                    //neighbor (it is not):
                    if(!((i == x) && (j == y))){
                        center.checkOnNeighbors(boardCurrent[i][j]);
                    }
                }
            }
        }
    }
}

gameOfLife::~gameOfLife() {
}

