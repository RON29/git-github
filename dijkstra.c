#include <stdio.h>
#include <limits.h>

void Dijkstra( int n, int e, int G[][n], int source) {
	int d[n], i, v, y;
	int s[n], v_s[n];
	int min, min_index;

	for( i = 0; i < n; i++) {
		s[i] = 0;
		v_s[i] = 1;
	}

	s[source] = 1;
	v_s[source] = 0;
	d[source] = 0;

	for( v = 0; v < n; v++)
		if(v_s[v] == 1)
			d[v] = G[source][v];

	for( i = 0; i < n-1; i++) {
		for( y = 0, min = INT_MAX; y < n; y++)
			if( v_s[y] == 1)
				if(d[y] < min) {
					min_index = y;
					min = d[y];
				}

		s[min_index] = 1;
		v_s[min_index] = 0;

		for( v = 0; v < n; v++)
			if( v_s[v] == 1)
				if(G[min_index][v] != INT_MAX && d[min_index] + G[min_index][v] < d[v])
					d[v] = d[min_index] + G[min_index][v];
	}

	for( i = 0; i < n; i++)
		printf("%d\t\t%d\n", i, d[i]);
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

	Dijkstra( n, e, G, source);

	return 0;
}
