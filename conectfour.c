#include <stdio.h>
#include <stdlib.h>
#define ROWS 6
#define COLS 7

char gamearr[ROWS][COLS];  

int validMove(int col)
{
    return gamearr[0][col] == ' ';
}

void inputMove(int col, char player)
{
    

    for (int row = ROWS - 1; row >= 0; row--)
    {
        if (gamearr[row][col] == ' ')
        {
            gamearr[row][col] = player;
            return;
        }
    }
}

void initializeBoard()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            gamearr[i][j] = ' ';
        }
    }
}

void printBoard()
{
    for (int j = 1; j <= COLS; j++)
    {
        printf("  %d ", j);
    }
    printf("\n");

    
    


    
    

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("| %c ", gamearr[i][j]);
        }
        printf("|\n"); //for final colum and new line
    }
}


int checkWin(char player){
    int count;
    //horizontal test
    for (int i = 0; i < ROWS; i++)
    {
        count = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (gamearr[i][j] == player)
            {
                count++;
                if (count == 4)
                {
                    return 1;
                }
                
            }else
            {
                count = 0;
            }
            
        }
        
    }
    //vertical
    for (int i = 0; i < COLS; i++)
    {
        count = 0;
        for (int j = 0; j < ROWS; j++)
        {
            if (gamearr[j][i] == player)
            {
                count++;
                if (count == 4)
                {
                    return 1;
                }
                
            }else
            {
                count = 0;
            }
            
        }
        
    }

    for (int i = 0; i < ROWS - 3; i++)
    {
        for (int j = 0; j < COLS - 3; j++)
        {
            if (gamearr[i][j] == player && gamearr[i+1][j+1] == player && gamearr[i + 2][j + 2] == player && gamearr[i + 3][j + 3] == player)
            {
                return 1;
            }
            
        }
        
    }

    for (int i = 0; i < ROWS - 3; i++)
    {
        for (int j = 3; j < COLS; j++)
        {
            if (gamearr[i][j] == player && gamearr[i + 1][j - 1] == player && gamearr[i + 2][j - 2] == player && gamearr[i + 3][j - 3] == player)
            {
                return 1;
            }
            
        }
        
    }
    
    return 0;
    
}

int main()
{
    
    int moves = 0;
    int col;
    char player = 'X';
    initializeBoard();

    while (1)
    {
        
        
        printBoard();

        printf("Enter column (1-7) for player %c: ", player);
        if(scanf("%d", &col) != 1) { // check for successful read
            printf("Invalid input, please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        if (col < 1 || col > 7) {
            printf("Invalid column number, please try a diffrent column.\n");
            continue;
        }
        col--;
        if (!validMove(col)) {
            printf("Column is full, please try a diffrent column.\n");
            continue;
        }  
        inputMove(col, player);
        moves++;
        if (checkWin(player))
        {
            printBoard();
            printf("\nplayer %c wins!", player);
            
            break;
        }
        
        if(moves == ROWS * COLS) {
            printf("\nIt's a draw!\n");
            break;
        }
        
        
        
        
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}
