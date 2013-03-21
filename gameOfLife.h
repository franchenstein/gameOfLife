/* 
 * File:   gameOfLife.h
 * Author: Franch
 *
 * Created on March 20, 2013, 8:36 PM
 */

#ifndef GAMEOFLIFE_H
#define	GAMEOFLIFE_H
//TODO: Turn this into user input
#define WIDTH 8
#define HEIGHT 8

#include "cell.h"
#include <iostream>
using namespace std;

class gameOfLife {
public:
    gameOfLife();
    gameOfLife(const gameOfLife& orig);
    virtual ~gameOfLife();
    
    //Function: run
    //Input: -
    //Output: -
    //Description: Runs Conway's Game of Life's state machine.
    void run();
    
    //Function: checkNeighborhood
    //Input: center - cell on the center of the neighborhood being analysed
    //Output: center.numLiveNeighbors will be updated with the total number of
    //        live neighbors.
    //Description: Analyses all neighbors of center. Checks if the center is in
    //             some corner of the board and then analyses each of the
    //             found neighbors, updating numLiveNeighbors if they are alive.
    void checkNeighborhood(cell& center);
    
    
private:
    
    cell board[WIDTH][HEIGHT];        //Board being updated 
    //TODO: Probably turn current state into a local variable for run()
    cell boardCurrent[WIDTH][HEIGHT]; //Current state before update

};

#endif	/* GAMEOFLIFE_H */

