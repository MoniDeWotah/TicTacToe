#include <stdio.h>

#define SIZE 3 // Size of Tic Tac Toe Board

void initializeBoard(char board[SIZE][SIZE]); // Make Board
void printBoard(char board[SIZE][SIZE]); // Print Board
int checkWinner(char board[SIZE][SIZE], char player); // Check for a winner
void clearBoard(char board[SIZE][SIZE], char player); // Highlight winner
int checkFull(char board[SIZE][SIZE]); // Check how full the board is


int main()
{
    char board[SIZE][SIZE]; 
    int flag = 0, row, col;
    char currentPlayer = 'X';
    int game = 0; // 1 if the game is won, 0 otherwise

    initializeBoard(board);

    printf("Welcome to Tic Tac Toe!\n");
    printf("Players take turns entering positions as Row Column (1-based indexing).\n");

    while (!game) 
    {
        row = col = 0;
        M:
        printBoard(board);

        // Input for Row and Column
        do
        {
            printf("Player %c, enter row (1-3): ", currentPlayer);

            flag = scanf("%d", &row);
            if(!flag)
            {
                while(getchar()!='\n');
                flag = 0;
            }
        }
        while(row <= 0 || row > SIZE);

        do
        {
            printf("Player %c, enter column (1-3): ", currentPlayer);
            flag = scanf("%d", &col);
            if(!flag)
            {
                while(getchar()!='\n');
            }
        }
        while(col <= 0 || col > SIZE); // Validate Input


        // Make the move
        row--; col--;
        if(board[row][col] == 'X' || board[row][col] == 'O')
        {
            goto M;
        }
        else
        {
            board[row][col] = currentPlayer;
        }
        // Check for a winner
        if (checkWinner(board, currentPlayer) == 1) 
        {
            game = 1;
            clearBoard(board, currentPlayer);
            printBoard(board);
            printf("\nPlayer %c wins!\n", currentPlayer);
        }

        // Check for a draw
        if (checkFull(board) == SIZE*SIZE)
        {
            printBoard(board);
            printf("Draw!\n");
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        while(getchar()!='\n');
    }
    return 0;
}

// Make Board
void initializeBoard(char board[SIZE][SIZE]) 
{
    for (int row = 0; row < SIZE; row++) 
    {
        for (int col = 0; col < SIZE; col++) 
        {
            board[row][col] = ' ';
        }
    }
}

// Print Board
void printBoard(char board[SIZE][SIZE]) 
{
    printf("\nCurrent Board:\n");
    for (int row = 0; row < SIZE; row++) 
    {
        for (int col = 0; col < SIZE; col++) 
        {
            printf(" %c ", board[row][col]);
            if (col < SIZE - 1) 
            {
                printf("|");
            }
        }
        printf("\n");
        if (row < SIZE - 1) 
        {
            for (int col = 0; col < SIZE - 1; col++)
            {
                printf("---+");
            }
            printf("---\n");
        }
    }
}

// Check for a winner
int checkWinner(char board[SIZE][SIZE], char player) 
{
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) 
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) 
    {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }
    return 0; // If no winner
}

// Highlight Winner
void clearBoard(char board[SIZE][SIZE], char player) 
{
    char player2 = ' ';
    if(player == 'X')
    {
        player2 = 'o';
    }
    else
    {
        player2 = 'x';
    }
    for (int row = 0; row < SIZE; row++) 
    {
        for (int col = 0; col < SIZE; col++) 
        {
            if (board[row][col] != player) 
            {
                if(board[row][col] == ' ')
                {
                    continue;
                }
                else{
                board[row][col] = player2;
                }
            }
        }
    }
}

// Check how full the board is
int checkFull(char board[SIZE][SIZE])
{
    int flag = 0;
    for(int row = 0; row < SIZE; row++)
    {
        for(int col = 0; col < SIZE; col++)
        {
            if(board[row][col] == 'X' || board[row][col] == 'O')
            {
                flag++;
            }
        }
    }
    return flag;
}