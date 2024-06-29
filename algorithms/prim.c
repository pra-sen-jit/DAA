// Implementing Prim's Algorithm on a graph

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int V;

int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

int printMST(int parent[], int graph[V][V])
{
	int minCost = 0;
	printf("Edge \tCost\n");
	for (int i = 1; i < V; i++) {
		printf("%d - %d \t%d \n", parent[i], i,
			graph[i][parent[i]]);
		minCost += graph[i][parent[i]];
	}
	printf("Minimum Cost = %d", minCost);
}

void primMST(int graph[V][V])
{
	int parent[V];
	int key[V];
	bool mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;

	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) {
		
		int u = minKey(key, mstSet);

		mstSet[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	printMST(parent, graph);
}

int main()
{
	printf("Enter the number of vertices: ");
	scanf("%d", &V);
	int graph[V][V];
	printf("Enter the adjacency matrix:\n");
	for(int i = 0; i < V; i++) {
		printf("Row %d:\n", i + 1);
		for(int j = 0; j < V; j++)
			scanf("%d", &graph[i][j]);
	}
	
	primMST(graph);

	return 0;
}


/*
Example graph:
{ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
  { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
  { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
  { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
  { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } }
Output:
Edge    Cost
0 - 1   4
1 - 2   8
2 - 3   7
3 - 4   9
2 - 5   4
5 - 6   2
6 - 7   1
2 - 8   2
Minimum Cost = 37
*/