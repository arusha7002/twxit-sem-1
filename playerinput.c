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
int playerinput(int turnflag, int *row, int *column, struct peg* board[][24])
{
    int movevalidity = 1;
    do
    {
        if(turnflag == 1)//red's turn
        {
            if(movevalidity == 1)
            {
                printf("Red player\nPlease enter valid coordinates (x ranges from 0 to 23, y ranges from 1 to 22) of the point where you want your peg to be placed\n");
                scanf("%d %d", row, column);
            }
            else if(movevalidity == 0)
            {
                printf("ERROR! Invalid coordinates entered\nRed player\nPlease re-enter valid coordinates of the point where you want your peg to be placed\n");
                scanf("%d %d", row, column);
            }
        }
        else if(turnflag == 0)
        {
            if(movevalidity == 1)
            {
                printf("Black player\nPlease enter valid coordinates (x ranges from 1 to 22, x ranges from 0 to 23) of the point where you want your peg to be placed\n");
                scanf("%d %d", row, column);
            }
            else if(movevalidity == 0)
            {
                printf("ERROR! Invalid coordinates entered\nBlack player\nPlease re-enter valid coordinates of the point where you want your peg to be placed\n");
                scanf("%d %d", row, column);
            }
        }
                
            
           
        movevalidity = recordamove(row, column, turnflag, board);
        
        if(movevalidity == 1)
        {
            printboardaftereachmove(board, row, column);
        }
    }
    while(!movevalidity);
    return movevalidity;

}
