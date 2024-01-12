#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE];
char currentPlayer = 'X';
int moves = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
bool game_over = false; // Global flag to indicate if the game is over
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) 
            board[i][j] = ' ';
    }
}
void display_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++)
            printf("| %c ", board[i][j]);
        printf("|\n");
    }
}
bool make_move(int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ')
        return false; // Invalid move
    board[row][col] = currentPlayer;
    moves++;
    return true;
}
bool check_winner() { // Check rows, columns, and diagonals for a win
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true; // Row win
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) 
            return true; // Column win
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) 
        return true; // Diagonal win
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true; // Diagonal win
    return false;
}
void* player_thread(void* player_name) {
    while (moves < BOARD_SIZE * BOARD_SIZE) {
        pthread_mutex_lock(&mutex); // Acquire the lock
        if (game_over) {
            pthread_mutex_unlock(&mutex); // Release the lock
            break; // Exit the loop if the game is over
        }
        printf("Current board:\n");
        display_board();
        printf("Player %c's turn. Enter row and column (0-2): ", currentPlayer);
        int row, col;
        scanf("%d %d", &row, &col);
        if (make_move(row, col)) {
            if (check_winner()) {
                printf("\nPlayer %c wins!\n", currentPlayer);
                display_board();
                game_over = true; // Set the game over flag
            } else if (moves == BOARD_SIZE * BOARD_SIZE) {
                printf("\nIt's a draw!\n");
                display_board();
                game_over = true; // Set the game over flag
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
        } else
            printf("Invalid move. Try again.\n");
        pthread_mutex_unlock(&mutex); // Release the lock
    }
    return NULL;
}
int main() {
    initialize_board();
    pthread_t player_X_thread, player_O_thread;
    char player_X_name = 'X';
    char player_O_name = 'O';
    pthread_create(&player_X_thread, NULL, player_thread, &player_X_name);
    pthread_create(&player_O_thread, NULL, player_thread, &player_O_name);
    pthread_join(player_X_thread, NULL);
    pthread_join(player_O_thread, NULL);
    return 0;
}