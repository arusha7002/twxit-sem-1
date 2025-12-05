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
//THIS GAME RUNS FOR ONLY FIVE TURNS OF EACH PLAYER
int main()
{
    
    printtwixt();
    struct peg* board[24][24] = {{NULL}};
    int turnflag = 1;
    int row = 0, column = 0;
    while(1)
    {
        int result = playerinput(turnflag, &row, &column, board);
        if(result == 2)
        {
            printboardaftereachmove(board, &row, &column);
            printf("GAME OVER\n");
            break;
        }
        turnflag = 1-turnflag;
    }
    return 0;
}