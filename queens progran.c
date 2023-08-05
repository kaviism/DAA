#include <stdio.h>
#include <stdbool.h>
#define N 10 
int board[N][N];
bool isSafe(int row, int col, int n) {
int i, j;
for (i = 0; i < col; i++) {
if (board[row][i]) {
return false;
}
}
for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
if (board[i][j]) {
return false;
}
}
for (i = row, j = col; j >= 0 && i < n; i++, j--) {
if (board[i][j]) {
return false;
}
}
return true;
}
bool solveNQueens(int col, int n) {
if (col == n) {
return true;
}
for (int i = 0; i < n; i++) {
if (isSafe(i, col, n)) {
board[i][col] = 1;
if (solveNQueens(col + 1, n)) {
return true;
}
board[i][col] = 0;
}
}
return false;
}
void printBoard(int n) {
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
printf("%c ", board[i][j] ? 'Q' : '.');
}
printf("\n");
}
}
int main() {
int n;
printf("Enter the size of the chessboard (n): ");
scanf("%d", &n);
if (n <= 0 || n > N) {
printf("Invalid input! Please enter a valid size.\n");
return 1;
}
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++) {
board[i][j] = 0;
}
}
if (solveNQueens(0, n)) {
printf("Solution:\n");
printBoard(n);
} else {
printf("No solution found for the given chessboard size.\n");
}

return 0;
}

