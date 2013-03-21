/* 
 * File:   cell.h
 * Author: Franch
 *
 * Created on March 20, 2013, 8:32 PM
 */

#ifndef CELL_H
#define	CELL_H

class cell {
public:
    cell();
    cell(const cell& orig);
    virtual ~cell();    
    
    //Function: init
    //Input: birth - Initial value for isAlive
    //       a - Initial x
    //       b- Initial y
    //Output: -
    //Description: Initializes the object.
    void init(bool birth, int a, int b); 
    
    //Function: deadOrAlive
    //Input: uses numLiveNeighbors
    //Output: sets isAlive
    //Description: Defines if cell is alive or dead following Conway's Game of
    //Life rules:
    //Live cells:
    //  0 to 1 live neighbors - cell dies of under-population/starvation
    //  2 to 3 live neighbors - cell lives for next generation
    //  More than 3 live neighbors - cell dies by overcrowding
    //Dead cells:
    //  3 live neighbors - cell comes alive as by reproduction
    void deadOrAlive();
    
    //Function: checkOnNeighbors
    //Input:  neighbor - neighbor cell to be checked
    //Output: updates numLiveNeighbors
    //Description: Checks if neighbor is alive. If it is, increments
    //numLiveNeighbors.
    void checkOnNeighbors(cell&  neighbor);
    
    //I won't write descriptions for setters and getters.
    //setters:
    void setIsAlive(bool alive);
    void setX(int a);
    void setY(int b);
    void setNumLiveNeighbors(int n);
    //getters:
    bool getIsAlive();
    int getX();
    int getY();
    int getNumLiveNeighbors();
    
private:
    
    //TODO: Find uses for x and y as well use some structure for the cell
    //to know its neighbors.
    bool isAlive; //True when the cell is alive
    int x;        //Cell's x coordinate
    int y;        //Cell's y coordinate 
    int numLiveNeighbors; //Number of live neighbors

};

#endif	/* CELL_H */

