#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_CITIES 10
int min(int a, int b) {
return (a < b) ? a : b;
}
int tsp(int graph[MAX_CITIES][MAX_CITIES], int n, int start) {
int dp[1 << MAX_CITIES][MAX_CITIES];
int i, j, mask;
for (i = 0; i < (1 << n); i++) {
for (j = 0; j < n; j++) {
dp[i][j] = -1;
}
}
dp[1 << start][start] = 0;
for (mask = 1; mask < (1 << n); mask++) {
for (i = 0; i < n; i++) {
if (!(mask & (1 << i))) {
continue;
}
for (j = 0; j < n; j++) {
if (mask & (1 << j) && i != j) {
if (dp[mask ^ (1 << i)][j] != -1) {
if (dp[mask][i] == -1) {
dp[mask][i] = dp[mask ^ (1 << i)][j] + graph[j][i];
} else {
dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + graph[j][i]);
}
}
}
}
}
}
int final_mask = (1 << n) - 1;
int min_cost = INT_MAX;
for (i = 0; i < n; i++) {
if (dp[final_mask][i] != -1 && graph[i][start] != -1) {
min_cost = min(min_cost, dp[final_mask][i] + graph[i][start]);
}
}
return min_cost;
}
int main() {
int n, start;
printf("Enter the number of cities (n): ");
scanf("%d", &n);
if (n <= 0 || n > MAX_CITIES) {
printf("Invalid input! Please enter a valid number of cities.\n");
return 1;
}
int graph[MAX_CITIES][MAX_CITIES];
printf("Enter the distance matrix (use -1 for unreachable edges):\n");
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
scanf("%d", &graph[i][j]);
}
}
printf("Enter the starting city (0 to %d): ", n - 1);
scanf("%d", &start);
if (start < 0 || start >= n) {
printf("Invalid input! Please enter a valid starting city.\n");
return 1;
}
int min_cost = tsp(graph, n, start);
printf("Minimum cost of the Traveling Salesman Problem: %d\n", min_cost);
return 0;
}

