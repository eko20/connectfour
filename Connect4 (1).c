#include <stdio.h>
#include <stdlib.h>
#define ROWS 6
#define COLS 7

char gamearr[ROWS][COLS];  //game Array for storing movements


//initialize game board with spaces
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


//board print in the terminal
void printBoard()
{
    for (int j = 1; j <= COLS; j++) //print numbers
    {
        printf("  %d ", j);
    }
    printf("\n");


    for (int i = 0; i < ROWS; i++) //print boards
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("| %c ", gamearr[i][j]);
        }
        printf("|\n"); 
        for (int j = 0; j < COLS; j++)
        {
            printf("+---");
        }
        printf("+\n");
    }  
}

void inputMove(int col, char player)
{
    // put the player in the game array

    for (int row = ROWS - 1; row >= 0; row--) // to start from the bottom row
    {
        if (gamearr[row][col] == ' ')
        {
            gamearr[row][col] = player;
            return;
        }
    }
}



//checks that Is there a space to play in the column
int validMove(int col)
{
    return gamearr[0][col] == ' '; 
}



int checkWin(char player){
    int count;
    //horizontal checkwin
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
    //vertical check win
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
    
    //cross checkwins

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
    //game start
    
    int moves = 0;
    int col;
    char player = 'X';
    initializeBoard();

    while (1)
    {
    
        printBoard();

        printf("Enter column (1-7) for player %c: ", player);
        if(scanf("%d", &col) != 1) {  // check for successful read
            
            printf("\n ⚠️ ⚠️   Invalid input, please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            printf("\n");
            continue;
            
        }
        printf("\n");
        if (col < 1 || col > 7) { //check for column number is betwwen 1 and 7
            
            printf("⚠️ ⚠️   Invalid column number, please try a diffrent column.\n");
            printf("\n");
            continue;
        }
        col--; //decarese the col number because our game array is between 0 and 6
        
        if (!validMove(col)) { //check that is the column full
            
            printf("⚠️ ⚠️  Column is full, please try a diffrent column.\n");
            printf("\n");
            continue;
        }  
        inputMove(col, player);
        

        moves++; //counting moves

        if (checkWin(player)) //check win
        {
            
            printf("\n🎉🎉   Player %c wins!   🎉🎉\n\n", player);
            printBoard();
            break;
        }
        
        if(moves == ROWS * COLS) { //check for is there are space to move
            
            printf("\nIt's a draw!\n"); // if not print draw
            break;
        }

        player = (player == 'X') ? 'O' : 'X'; //switch player
    }
    return 0;
}
