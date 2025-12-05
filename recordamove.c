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
//need to put a valid move function in this
int recordamove(int *row, int *column, int turnflag, struct peg* board[][24])
{
    if(*row<0 || *row>23 || *column<0 || *column>23)
    {
        printf("Invalid coordinates!\n");
        return 0;
    }
    else if(turnflag == 1 && (*column>0 && *column<23) && (*row>=0 && *row<=23))//red is flag 1
    {
        if(board[*row][*column] == NULL)
        {
            //remember to use these player struct nodes in link validity chekdcs
            struct peg* newpeg = (struct peg*)malloc(sizeof(struct peg));
            board[*row][*column] = newpeg;
            newpeg->colourofplayer = red;
            newpeg->row = *row;
            newpeg->column = *column;
            newpeg->numberoflinks = 0;
            newpeg->st = newpeg->end = 0;
            for(int i=0;i<8;i++) 
            {
                newpeg->pegpointer[i] = NULL;
            }
            if(*row == 0)
            {
                board[*row][*column]->st = 1;
            }
            else if(*row == 23)
            {
                board[*row][*column]->end = 1;
            }
            struct peg* newpeg1 = board[*row][*column];
            struct peg* link[8];
            int linkcount = valid(*row, *column, board, newpeg1, link);
            if(linkcount>0)
            {
                for(int i = 0; i<linkcount; i++)
                {
                    board[*row][*column]->pegpointer[board[*row][*column]->numberoflinks] = link[i];
                    link[i]->pegpointer[link[i]->numberoflinks] = board[*row][*column];
                    board[*row][*column]->numberoflinks++;
                    link[i]->numberoflinks++;
                    if(link[i]->st)
                    {
                        board[*row][*column]->st = 1;
                    }
                    if(board[*row][*column]->st)
                    {
                        link[i]->st = 1;
                    }
                    if(link[i]->end)
                    {
                        board[*row][*column]->end = 1;
                    }
                    if(board[*row][*column]->end)
                    {
                        link[i]->end = 1;
                    }
                }
            }

            int resR = winnerWinnerChickenDinner(newpeg1);
            if(resR)
            {
                return 2;
            }
            
            return 1;
            
        }
        else
        {
            printf("This spot is already occupied!\nPlease enter coordinates again\n");
            return 0;
        }
    }

    else if(turnflag == 0 && (*row>0 && *row<23) && (*column>=0 && *column<=23))//black is flag = 0
    {
         if(board[*row][*column] == NULL)
        {
            
            //remember to use these olayer struct nodes in link validty checks
            
            //board[*row][*column] = filledblackpegspots;
            struct peg* newpeg = (struct peg*)malloc(sizeof(struct peg));
            board[*row][*column] = newpeg;
            newpeg->colourofplayer = black;
            newpeg->row = *row;
            newpeg->column = *column;
            newpeg->numberoflinks = 0;
            newpeg->st = newpeg->end = 0;
            for(int i=0;i<8;i++) 
            {
                newpeg->pegpointer[i] = NULL;
            }
            if(*column == 0)
            {
                board[*row][*column]->st = 1;
            }
            else if(*column == 23)
            {
                board[*row][*column]->end = 1;
            }
                
            
            struct peg* newpeg1 = board[*row][*column];
            struct peg* link[8];
            int linkcount = valid(*row, *column, board, newpeg1, link);
            if(linkcount>0)
            {
                
                for(int i = 0; i<linkcount; i++)
                {
                    board[*row][*column]->pegpointer[board[*row][*column]->numberoflinks] = link[i];
                    link[i]->pegpointer[link[i]->numberoflinks] = board[*row][*column];
                    board[*row][*column]->numberoflinks++;
                    link[i]->numberoflinks++;
                    if(link[i]->st)
                    {
                        board[*row][*column]->st = 1;
                    }
                    if(board[*row][*column]->st)
                    {
                        link[i]->st = 1;
                    }
                    if(link[i]->end)
                    {
                        board[*row][*column]->end = 1;
                    }
                    if(board[*row][*column]->end)
                    {
                        link[i]->end = 1;
                    }
                }
            }

            int resB = winnerWinnerChickenDinner(newpeg1);
            if(resB)
            {
                return 2;
            }
            
            return 1;
        }
        else
        {
            printf("This spot is already occupied!\nPlease enter coordinates again\n");
            return 0;
        }
    }

    return 0;
}