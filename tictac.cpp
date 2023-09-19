#include <iostream>
#include <vector>

// Function to display the Tic-Tac-Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (const std::vector<char>& row : board) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;  // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;  // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;  // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;  // Diagonal win (top-right to bottom-left)
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (const std::vector<char>& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;  // There is an empty cell, game is not a draw
            }
        }
    }
    return true;  // All cells are filled, game is a draw
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    while (!gameWon && !gameDraw) {
        // Display the current state of the board
        displayBoard(board);

        // Prompt the current player to enter their move
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        // Update the board with the player's move
        board[row][col] = currentPlayer;

        // Check if the current player has won
        gameWon = checkWin(board, currentPlayer);

        // Check if the game is a draw
        gameDraw = checkDraw(board);

        if (!gameWon && !gameDraw) {
            // Switch players only if the game is not won or drawn
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    // Display the final state of the board
    displayBoard(board);

    // Display the result of the game
    if (gameWon) {
        std::cout << "Player " << currentPlayer << " wins! Congratulations!" << std::endl;
    } else {
        std::cout << "It's a draw! The game ends in a tie." << std::endl;
    }

    return 0;
}
