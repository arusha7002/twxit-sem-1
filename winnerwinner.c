#include<stdio.h>
#include<stdlib.h>
#include "colourenum.h"
#include "pegstruct.h"
#include "recordamove.h"
#include "playerinput.h"
#include "printboardaftereachmove.h"
#include "printtwixt.h"
#include "linkvaliditycheck.h"
#include "winnerwinner.h"
int winnerWinnerChickenDinner(struct peg* winningpeg)
{
    if(winningpeg == NULL)
    {
        return 0;
    }
    if(winningpeg->st == 1 && winningpeg->end == 1)
    {
       if(winningpeg->colourofplayer == red)
        {
            printf("RED WINS !\n");
            return 1;//won one won one won one
        }
        else if(winningpeg->colourofplayer == black)
        {
            printf("BLACK WINS !\n");
            return 1;//won one won one won one
        }
    }
    return 0;//not won not one = zero
}