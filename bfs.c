#include <stdio.h>
#include <stdlib.h>

int v,  visited[12], Q[12], rear = -1, front = -1;

void createQueue( int x) {
	rear++;
	front++;
	Q[rear] = x;
}

void enqueue( int x) {
	if(front == -1)
		front++;
	rear++;
	Q[rear] = x;
}

int dequeue() {
	int x = Q[front];
	if(front == rear)
		front = rear = -1;
	else
		front++;
	return x;
}

int isEmptyQueue() {
	if(rear == -1)
		return 1;
	else
		return 0;
}

void bfs( int G[][v], int source) {
	createQueue( source);
	int x, i;
	while(!isEmptyQueue()) {
		x = dequeue();
		visited[x] = 1;
		printf("%d>", x + 1);
		for( i = 0; i < v; i++)
			if(!visited[i] && G[x][i] != 0) {
				enqueue( i);
			}
	}
}

int main() {
	printf("Enter the number of vertices: ");
	scanf("%d", &v);
	int adj_mat[v][v], i, j, source;
	for( i = 0; i < v; i++)
		for( j = 0; j < v; j++)
			scanf("%d", &adj_mat[i][j]);

	for( i = 0; i < v; i++)
		visited[i] = 0;

	printf("Enter source: ");
	scanf("%d", &source);
	printf("The bfs of the graph:\n");
	bfs( adj_mat, source-1);
	printf("end\n");
	return 0;
}
