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
int valid(int row, int column, struct peg* board[][24], struct peg* newpeg, struct peg* link[])//newpeg is passed from from makeamove.c
{
    int l = 0;
    int r = 0, c= 0;
    
    //lets do the link checking ability first
    int di[] = {-1, -1, 1, 1, -2, 2, -2, 2};
    int dj[] = {2, -2, 2, -2, 1, 1, -1, -1};
    for(int i = 0; i<8; i++)
    {
        //int breakout = 1;
        r = row+di[i];
        c = column+dj[i];
        if((r>=0 && r<=23 && c>=0 && c<=23) && board[r][c] != NULL )
        {
            if(newpeg->colourofplayer == board[r][c]->colourofplayer)//link possible
            {
                int isvalidflag = 1;
                int x1 = newpeg->row, y1 = newpeg->column;
                int x2 = board[r][c]->row, y2 = board[r][c]->column;
                int midX = (x1+x2)/2, midY = (y1+y2)/2;
                for(int i = 0; i<24 && isvalidflag; i++)
                {
                    for(int j = 0; j<24 && isvalidflag; j++)
                    {
                        if(board[i][j]!=NULL)
                        {
                            struct peg* curr = board[i][j];
                            for(int k = 0; k<curr->numberoflinks; k++)
                            {
                                struct peg* linkedtocurr = curr->pegpointer[k];
                                int p1 = curr->row, q1 = curr->column;
                                int p2 = linkedtocurr->row, q2 = linkedtocurr->column;
                                int midP = (p1+p2)/2, midQ = (q1+q2)/2;
                                if(midX == midP && midY == midQ && !(x1 == p1 && y1 == q1) && !(x2 == p2 && y2 ==q2) && !(x1 == p2 && y1 == q2) && !(x2 == p1 && y2 == q1))
                                {
                                    isvalidflag = 0;
                                    //breakout = 0;
                                    printf("Crossing detected!\nCan't form a link here\n");
                                    break;
                                }

                            }
                        }
                    }
                }
                if(isvalidflag)
                {
                    link[l] = board[r][c];
                    l++;
                }
            }
           /*else if(newpeg->colourofplayer ==  board[r][c]->colourofplayer )
            {
                int x1 = newpeg->row, y1 = newpeg->column;
                int x2 = board[r][c]->row, y2 = board[r][c]->column;
                int midX = (x1+x2)/2, midY = (y1+y2)/2;
                for(int i = 0; i<24; i++)
                {
                    for(int j = 0; j<24; j++)
                    {
                        if(board[i][j]!=NULL)
                        {
                            struct peg* curr = board[i][j];
                            for(int k = 0; k<curr->numberoflinks; k++)
                            {
                                struct peg* linkedtocurr = curr->pegpointer[k];
                                int p1 = curr->row, q1 = curr->column;
                                int p2 = linkedtocurr->row, q2 = linkedtocurr->column;
                                int midP = (p1+p2)/2, midQ = (q1+q2)/2;
                                if(midX == midP && midY == midQ && !(x1 == p1 && y1 == q1) && !(x2 == p2 && y2 ==q2) && !(x1 == p2 && y1 == q2) && !(x2 == p1 && y2 == q1))
                                {
                                    isvalidflag = 0;
                                    break;
                                }

                            }
                        }
                    }
                }
                if(isvalidflag)
                {
                    link[l] = board[r][c];
                    l++;
                }
            }*/


        }
        
    }

    return l;
}