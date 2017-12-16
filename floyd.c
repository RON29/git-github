#include <stdio.h>
#include <limits.h>

void floyd( int n, int adjMat[][n]) {
	int i, j, k;

	for( k = 0; k < n; k++)
		for( i = 0; i < n; i++)
			for( j = 0; j < n; j++)
				if((adjMat[i][k] == INT_MAX) || (adjMat[k][j] == INT_MAX))
					continue;
				else if(adjMat[i][j] > (adjMat[i][k] + adjMat[k][j]))
					adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
}

int main() {
	int n, e;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	printf("Enter the number of edges: ");
	scanf("%d", &e);

	int i, adjMat[n][n], j;
	int n1, n2;

	for( i = 0; i < n; i++)
		for( j = 0; j < n; j++) {
			adjMat[i][j] = INT_MAX;
			if(i == j)
				adjMat[i][j] = 0;
		}

	for( i = 0; i < e; i++) {
		printf("Enter the nodes(a, b): ");
		scanf("%d %d", &n1, &n2);
		printf("Enter value: ");
		scanf("%d", &adjMat[n1-1][n2-1]);
	}

	floyd( n, adjMat);
	printf("Shortest path matrix:\n");

	for( i = 0; i < n; i++) {
		for( j = 0; j < n; j++)
			printf("%3d ", adjMat[i][j]);
		printf("\n");
	}

	return 0;
}
