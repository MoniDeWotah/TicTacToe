# TicTacToe
TIC-TAC-TOE

**Main Function Overview**
The main function is the heart of the Tic Tac Toe game. It initializes a 3x3 board, sets the current player to 'X', and begins the game loop. 
Inside the loop, the board is printed, and the current player is prompted to input their desired row and column. After validating the inputs and ensuring the selected cell is empty, the move is placed on the board. 
The program then checks if the player has won, which ends the game. 
If the board is full and no winner is found, it declares a draw. 
The game continues until one of these conditions is met.

**Input Validation**
Input validation in this code ensures that players only enter valid rows and columns between 1 and 3. 
The scanf function reads user input, and the return value is checked to ensure a number was entered. If invalid input (like a letter or an array of characters) is detected, the input buffer is cleared using a loop that consumes characters with getchar(). 
This prevents leftover junk data from interfering with subsequent inputs, effectively avoiding issues like infinite loops caused by invalid input.


**The initializeBoard Function**
This function sets up the Tic Tac Toe board by populating the 3x3 grid with empty spaces (' '). 
It uses nested loops to iterate through each cell in the board array, ensuring it's clean and ready for gameplay. 
This makes it reusable for resetting the board if needed.

**The printBoard Function**
The printBoard function takes care of displaying the current state of the board. 
It prints each row and column of the board, separating cells with vertical and horizontal dividers for clarity. 
The formatting ensures that the board looks neat and player-friendly.

**The checkWinner Function**
This function checks if the current player has won the game by forming a straight line of their symbol ('X' or 'O'). 
It evaluates all rows, columns, and the two diagonals for a match. 
If any condition is met, it returns 1, signaling a win. Otherwise, it returns 0.

**The clearBoard Function**
When a winner is found, this function highlights the winning cells by ensuring they retain the current player's symbol while changing all other filled cells to lowercase ('x' or 'o'). 
This visual effect is implemented using a nested loop that scans each cell and modifies its content if it doesn’t match the winning player.


**The checkFull Function**
This function determines whether the board is full by counting how many cells contain 'X' or 'O'. 
It loops through each cell and increments a counter for every filled spot. 
If the count reaches 9 (the total number of cells), the board is declared full, which can indicate a draw if no winner is found.

**Game Flow Using Labels and goto**
The code uses a label (M:) and a goto statement to handle invalid moves. 
For instance, if a player attempts to play in an already occupied cell, the program jumps back to the input prompt for that player. 
While functional, this approach can be considered less elegant than using a loop or additional logic for retries.
