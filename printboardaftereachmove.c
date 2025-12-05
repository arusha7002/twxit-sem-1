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
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREY    "\033[90m"
void printboardaftereachmove(struct peg* board[][24], int *row, int *column)
{
    printf("  ");
    for(int i = 0; i<24; i++)
    {
        if(i<10)
        {
            printf(" %d  ", i);//put an extra space in front remove if needed
        }
        else
        {
            printf(" %d ", i);
        }
    }
    printf("\n\n");
    for(int k = 0; k<24; k++)
    {
        if(k<10)
        {
            printf("%d ", k);
        }
        else
        {
            printf("%d", k);
        }
        for(int j = 0; j<24; j++)
        {
            if(board[k][j] == NULL)
            {
    
                if(j<10)
                {
                    printf(" •  ");
                }
                else
                {
                    printf(" •  ");
                }
            }

            else
            {
                if(board[k][j]->colourofplayer == red)
                {
                    if(j<10)
                    {
                        printf(" %sR%s  ", RED, RESET);
                    }
                    else
                    {
                        printf(" %sR%s  ", RED, RESET);
                    }
                }
                else if(board[k][j]->colourofplayer == black)
                {
                    if(j<10)
                    {
                        printf(" %sB%s  ", GREY, RESET);
                    }
                    else
                    {
                        printf(" %sB%s  ", GREY, RESET);
                    }
                }
            }

        }
        printf("\n\n");
    }

}

