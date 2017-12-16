#include <stdio.h>
#include <limits.h>

void BellmanFord( int n, int e, int G[][n], int source) {
	int dist[n], i, u, v;
	for( i = 0; i < n; i++)
		dist[i] = INT_MAX;
	dist[source] = 0;

	for( i = 0; i < n-1; i++)
		for( u = 0; u < n; u++)
			for( v = 0; v < n; v++)
				if(G[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + G[u][v] < dist[v])
						dist[v] = dist[u] + G[u][v];

	for( u = 0; u < n; u++)
		for( v = 0; v < n; v++)
			if(G[u][v] != INT_MAX) && dist[u] != INT_MAX && dist[u] + G[u][v] < dist[v])
					printf("Graph contains negative weight cycle");

	for( i = 0; i < n; i++)
		printf("%d\t\t%d\n", i, dist[i]);

	printf("\n");
}

int main() {
	int n, e;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	printf("Enter the number of edges: ");
	scanf("%d", &e);

	int i, j, a, b, G[n][n];
	for( i = 0; i < n; i++)
		for( j = 0; j < n; j++)
			G[i][j] = INT_MAX;

	for( i = 0; i < e; i++) {
		printf("Enter the nodes(a,b): ");
		scanf("%d %d", &a, &b);
		printf("Enter distance: ");
		scanf("%d", &G[a][b]);
	}

	int source;
	printf("Enter source: ");
	scanf("%d", &source);

	BellmanFord( n, e, G, source);

	return 0;
}
