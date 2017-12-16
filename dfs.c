#include <stdio.h>

int v;
int visited[12];

void dfs( int G[][v], int source) {
	int i;
	visited[source] = 1;
	printf("%d  ", source + 1);
	for( i = 0; i < v; i++)
		if(!visited[i] && G[source][i] != 0)
			dfs( G, i); 
}

int main() {
	int i, j;
	printf("Enter the number of vertices: ");
	scanf("%d", &v);
	int adj_mat[v][v];
	for( i = 0; i < v; i++)
		for( j = 0; j < v; j++)
			scanf("%d", &adj_mat[i][j]);
	
	for( i = 0; i < v; i++)
		visited[i] = 0;

	printf("The dfs of the graph:\n");
	dfs( adj_mat, 0);
	printf("\n");
	return 0;
}
