#include <stdio.h>
#define INF 99999
#define MAX_VERTICES 10
int min(int a, int b) {
return (a < b) ? a : b;
}
void floydWarshall(int graph[MAX_VERTICES][MAX_VERTICES], int V) 
{
int dist[MAX_VERTICES][MAX_VERTICES];
int i, j, k;
for (i = 0; i < V; i++) 
{
for (j = 0; j < V; j++) 
{
dist[i][j] = graph[i][j];
}
}
for (k = 0; k < V; k++) 
{
for (i = 0; i < V; i++) 
{
for (j = 0; j < V; j++) 
{
if (dist[i][k] + dist[k][j] < dist[i][j]) 
{
dist[i][j] = dist[i][k] + dist[k][j];
}
}
}
}
printf("Shortest distances between all pairs of vertices:\n");
for (i = 0; i < V; i++) 
{
for (j = 0; j < V; j++) 
{
if (dist[i][j] == INF) 
{
printf("INF\t");
} else {
printf("%d\t", dist[i][j]);
}
}
printf("\n");
}
}
int main() 
{
int V;
printf("Enter the number of vertices (V): ");
scanf("%d", &V);
if (V <= 0 || V > MAX_VERTICES) 
{
printf("Invalid input! Please enter a valid number of vertices.\n");
return 1;
}
int graph[MAX_VERTICES][MAX_VERTICES];
printf("Enter the adjacency matrix (use 'INF' for unreachable edges):\n");
for (int i = 0; i < V; i++) 
{
for (int j = 0; j < V; j++) 
{
scanf("%d", &graph[i][j]);
if (graph[i][j] == INF) 
{
if (i == j) 
{
graph[i][j] = 0;
}
}
}
}
floydWarshall(graph, V);
return 0;
}

