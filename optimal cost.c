#include <stdio.h>
int max(int a, int b) 
{
return (a > b) ? a : b;
}
int knapsack(int weights[], int values[], int n, int capacity) {
int dp[n + 1][capacity + 1];
int i, w;
for (i = 0; i <= n; i++) {
for (w = 0; w <= capacity; w++) {
if (i == 0 || w == 0) {
dp[i][w] = 0;
} else if (weights[i - 1] <= w) {
dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
} else {
dp[i][w] = dp[i - 1][w];
}
}
}
return dp[n][capacity];
}
int main() {
int n, capacity;
printf("Enter the number of items: ");
scanf("%d", &n);
int weights[n], values[n];
printf("Enter the weight and value of each item:\n");
for (int i = 0; i < n; i++) {
scanf("%d %d", &weights[i], &values[i]);
}
printf("Enter the knapsack capacity: ");
scanf("%d", &capacity);
int optimal_cost = knapsack(weights, values, n, capacity);
printf("Optimal cost: %d\n", optimal_cost);
return 0;
}

