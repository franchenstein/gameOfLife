/* 
 * File:   cell.cpp
 * Author: Franch
 * 
 * Created on March 20, 2013, 8:32 PM
 */

#include "cell.h"

cell::cell() {
}

cell::cell(const cell& orig) {
}

void cell::init(bool birth, int a, int b){
    //Initializes values:
    isAlive = birth;
    x = a;
    y = b;
    numLiveNeighbors = 0;
}

void cell::deadOrAlive(){
    
    //Rule for live cells:
    if(isAlive){
        //Checks if the cell is underpopulated or overcrowded:
        if((numLiveNeighbors < 2)||(numLiveNeighbors > 3)){
            isAlive = 0;        //If it is, cell dies.
        }
    }
    //Rule for dead cells:
    else{
        //Checks if there are enough neighbors to reproduce:
        if(numLiveNeighbors == 3){
            isAlive = 1;        //If there are, cell comes alive.
        }
    }
    
}

void cell::checkOnNeighbors(cell& neighbor){
    
    if(neighbor.getIsAlive()){
        numLiveNeighbors++; //Increments number of live neighbors if the
                            //neighbor under analysis is alive
    }
        
}

//setters:

void cell::setIsAlive(bool alive){
    isAlive = alive;
}

void cell::setX(int a){
    x = a;
}

void cell::setY(int b){
    y = b;
}

void cell::setNumLiveNeighbors(int n){
    numLiveNeighbors = n;
}

//getters:

bool cell::getIsAlive(){    
    return isAlive;    
}

int cell::getX(){
    return x;
}

int cell::getY(){
    return y;
}

int cell::getNumLiveNeighbors(){
    return numLiveNeighbors;
}

cell::~cell() {
}

