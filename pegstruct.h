#ifndef PEG_H
#define PEG_H
#include "colourenum.h"
struct peg
{
    colour colourofplayer;
    int row;
    int column;
    struct peg* pegpointer[8];//yeh count for number of links made by one peg hai 
    int numberoflinks;
    int st;
    int end;

};
#endif